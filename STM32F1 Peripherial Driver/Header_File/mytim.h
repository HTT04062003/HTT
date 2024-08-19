#ifndef __MYTIM_H_
#define __MYTIM_H_
#include "mystartup.h"                
/**/
/**/
#define MY_TIM_Counter_Mode_Down 0x0010
#define MY_TIM_Counter_Mode_Up 0x0000
/**/
/*IC1_Selcttion*/
#define IC1_Map_On_TI1 0x0001
#define IC1_Map_On_TI2 0x0002
#define IC1_Map_On_TRC 0x0003
/*IC2_Selection*/
#define IC2_Map_On_TI2 0x0100
#define IC2_Map_On_TI1 0x0200
#define IC2_Map_On_TRC 0x0300
/*IC3_Selection*/
#define IC3_Map_On_TI3 0x0001
#define IC3_Map_On_TI4 0x0002
#define IC3_Map_On_TRC 0x0003
/*IC4_Selection*/
#define IC4_Map_On_TI4 0x0100
#define IC4_Map_On_TI3 0x0200
#define IC4_Map_On_TRC 0x0300
/*IC_Polarrity*/
#define IC1_Rising_Edge 0x0000
#define IC1_Falling_Edge 0x0002
#define IC2_Rising_Edge 0x0000
#define IC2_Falling_Edge 0x0020
#define IC3_Rising_Edge 0x0000
#define IC3_Falling_Edge 0x0200
#define IC4_Rising_Edge 0x0000
#define IC4_Falling_Edge 0x2000
/*OC1_Mode*/
#define OC1_Mode_PWM_1 0x0060
#define OC1_Mode_PWM_2 0x0070
/*OC2_Mode*/
#define OC2_Mode_PWM_1 0x6000
#define OC2_Mode_PWM_2 0x6000
/*OC3_Mode*/
#define OC3_Mode_PWM_1 0x0060
#define OC3_Mode_PWM_2 0x0070
/*OC4_Mode*/
#define OC4_Mode_PWM_1 0x6000
#define OC4_Mode_PWM_2 0x6000
/*OC1_Polarity*/
#define OC1_Active_high 0x0000
#define OC1_Active_low 0x0002
/*OC2_Polarity*/
#define OC2_Active_high 0x0000
#define OC2_Active_low 0x0020
/*OC3_Polarity*/
#define OC3_Active_high 0x0000
#define OC3_Active_low 0x0200
/*OC4_Polarity*/
#define OC4_Active_high 0x0000
#define OC4_Active_low 0x2000
/*Slave_Mode_Selection*/
#define MY_TIM_Slave_MOde_Encoder_1 0x0001
#define MY_TIM_Slave_MOde_Encoder_2 0x0002
#define MY_TIM_Slave_MOde_Encoder_3 0x0003
#define MY_TIM_Slave_MOde_Reset_Mode 0x0004
#define MY_TIM_Slave_MOde_Gated_Mode 0x0005
#define MY_TIM_Slave_MOde_Trigger Mode 0x0006
#define MY_TIM_Slave_MOde_External_Clock_Mode_1  0x0007
/*Triger_Selection*/
#define MY_TIM_Trigger_Internal_0 0x0000
#define MY_TIM_Trigger_Internal_1 0x0010
#define MY_TIM_Trigger_Internal_2 0x0020
#define MY_TIM_Trigger_Internal_3 0x0030
#define MY_TIM_Trigger_TI1_Edge_Detector 0x0040
#define MY_TIM_Trigger_TI1FP1 0x0050
#define MY_TIM_Trigger_TI2FP2 0x0060
#define MY_TIM_Trigger_ETRF 0x0070
/*Interrupt_Enable*/
#define MY_TIM_UIE 0x0001
#define MY_TIM_CC1IE 0x0002
#define MY_TIM_CC2IE 0x0004
#define MY_TIM_CC3IE 0x0008
#define MY_TIM_CC4IE 0x0010
#define MY_TIM_TIE 0x0040
/*MY_TIM_DMA*/
#define MY_TIM_UDE 0x0100
#define MY_TIM_CC1DE 0x0200
#define MY_TIM_CC2DE 0x0500
#define MY_TIM_CC3DE 0x0800
#define MY_TIM_CC4DE 0x1000
#define MY_TIM_TDE 0x4000
/*MY_TIM_Flag_Status*/
#define MY_TIM_UIF 0x0001
#define MY_TIM_CC1F 0x0002
#define MY_TIM_CC2F 0x0004
#define MY_TIM_CC3F 0x0008
#define MY_TIM_CC4F 0x0010
#define MY_TIM_TIF 0x0040
#define MY_TIM_CC1OF 0x0200
#define MY_TIM_CC2OF 0x0400
#define MY_TIM_CC3OF 0x0800
#define MY_TIM_CC4OF 0x1000

/**/
void My_TIM_Base_Init( My_TIM* TIMx, uint16_t PSC, uint16_t ARR);
void My_TIM_Enable_Counter(My_TIM* MY_TIMx, FunctionalState_Typedef New_State);
void My_TIM_Counter_Mode(My_TIM* MY_TIMx, uint16_t MY_TIM_Counter_mode);

void My_TIM_Select_Input_Trigger( My_TIM* MY_TIMx, uint16_t MY_TIM_Trigger_Selection);
void My_TIM_Selection_Slave_Mode( My_TIM* MY_TIMx, uint16_t MY_TIM_Slave_Mode);

void IC1_Selection( My_TIM* MY_TIMx, uint16_t IC1_Map, uint16_t IC1_Polarity);
void IC2_Selection( My_TIM* MY_TIMx, uint16_t IC2_Map, uint16_t IC2_Polarity);
void IC3_Selection( My_TIM* MY_TIMx, uint16_t IC3_Map, uint16_t IC3_Polarity);
void IC4_Selection( My_TIM* MY_TIMx, uint16_t IC4_Map, uint16_t IC4_Polarity);

void OC1_Init(My_TIM* MY_TIMx, uint16_t OC1_Mode, uint16_t OC1_Polarity);
void OC2_Init(My_TIM* MY_TIMx, uint16_t OC2_Mode, uint16_t OC2_Polarity);
void OC4_Init(My_TIM* MY_TIMx, uint16_t OC4_Mode, uint16_t OC4_Polarity);
void OC3_Init(My_TIM* MY_TIMx, uint16_t OC3_Mode, uint16_t OC3_Polarity);

void Capture_Compare_1_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState);
void Capture_Compare_2_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState);
void Capture_Compare_3_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState);
void Capture_Compare_4_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState);

uint16_t My_TIM_Get_Capture_1( My_TIM* MY_TIMx);
uint16_t My_TIM_Get_Capture_2( My_TIM* MY_TIMx);
uint16_t My_TIM_Get_Capture_3( My_TIM* MY_TIMx);
uint16_t My_TIM_Get_Capture_4( My_TIM* MY_TIMx);

void MY_TIM_Set_Compare_1( My_TIM* MY_TIMx, uint16_t Compare_Value);
void MY_TIM_Set_Compare_2( My_TIM* MY_TIMx, uint16_t Compare_Value);
void MY_TIM_Set_Compare_3( My_TIM* MY_TIMx, uint16_t Compare_Value);
void MY_TIM_Set_Compare_4( My_TIM* MY_TIMx, uint16_t Compare_Value);

void MY_TIM_Interrupt_Enable( My_TIM* MY_TIMx, uint16_t MY_TIM_Interrupt, FunctionalState_Typedef Newstate);
uint16_t MY_TIM_Get_Flag_Status( My_TIM* MY_TIMx, uint16_t MY_TIM_Flag);
/**/

/**/
#endif