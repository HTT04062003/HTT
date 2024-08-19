#ifndef __MYGPIO_H_
#define __MYGPIO_H_
/**/                
#include "mystartup.h"
/**/
#define My_GPIO_Pin_0 0
#define My_GPIO_Pin_1 1
#define My_GPIO_Pin_2 2
#define My_GPIO_Pin_3 3
#define My_GPIO_Pin_4 4
#define My_GPIO_Pin_5 5
#define My_GPIO_Pin_6 6
#define My_GPIO_Pin_7 7
#define My_GPIO_Pin_8 8
#define My_GPIO_Pin_9 9
#define My_GPIO_Pin_10 10
#define My_GPIO_Pin_11 11
#define My_GPIO_Pin_12 12
#define My_GPIO_Pin_13 13
#define My_GPIO_Pin_14 14
#define My_GPIO_Pin_15 15
/**/
#define My_GPIO_Speed_10MHz 0x1
#define My_GPIO_Speed_2MHz 0x2
#define My_GPIO_Speed_50MHz 0x3

/**/

/**/
typedef enum{
	GPIO_Mode_Output_Push_Pull = 0x1,
	GPIO_Mode_Open_Drain = 0x5,
	GPIO_Mode_AF_Push_Pull = 0xB,
	GPIO_Mode_AF_Open_Drain = 0xD,
	GPIO_Mode_Input_Floating = 0x4,
	GPIO_Mode_Input_Pull_Up = 0x8
}GPIO_Mode;
/**/
typedef struct{
	volatile uint32_t Mode;
	volatile uint32_t Speed;
	volatile uint32_t Pin;
	}My_GPIO_Parameter_Typedef;
/**/
void GPIO_Pin_Config(My_GPIO_Typedef* GPIOx, uint16_t GPIO_Pin, GPIO_Mode Mode, uint32_t GPIO_Speed);
void GPIO_Set_Pin( My_GPIO_Typedef* GPIOx, uint16_t GPIO_pin);
void GPIO_Reset_Pin( My_GPIO_Typedef* GPIOx, uint16_t GPIO_pin);
void GPIO_Write_Pin( My_GPIO_Typedef* GPIOx, uint16_t GPIO_pin, uint8_t New_State);
/**/
#endif