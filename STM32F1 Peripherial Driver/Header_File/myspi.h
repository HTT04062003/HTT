#ifndef __MYSPI_H_
#define __MYSPI_H_
#include "mystartup.h"
/**/
typedef struct{
	volatile uint16_t CPHA;
	volatile uint16_t CPOL;
	volatile uint16_t Mode;
	volatile uint16_t Baudrate_Prescaler;
	volatile uint16_t NSS;
	volatile uint16_t Direction;
	volatile uint16_t Data_Size;
	volatile uint16_t FirstBit;
}My_SPI_Init_Parameter;
/*CPHA*/
#define CPHA_1Edge 0x0000
#define CPHA_2Edge 0x0001
/*CPOL*/
#define CPOL_Low 0x0000
#define CPOL_High 0x0002
/*Mode*/
#define Mode_Slave 0x0000
#define Mode_Master 0x0004
/*Baudrate_Prescaler*/
#define Baudrate_Prescaler_Div_2 0x0000
#define Baudrate_Prescaler_Div_4 0x0008
#define Baudrate_Prescaler_Div_8 0x0010
#define Baudrate_Prescaler_Div_16 0x0018
#define Baudrate_Prescaler_Div_32 0x0020
#define Baudrate_Prescaler_Div_64 0x0028
#define Baudrate_Prescaler_Div_128 0x0030
#define Baudrate_Prescaler_Div_256 0x0038
/*NSS*/
#define NSS_Soft 0x0300
#define NSS_Hardware 0x0000
/*Direction*/
#define Direction_2Line_Fullduplex 0x0000
#define Direction_2Line_Receiveonly 0x0400
#define Direction_1Line_Rx 0x8000
#define Direction_1Line_Tx 0xC000
/*Data_Size*/
#define Data_Size_8b 0x0000
#define Data_Size_16b 0x0800
/*FirstBit*/
#define FirstBit_MSB 0x0000
#define FirstBit_LSB 0x0080
/**/
#define CR1_SPE_Set          ((uint16_t)0x0040)
#define CR1_SPE_Reset        ((uint16_t)0xFFBF)
/*MY_SPI_SR*/
#define MY_SPI_SR_RXNE 0x0001
#define MY_SPI_SR_TXE 0x0002
#define MY_SPI_SR_BSY 0x0080
/*MY_SPI_CR2*/
#define MY_SPI_CR2_RXDMAEN 0x0001
#define MY_SPI_CR2_TXDMAEN 0x0002
#define MY_SPI_CR2_SSOE 0x0004
#define MY_SPI_CR2_ERRIE 0x0020
#define MY_SPI_CR2_RXNEIE 0x0040
#define MY_SPI_CR2_TXEIE 0x0080
/**/
void SPI_Config( My_SPI_Typedef* MY_SPIx, My_SPI_Init_Parameter* MY_SPI_Init_Parameter);
void SPI_ENABLE(My_SPI_Typedef* MY_SPIx, FunctionalState_Typedef Newstate);
uint16_t MY_SPI_Get_Flag_Status( My_SPI_Typedef* MY_SPIx, uint16_t MY_SPI_SR_Flag);
void MY_SPI_Interrupt_Config(My_SPI_Typedef* MY_SPIx, uint16_t MY_SPI_CR2_IT, FunctionalState_Typedef NewState);
void MY_SPI_Send_Byte( My_SPI_Typedef* MY_SPIx, uint8_t Data);
void MY_SPI_Send_Array(My_SPI_Typedef* MY_SPIx, uint8_t* Array);
/**/


#endif