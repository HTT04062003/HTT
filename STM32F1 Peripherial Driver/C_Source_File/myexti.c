#include "myexti.h"
#include "stm32f10x.h"                  // Device header



void MY_EXTI_Line_config( uint16_t MY_EXTI_Line_Selection, uint16_t MY_EXTI_Port_Selection, uint16_t MY_EXTI_Edge){
	MY_RCC->APB2ENR |= 1<<0;
	/*AFIO_EXTICR1*/
	if(MY_EXTI_Line_Selection < MY_EXTI_Line_4 ){
		MY_AFIO->EXTICR1 &= (uint16_t)(~(0xF << MY_EXTI_Line_Selection*4));
		MY_AFIO->EXTICR1 |= (uint16_t)(MY_EXTI_Port_Selection<< (MY_EXTI_Line_Selection*4));
		}
	/*AFIO_EXTICR2*/
	if((MY_EXTI_Line_Selection > MY_EXTI_Line_3) && (MY_EXTI_Line_Selection < MY_EXTI_Line_8) ){
		MY_AFIO->EXTICR2 &= (uint16_t)(~(0xF << ((MY_EXTI_Line_Selection - 4)*4)));
		MY_AFIO->EXTICR2 |= (uint16_t)(MY_EXTI_Port_Selection<< ((MY_EXTI_Line_Selection - 4)*4));
		}
	/*AFIO_EXTICR3*/
	if((MY_EXTI_Line_Selection > MY_EXTI_Line_7) && (MY_EXTI_Line_Selection < MY_EXTI_Line_12) ){
		MY_AFIO->EXTICR3 &= (uint16_t)(~(0xF << ((MY_EXTI_Line_Selection - 8)*4)));
		MY_AFIO->EXTICR3 |= (uint16_t)(MY_EXTI_Port_Selection<< ((MY_EXTI_Line_Selection - 8)*4));
		}
	/*AFIO_EXTICR4*/
	if((MY_EXTI_Line_Selection > MY_EXTI_Line_11) && (MY_EXTI_Line_Selection <= MY_EXTI_Line_15) ){
		MY_AFIO->EXTICR4 &= (uint16_t)(~(0xF << ((MY_EXTI_Line_Selection - 12)*4)));
		MY_AFIO->EXTICR4 |= (uint16_t)(MY_EXTI_Port_Selection<< ((MY_EXTI_Line_Selection - 12)*4));
		}
	/*EXTI_IMR*/
		MY_EXTI->IMR &= (~(1 << MY_EXTI_Line_Selection));
		MY_EXTI->IMR |= 1 << MY_EXTI_Line_Selection;
	/*EXTI_RTSR*/
	if( MY_EXTI_Edge == MY_EXTI_Rising_Edge){
		MY_EXTI->RTSR &= (~(1 << MY_EXTI_Line_Selection));
		MY_EXTI->RTSR |= 1 << MY_EXTI_Line_Selection;
		}
	/*EXTI_FTSR*/
	if( MY_EXTI_Edge == MY_EXTI_Falling_Edge){
		MY_EXTI->FTSR &= (~(1 << MY_EXTI_Line_Selection));
		MY_EXTI->FTSR |= 1 << MY_EXTI_Line_Selection;
		}
	}
/**/
uint16_t  MY_EXTI_Get_It_Status( uint16_t MY_EXTI_Line){
		return (uint16_t)(MY_EXTI->PR&(1<<MY_EXTI_Line));
		}