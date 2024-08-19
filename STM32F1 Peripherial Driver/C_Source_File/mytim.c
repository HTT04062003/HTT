#include "mytim.h"


void My_TIM_Base_Init( My_TIM* TIMx, uint16_t PSC, uint16_t ARR){
	if(TIMx == MY_TIM4_BASE_ADDRESS) MY_RCC->APB1ENR |= 1<<2;
	if(TIMx == MY_TIM1_BASE_ADDRESS) MY_RCC->APB2ENR |= 1<<11;
	if(TIMx == MY_TIM2_BASE_ADDRESS) MY_RCC->APB1ENR |= 1<<0;
	if(TIMx == MY_TIM3_BASE_ADDRESS) MY_RCC->APB1ENR |= 1<<1;
	TIMx->PSC = PSC;
	TIMx->ARR = ARR;
	TIMx->EGR |= 1<<0;
	}
void My_TIM_Enable_Counter(My_TIM* MY_TIMx, FunctionalState_Typedef New_State){
	if(New_State == EN){
		MY_TIMx->CR1 |= 1<<0;
		}
	if(New_State == DIS){
		MY_TIMx->CR1 &= ~(1<<0);
		}
	}
/**/
void My_TIM_Counter_Mode(My_TIM* MY_TIM, uint16_t MY_TIM_Counter_mode){
	MY_TIM->CR1 &= ~0x0010;
	MY_TIM->CR1 |= MY_TIM_Counter_mode;
	}
/**/
void My_TIM_Select_Input_Trigger( My_TIM* MY_TIMx, uint16_t MY_TIM_Trigger_Selection){
	MY_TIMx->SMCR &= ~(0x0070);
	MY_TIMx->SMCR |= MY_TIM_Trigger_Selection;
	}
void My_TIM_Selection_Slave_Mode( My_TIM* MY_TIMx, uint16_t MY_TIM_Slave_Mode){
	MY_TIMx->SMCR &= ~(0x0007);
	MY_TIMx->SMCR |= MY_TIM_Slave_Mode;
}
void IC1_Selection( My_TIM* MY_TIMx, uint16_t IC1_Map, uint16_t IC1_Polarity){
	MY_TIMx->CCMR1 &= ~(0x0003);
	MY_TIMx->CCER&= ~(0x0002);
	MY_TIMx->CCMR1 |= IC1_Map;
	MY_TIMx->CCER|= IC1_Polarity;
}
void IC2_Selection( My_TIM* MY_TIMx, uint16_t IC2_Map, uint16_t IC2_Polarity){
	MY_TIMx->CCMR1 &= ~(0x0300);
	MY_TIMx->CCER&= ~(0x0020);
	MY_TIMx->CCMR1 |= IC2_Map;
	MY_TIMx->CCER|= IC2_Polarity;
}
void IC3_Selection( My_TIM* MY_TIMx, uint16_t IC3_Map, uint16_t IC3_Polarity){
	MY_TIMx->CCMR2 &= ~(0x0003);
	MY_TIMx->CCER&= ~(0x0200);
	MY_TIMx->CCMR2 |= IC3_Map;
	MY_TIMx->CCER|= IC3_Polarity;
}
void IC4_Selection( My_TIM* MY_TIMx, uint16_t IC4_Map, uint16_t IC4_Polarity){
	MY_TIMx->CCMR2 &= ~(0x0300);
	MY_TIMx->CCER&= ~(0x2000);
	MY_TIMx->CCMR2 |= IC4_Map;
	MY_TIMx->CCER|= IC4_Polarity;
}
void OC1_Init(My_TIM* MY_TIMx, uint16_t OC1_Mode, uint16_t OC1_Polarity){
	MY_TIMx->CCMR1 &= ~0x0070;
	MY_TIMx->CCER &= ~0x0002;
	MY_TIMx->CCMR1 |= OC1_Mode;
	MY_TIMx->CCER |= OC1_Polarity;
}
void OC2_Init(My_TIM* MY_TIMx, uint16_t OC2_Mode, uint16_t OC2_Polarity){
	MY_TIMx->CCMR1 &= ~0x7000;
	MY_TIMx->CCER &= ~0x0020;
	MY_TIMx->CCMR1 |= OC2_Mode;
	MY_TIMx->CCER |= OC2_Polarity;
}
void OC4_Init(My_TIM* MY_TIMx, uint16_t OC4_Mode, uint16_t OC4_Polarity){
	MY_TIMx->CCMR2 &= ~0x7000;
	MY_TIMx->CCER &= ~0x2000;
	MY_TIMx->CCMR2 |= OC4_Mode;
	MY_TIMx->CCER |= OC4_Polarity;
}
void OC3_Init(My_TIM* MY_TIMx, uint16_t OC3_Mode, uint16_t OC3_Polarity){
	MY_TIMx->CCMR2 &= ~0x0070;
	MY_TIMx->CCER &= ~0x0002;
	MY_TIMx->CCMR2 |= OC3_Mode;
	MY_TIMx->CCER |= OC3_Polarity;
}

void Capture_Compare_1_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState){
	if(NewState == EN) MY_TIMx->CCER |= 1<<0;
	if(NewState == DIS) MY_TIMx->CCER &= ~(1<<0);
}
void Capture_Compare_2_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState){
	if(NewState == EN) MY_TIMx->CCER |= 1<<4;
	if(NewState == DIS) MY_TIMx->CCER &= ~(1<<4);
}
void Capture_Compare_3_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState){
	if(NewState == EN) MY_TIMx->CCER |= 1<<8;
	if(NewState == DIS) MY_TIMx->CCER &= ~(1<<8);
}
void Capture_Compare_4_Enable( My_TIM* MY_TIMx, FunctionalState_Typedef NewState){
	if(NewState == EN) MY_TIMx->CCER |= 1<<12;
	if(NewState == DIS) MY_TIMx->CCER &= ~(1<<12);
}
uint16_t My_TIM_Get_Capture_1( My_TIM* MY_TIMx){
	return MY_TIMx->CCR1;
}
uint16_t My_TIM_Get_Capture_2( My_TIM* MY_TIMx){
	return MY_TIMx->CCR2;
}
uint16_t My_TIM_Get_Capture_3( My_TIM* MY_TIMx){
	return MY_TIMx->CCR3;
}
uint16_t My_TIM_Get_Capture_4( My_TIM* MY_TIMx){
	return MY_TIMx->CCR4;
}
void MY_TIM_Set_Compare_1( My_TIM* MY_TIMx, uint16_t Compare_Value){
	MY_TIMx->CCR1 = Compare_Value;
}
void MY_TIM_Set_Compare_2( My_TIM* MY_TIMx, uint16_t Compare_Value){
	MY_TIMx->CCR2 = Compare_Value;
}
void MY_TIM_Set_Compare_3( My_TIM* MY_TIMx, uint16_t Compare_Value){
	MY_TIMx->CCR3 = Compare_Value;
}
void MY_TIM_Set_Compare_4( My_TIM* MY_TIMx, uint16_t Compare_Value){
	MY_TIMx->CCR4 = Compare_Value;
}
/**/
void MY_TIM_Interrupt_Enable( My_TIM* MY_TIMx, uint16_t MY_TIM_Interrupt, FunctionalState_Typedef Newstate){
	
  if(Newstate == DIS){
		MY_TIMx->DIER &= ~MY_TIM_Interrupt;
		}
	if(Newstate == EN){
		MY_TIMx->DIER |= MY_TIM_Interrupt;
		}
}
uint16_t MY_TIM_Get_Flag_Status( My_TIM* MY_TIMx, uint16_t MY_TIM_Flag){
  return MY_TIMx->SR&MY_TIM_Flag; 
}	