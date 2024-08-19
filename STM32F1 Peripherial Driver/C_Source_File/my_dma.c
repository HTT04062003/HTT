#include "my_dma.h"

void MY_DMA_Config(My_DMA_Channelx_Typedef* MY_DMA_Channelx, My_DMA_Parameter_Typedef* Parameter){
	MY_DMA_Channelx->CCR &= (uint16_t)(~0xFFF0);
	MY_DMA_Channelx->CCR |= Parameter->Channel_Priority;
	MY_DMA_Channelx->CCR |=  Parameter->Circular_Mode;
	MY_DMA_Channelx->CCR |= Parameter->Direction;
	MY_DMA_Channelx->CCR |= Parameter->mem2mem;
	MY_DMA_Channelx->CCR |= Parameter->Memory_Increment_Mode;
	MY_DMA_Channelx->CCR |= Parameter->M_Size;
	MY_DMA_Channelx->CCR |= Parameter->Peripheral_Increment_Mode;
	MY_DMA_Channelx->CCR |= Parameter->P_Size;
	}
