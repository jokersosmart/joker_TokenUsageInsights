import { spawn } from 'node:child_process';
import { writeFileSync } from 'node:fs';

const BIN = '/workspace/target/release/joker-token-usage-insights';
const OUT = '/tmp/reverse-analysis/mcp';
const p = spawn(process.env.RE_CLI, ['--mcp'], { stdio: ['pipe', 'pipe', 'inherit'], env: process.env });
let buf = '';
const pending = new Map();
let id = 0;
p.stdout.on('data', (d) => {
  buf += d;
  let i;
  while ((i = buf.indexOf('\n')) >= 0) {
    const line = buf.slice(0, i);
    buf = buf.slice(i + 1);
    if (!line.trim()) continue;
    const m = JSON.parse(line);
    if (m.id && pending.has(m.id)) {
      pending.get(m.id)(m);
      pending.delete(m.id);
    }
  }
});
const req = (method, params) =>
  new Promise((r) => {
    const i = ++id;
    pending.set(i, r);
    p.stdin.write(JSON.stringify({ jsonrpc: '2.0', id: i, method, params }) + '\n');
  });
const call = async (label, name, args) => {
  const t0 = Date.now();
  const m = await req('tools/call', { name, arguments: args });
  const ms = Date.now() - t0;
  writeFileSync(`${OUT}/${label}.json`, JSON.stringify({ tool: name, arguments: args, elapsed_ms: ms, response: m }, null, 2));
  console.log(`${label} ${name} ${ms}ms isError=${m.result?.isError ?? !!m.error}`);
  return m;
};
const findAddr = (m, needle) => {
  const text = JSON.stringify(m);
  const re = new RegExp(`"name":"([^"]*${needle}[^"]*)","address":"(0x[0-9a-f]+)"|"address":"(0x[0-9a-f]+)","name":"([^"]*${needle}[^"]*)"`);
  const hit = text.match(re);
  if (!hit) return null;
  return hit[2] ?? hit[3];
};

await req('initialize', { protocolVersion: '2025-06-18', capabilities: {}, clientInfo: { name: 'reverse-analysis-report', version: '1' } });
p.stdin.write(JSON.stringify({ jsonrpc: '2.0', method: 'notifications/initialized' }) + '\n');

await call('01-open', 'open_binary', { path: BIN, provider_id: 'ghidra' });
await call('02-overview', 'binary_overview', {});
const cc = await call('03-search-calculate-cost', 'search_procedures', { pattern: 'calculate_cost' });
await call('04-search-sync', 'search_procedures', { pattern: 'sync_usage_logs' });
await call('05-strings-api', 'search_strings', { pattern: '/api/' });
await call('06-strings-pricing', 'search_strings', { pattern: 'pricing.csv' });
await call('07-strings-create-table', 'search_strings', { pattern: 'CREATE TABLE IF NOT EXISTS' });
await call('08-strings-272k', 'search_strings', { pattern: '272k' });
const addr = findAddr(cc, 'calculate_cost');
console.log('calculate_cost address', addr);
if (addr) {
  await call('09-pseudo-calculate-cost', 'procedure_pseudo_code', { procedure: addr });
  await call('10-callers-calculate-cost', 'procedure_callers', { procedure: addr });
}
await call('11-close', 'close_binary', {});
p.kill();
