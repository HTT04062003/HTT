#ifndef __MYUART_H_
#define __MYUART_H_
#include "mystartup.h"
#include <stdint.h>
/**/
#define PCLK1 36000000
#define PCLK2 72000000
/**/
/*UART_CR1_Interrupt*/
#define UART_IDLEIE 0x00000010
#define UART_RXNEIE 0x00000020
#define UART_TCIE   0x00000040
#define UART_TXEIE  0x00000080
#define UART_PEIE   0x00000100

/*UART_SR_Flag*/
#define UART_CTS 0x00000200
#define UART_LBD 0x00000100
#define UART_TXE 0x00000080
#define UART_TC  0x00000040
#define UART_RXNE 0x00000020
#define UART_IDLE 0x00000010
#define UART_ORE 0x00000008
#define UART_NE 0x00000004
#define UART_FE 0x00000002
#define UART_PE 0x00000001
/*Data_Len*/
#define Data_Len_8b 0x0000
#define Data_Len_9b 0x1000
/*Parity_Control*/
#define Parity_Control_Enable 0x00000001
#define Parity_Control_Disable 0x00000000
/*Parity_Selection*/
#define Parity_Selection_Even 0x00000000
#define Parity_Selection_Odd 0x00000200
/*Stop_Bit*/
#define Stop_Bit_1_b 0x00000000
#define Stop_Bit_05_b 0x00000100
#define Stop_Bit_2_b 0x00000200
#define Stop_Bit_15_b 0x00000300
/*UART_Mode*/
#define UART_Mode_Tx 0x0008
#define UART_Mode_Rx 0x0004
#define UART_Mode_Tx_Rx 0x000C

/*UART_Paremter_Config*/
typedef struct{
	volatile uint16_t Data_Len;
	volatile uint16_t Parity_Control;
	volatile uint16_t Parity_Selection;
	volatile uint16_t Stop_Bit;
	volatile uint16_t Baudrate;
	volatile uint16_t UART_Mode;
	}UART_Parameter_Config;
/*Prototype*/
/**/
void USART_config( My_UART* USARTx,  uint32_t baudrate);
void MY_UART_Config(My_UART* UARTx, UART_Parameter_Config* UART_Parameter);
void UART_Send_Byte( My_UART* UARTx,char Data);
void USART1_Send_String(My_UART* UARTx, const char *String);
void UART_Interrupt_config(My_UART* UARTx, uint16_t UART_IT_Mode, FunctionalState_Typedef New_state);
uint32_t checkUARTClockFrequency(My_UART *UARTx );
uint16_t UART_Get_Interrupt_Status( My_UART* UARTx, uint16_t UART_IT_Flag);
void UART_Clear_Flag( My_UART* UARTx, uint16_t UART_IT_Flag);
#endif