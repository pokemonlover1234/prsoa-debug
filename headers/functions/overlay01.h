#ifndef HEADERS_FUNCTIONS_OVERLAY01_H_
#define HEADERS_FUNCTIONS_OVERLAY01_H_
undefined4 BattleStateManager(struct battle_struct* param_1, undefined4 param_2, int param_3,
                              int* param_4);
undefined4 BattleBannerGraphicFrameUpdate(struct battle_struct* param_1);
undefined4 BattleActiveFrameUpdate(struct battle_struct* param_1, undefined4 param_2,
                                   undefined4 param_3, undefined4 param_4);
undefined4 BattleVerifyFleeFrameUpdate(struct battle_struct* param_1);
undefined4 BattleViewPartyFrameUpdate(struct battle_struct* param_1);
undefined4 BattleHandleWinFrameUpdate(struct battle_struct* param_1);
undefined4 BattleHandleLossFrameUpdate(struct battle_struct* param_1, undefined4 param_2,
                                       int param_3, int* param_4);
undefined4 EndBattleFrameUpdate(struct battle_struct* param_1);
undefined4 RegisterInBrowserFrameUpdate(struct battle_struct* param_1, undefined4 param_2,
                                        undefined4 param_3, undefined4 param_4);
undefined4 FightVictoryCheerFrameUpdate(struct battle_struct* param_1);
void FreeBattlePokemonSlot(struct battle_struct* param_1, int param_2);
void UpdateBrowserLifetimeCaughtAndMore(struct battle_struct* param_1, undefined4 param_2,
                                        undefined4 param_3, undefined4 param_4);
void ret_02123770(void);
void ret_021293D4(void);
void ret_0212C028(void);
void ret_0212E524(void);
void ret_0212E888(void);
void ret_0212EE20(void);
void ret_0212EE38(void);
void ret_02130B70(void);
void ret_02131B44(void);
void ret_02133C04(void);
void ret_02134350(void);
void ret_02136244(void);
void ret_021368F8(void);
void ret_02136AE8(void);
void ret_02137B90(void);
void ret_02137B94(void);
void ret_0213AE14(void);
#endif
