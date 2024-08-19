#include "myspi.h"

/**/

/**/
void SPI_Config( My_SPI_Typedef* MY_SPIx, My_SPI_Init_Parameter* MY_SPI_Init_Parameter){
	/**/
	MY_SPIx->CR1 &= (~0xCFBF);
	/*CPHA*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->CPHA;
	/*CPOL*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->CPOL;
	/*Mode*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->Mode;
	/*BR*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->Baudrate_Prescaler;
	/*LSBFIRST*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->FirstBit;
	/*SSM*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->NSS;
	/*Dir*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->Direction;
	/*Data_Size*/
	MY_SPIx->CR1 |= MY_SPI_Init_Parameter->Data_Size;
}
/**/
void SPI_ENABLE(My_SPI_Typedef* MY_SPIx, FunctionalState_Typedef Newstate){
	if(Newstate == EN) MY_SPIx->CR1 |= CR1_SPE_Set;
	if(Newstate == DIS) MY_SPIx->CR1 &= CR1_SPE_Reset;
	}
/**/
uint16_t MY_SPI_Get_Flag_Status( My_SPI_Typedef* MY_SPIx, uint16_t MY_SPI_SR_Flag){
	return (MY_SPIx->SR&MY_SPI_SR_Flag);
	}
void MY_SPI_Interrupt_Config(My_SPI_Typedef* MY_SPIx, uint16_t MY_SPI_CR2_IT, FunctionalState_Typedef NewState){
	if(NewState == EN) MY_SPIx->CR2 |= MY_SPI_CR2_IT;
	if(NewState == DIS) MY_SPIx->CR2 &= (~MY_SPI_CR2_IT);
	}
/**/
void MY_SPI_Send_Byte( My_SPI_Typedef* MY_SPIx, uint8_t Data){
	while((MY_SPIx->SR & MY_SPI_SR_BSY) == MY_SPI_SR_BSY);
	MY_SPIx->DR = (uint8_t) Data;
	}
/**/
void MY_SPI_Send_Array(My_SPI_Typedef* MY_SPIx, uint8_t* Array){
	while(*Array){
		MY_SPI_Send_Byte(MY_SPIx, *Array);
		Array++;
		}
	}
