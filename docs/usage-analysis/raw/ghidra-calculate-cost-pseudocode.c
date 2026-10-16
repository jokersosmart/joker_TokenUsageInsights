
/* joker_token_usage_insights::pricing::calculate_cost */

undefined8 * __rustcall
joker_token_usage_insights::pricing::calculate_cost
          (undefined8 *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
          long param_6,long param_7,long param_8)

{
  undefined8 *puVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined1 *__s2;
  undefined1 *puVar4;
  undefined8 **__n;
  undefined8 **ppuVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  undefined **local_d0;
  undefined1 *local_c8;
  undefined8 **local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 *local_a0;
  long local_98;
  ulong local_90;
  undefined8 *local_88;
  code *local_80;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined8 local_38;
  
  local_98 = param_6;
  local_70 = param_4;
  local_68 = param_5;
  parse_threshold_rule(&local_d0,param_4,param_5);
  __n = local_c0;
  __s2 = local_c8;
  ppuVar2 = local_d0;
  if (local_c0 == (undefined8 **)0x0) {
    local_88 = &local_70;
    local_80 = <&T_as_core::fmt::Display>::fmt;
    local_d0 = &PTR_DAT_005a8798;
    local_c8 = &DAT_00000001;
    local_b0 = 0;
    local_c0 = &local_88;
    local_b8 = 1;
    alloc::fmt::format::format_inner(&local_60,&local_d0);
    param_1[2] = local_50;
    *(undefined4 *)param_1 = local_60;
    *(undefined4 *)((long)param_1 + 4) = uStack_5c;
    *(undefined4 *)(param_1 + 1) = uStack_58;
    *(undefined4 *)((long)param_1 + 0xc) = uStack_54;
    puVar1 = param_1;
  }
  else {
    local_a0 = param_1;
    if (param_3 != 0) {
      local_90 = param_7 + local_98 + param_8;
      local_78 = param_3 * 0x10;
      param_3 = param_3 * 0x30;
      lVar10 = param_2;
      do {
        parse_threshold_rule(&local_d0,*(undefined8 *)(lVar10 + 8),*(undefined8 *)(lVar10 + 0x10));
        puVar4 = local_c8;
        ppuVar3 = local_d0;
        if ((local_c0 == (undefined8 **)0x0) || (local_c0 != __n)) {
LAB_0020ad27:
          if (ppuVar3 != (undefined **)0x0) {
            __rust_dealloc(puVar4,ppuVar3,1);
          }
        }
        else {
          bVar6 = (byte)local_b8;
          iVar8 = bcmp(local_c8,__s2,(size_t)__n);
          if (iVar8 != 0) goto LAB_0020ad27;
          if (ppuVar3 != (undefined **)0x0) {
            __rust_dealloc(puVar4,ppuVar3,1);
          }
          if ((bVar6 == 2) || (((0x42680 < local_90 ^ bVar6) & 1) == 0)) goto LAB_0020af8a;
        }
        lVar10 = lVar10 + 0x30;
        param_3 = param_3 + -0x30;
      } while (param_3 != 0);
      lVar9 = local_78 * 3;
      do {
        parse_threshold_rule(&local_d0,*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10))
        ;
        ppuVar5 = local_c0;
        puVar4 = local_c8;
        ppuVar3 = local_d0;
        if (local_c0 == (undefined8 **)0x0) {
LAB_0020aec0:
          if (ppuVar3 != (undefined **)0x0) {
            __rust_dealloc(puVar4,ppuVar3,1);
          }
        }
        else {
          bVar6 = (byte)local_b8;
          cVar7 = <&str_as_core::str::pattern::Pattern>::is_contained_in(local_c8,local_c0,__s2,__n)
          ;
          if ((cVar7 == '\0') &&
             (cVar7 = <&str_as_core::str::pattern::Pattern>::is_contained_in
                                (__s2,__n,puVar4,ppuVar5), cVar7 == '\0')) goto LAB_0020aec0;
          if (ppuVar3 != (undefined **)0x0) {
            __rust_dealloc(puVar4,ppuVar3,1);
          }
          lVar10 = param_2;
          if ((bVar6 == 2) || (((0x42680 < local_90 ^ bVar6) & 1) == 0)) goto LAB_0020af8a;
        }
        param_2 = param_2 + 0x30;
        lVar9 = lVar9 + -0x30;
      } while (lVar9 != 0);
    }
    local_88 = &local_70;
    local_80 = <&T_as_core::fmt::Display>::fmt;
    local_d0 = &PTR_DAT_005a87a8;
    local_c8 = &DAT_00000001;
    local_b0 = 0;
    local_c0 = &local_88;
    local_b8 = 1;
    alloc::fmt::format::format_inner(&local_48,&local_d0);
    local_a0[2] = local_38;
    *(undefined4 *)local_a0 = local_48;
    *(undefined4 *)((long)local_a0 + 4) = uStack_44;
    *(undefined4 *)(local_a0 + 1) = uStack_40;
    *(undefined4 *)((long)local_a0 + 0xc) = uStack_3c;
    puVar1 = local_a0;
  }
joined_r0x0020adf0:
  if (ppuVar2 != (undefined **)0x0) {
    __rust_dealloc(__s2,ppuVar2,1);
  }
  return puVar1;
LAB_0020af8a:
  local_a0[1] = ((((double)CONCAT44(0x45300000,(int)((ulong)param_7 >> 0x20)) -
                  1.9342813113834067e+25) +
                 ((double)CONCAT44(0x43300000,(int)param_7) - 4503599627370496.0)) / 1000000.0) *
                *(double *)(lVar10 + 0x28) +
                ((((double)CONCAT44(0x45300000,(int)((ulong)param_8 >> 0x20)) -
                  1.9342813113834067e+25) +
                 ((double)CONCAT44(0x43300000,(int)param_8) - 4503599627370496.0)) / 1000000.0) *
                *(double *)(lVar10 + 0x20) +
                ((((double)CONCAT44(0x45300000,(int)((ulong)local_98 >> 0x20)) -
                  1.9342813113834067e+25) +
                 ((double)CONCAT44(0x43300000,(int)local_98) - 4503599627370496.0)) / 1000000.0) *
                *(double *)(lVar10 + 0x18);
  *local_a0 = 0x8000000000000000;
  puVar1 = local_a0;
  goto joined_r0x0020adf0;
}


