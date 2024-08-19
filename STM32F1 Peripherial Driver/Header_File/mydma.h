#ifndef __MYDMA_H_
#define __MYDMA_H_
#include <stdint.h>
#include "stm32f10x.h"                 
#include "mystartup.h"
/**/

/*MY_DMA_Channelx_Parameter*/
typedef struct{
	volatile uint16_t memory2memory_mode;
	volatile uint16_t Channel_Priority;
	volatile uint16_t M_size;
	volatile uint16_t P_size;
	volatile uint16_t Memory_Increment_Mode;
	volatile uint16_t Peripheral_Increment_Mode;
	volatile uint16_t Circular_Mode;
	volatile uint16_t Data_Tranfer_Direction;
	}My_DMA_Channelx_Config_Parameter;

/**/

/**/
#define memory2memory_mode_Disable 0x0000
#define memory2memory_mode_Enable 0x0001
/**/
#define Channel_Priority_Low 0x0000
#define Channel_Priority_Medium 0x1000
#define Channel_Priority_High 0x2000
#define Channel_Priority_Very_High 0x3000
/**/
#define M_size_8b 0x0000
#define M_size_16b 0x0400
#define M_size_32b 0x0800
/**/
#define P_size_8b 0x0000
#define P_size_16b 0x0100
#define P_size_32b 0x0200
/**/
#define Memory_Increment_Mode_Disable 0x0000
#define Memory_Increment_Mode_Enable 0x0001
/**/
#define Peripheral_Increment_Mode_Disable 0x0000
#define Peripheral_Increment_Mode_Enable 0x0001
/**/
#define Circular_Mode_Disable 0x0000
#define Circular_Mode_Enable 0x0001
/**/
#define Data_Tranfer_Direction_From_Memory 0x0010
#define Data_Tranfer_Direction_From_Peripheral 0x0000

/**/
void MY_DMA_Channelx_Config( My_DMA_Channelx_Typedef* MY_DMA_Channelx, My_DMA_Channelx_Config_Parameter* MY_DMA_Struct_Parameter);
void MY_DMA_Channelx_Number_Data_Tranfer( My_DMA_Channelx_Typedef* MY_DMA_Channelx,uint16_t MY_DMA_Number_Data);
void MY_DMA_Channelx_Peripheral_Address( My_DMA_Channelx_Typedef* My_DMA_Channelx, uint32_t u32Address);
void MY_DMA_Channelx_Memory_Address( My_DMA_Channelx_Typedef* My_DMA_Channelx, uint32_t u32Address);
void MY_DMA_Channelx_Enable(My_DMA_Channelx_Typedef* MY_DMA_Channelx, FunctionalState New_State);
#endif