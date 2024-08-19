#include "mydma.h"
#include "stm32f10x.h"                  

/**/
void MY_DMA_Channelx_Config( My_DMA_Channelx_Typedef* MY_DMA_Channelx, My_DMA_Channelx_Config_Parameter* MY_DMA_Struct_Parameter){
	/**/
	MY_RCC->AHBENR |= 1<<0;
	/**/
	MY_DMA_Channelx->CCR &= (uint16_t)(~0xFFF0);
	/*MEM2MEM*/
	if(MY_DMA_Struct_Parameter->memory2memory_mode ==  memory2memory_mode_Disable) MY_DMA_Channelx->CCR &= (uint16_t)(~(1<<14));
	if(MY_DMA_Struct_Parameter->memory2memory_mode ==  memory2memory_mode_Enable) MY_DMA_Channelx->CCR |= (uint16_t)((1<<14));
	/*PL*/
	MY_DMA_Channelx->CCR |= MY_DMA_Struct_Parameter->Channel_Priority;
	/*MSIZE*/
	MY_DMA_Channelx->CCR |= MY_DMA_Struct_Parameter->M_size;
	/*PSIZE*/
	MY_DMA_Channelx->CCR |= MY_DMA_Struct_Parameter->P_size;
	/*MINC*/
	if(MY_DMA_Struct_Parameter->Memory_Increment_Mode == Memory_Increment_Mode_Disable) MY_DMA_Channelx->CCR &= (uint16_t)(~(1<<7));
	if(MY_DMA_Struct_Parameter->Memory_Increment_Mode == Memory_Increment_Mode_Enable) MY_DMA_Channelx->CCR |= (uint16_t)((1<<7));
	/*PNIC*/
	if(MY_DMA_Struct_Parameter->Peripheral_Increment_Mode == Peripheral_Increment_Mode_Disable) MY_DMA_Channelx->CCR &= (uint16_t)(~(1<<6));
	if(MY_DMA_Struct_Parameter->Peripheral_Increment_Mode == Peripheral_Increment_Mode_Enable) MY_DMA_Channelx->CCR |= (uint16_t)((1<<6));
	/*CIRC*/
	if(MY_DMA_Struct_Parameter->Circular_Mode == Circular_Mode_Disable) MY_DMA_Channelx->CCR &= (uint16_t)(~(1<<5));
	if(MY_DMA_Struct_Parameter->Circular_Mode == Circular_Mode_Enable) MY_DMA_Channelx->CCR |= (uint16_t)((1<<5));
	/*DIR*/
	MY_DMA_Channelx->CCR |= MY_DMA_Struct_Parameter->Data_Tranfer_Direction;
	}
/**/
void MY_DMA_Channelx_Number_Data_Tranfer( My_DMA_Channelx_Typedef* MY_DMA_Channelx,uint16_t MY_DMA_Number_Data){
	MY_DMA_Channelx->CNDTR = MY_DMA_Number_Data;
	}
/**/
void MY_DMA_Channelx_Peripheral_Address( My_DMA_Channelx_Typedef* My_DMA_Channelx, uint32_t u32Address){
	My_DMA_Channelx->CPAR = u32Address;
	}
/**/
void MY_DMA_Channelx_Memory_Address( My_DMA_Channelx_Typedef* My_DMA_Channelx, uint32_t u32Address){
	My_DMA_Channelx->CMAR = u32Address;
	}
/**/
void MY_DMA_Channelx_Enable(My_DMA_Channelx_Typedef* MY_DMA_Channelx, FunctionalState New_State){
	if(New_State == ENABLE) MY_DMA_Channelx->CCR |= 1<<0;
	if(New_State == DISABLE) MY_DMA_Channelx->CCR &= (uint16_t)(~(1<<0));
	}

/**/
