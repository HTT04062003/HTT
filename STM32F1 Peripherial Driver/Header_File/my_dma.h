#ifndef __MY_DMA_H_
#define __MY_DMA_H_
#include "mystartup.h"
typedef struct{
	volatile uint32_t mem2mem;
	volatile uint32_t Channel_Priority;
	volatile uint32_t M_Size;
	volatile uint32_t P_Size;
	volatile uint32_t Memory_Increment_Mode;
	volatile uint32_t Peripheral_Increment_Mode;
	volatile uint32_t Circular_Mode;
	volatile uint32_t Direction;
	}My_DMA_Parameter_Typedef;
/**/
#define mem2mem_Mode_Disable 0x0000
#define mem2mem_Mode_Enable 0x4000
/*MY_DMA_Channel_Priority*/
#define hannel_Priority_Low 0x0000
#define Channel_Priority_Medium 0x1000
#define Channel_Priority_High 0x2000
#define Channel_Priority_Very_High 0x3000
/*MY_DMA_Memory_Size*/
#define MSIZE_8b 0x0000
#define MSIZe_16b 0x0400
#define MSIZE_32b 0x0800
/*MY_DMA_PSIZE*/
#define PSIZE_8b 0x0000
#define PSIZE_16b 0x0100
#define PSIZE_32b 0x0200
/*Memory_Increment_Mode*/
#define Memory_Increment_Mode_Disable 0x0000
#define Memory_Increment_Mode_Enable 0x0080
/*Peripheral_Increment_Mode*/
#define Peripheral_Increment_Mode_Disable 0x0000
#define Peripheral_Increment_Mode_Enable 0x0040
/*Circular_Mode*/
#define Circular_Mode_Disable 0x0000
#define Circular_Mode_Enable 0x0020
/*Direction*/
#define Direction_From_Peripheral 0x0000
#define Direction_From_Memory 0x0010
/*Prototype*/
void MY_DMA_Config(My_DMA_Channelx_Typedef* MY_DMA_Channelx, My_DMA_Parameter_Typedef* Parameter);
#endif