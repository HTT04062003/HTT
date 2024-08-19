#include "myuart.h"
#include "mygpio.h"
#include "stm32f10x.h"
#include "mystartup.h"

void USART_config( My_UART* USARTx,  uint32_t baudrate){
	uint64_t APB_USART_Clock;
	double div;
	uint32_t nguyen;
	double		tmp;
	uint32_t du;
	if(USARTx == UART1_Base_Address){
		MY_RCC->APB2ENR |= (1<<14);
		/*Tx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_9, GPIO_Mode_AF_Push_Pull,My_GPIO_Speed_50MHz);
		/*Rx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_10, GPIO_Mode_Input_Floating,My_GPIO_Speed_50MHz);
		/**/
		APB_USART_Clock = PCLK2;
		}
	if(USARTx == UART2_Base_Address){
		MY_RCC->APB1ENR |= 1<<17;
		/*Tx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_2, GPIO_Mode_AF_Push_Pull,My_GPIO_Speed_50MHz);
		/*Rx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_3, GPIO_Mode_Input_Floating,My_GPIO_Speed_50MHz);
		/**/
		APB_USART_Clock = PCLK1;
		}
	if(USARTx == UART3_Base_Address){
		MY_RCC->APB1ENR |= 1<<18;
		/*Tx*/
		GPIO_Pin_Config(MY_GPIOB, My_GPIO_Pin_10, GPIO_Mode_AF_Push_Pull,My_GPIO_Speed_50MHz);
		/*Rx*/
		GPIO_Pin_Config(MY_GPIOB, My_GPIO_Pin_11, GPIO_Mode_Input_Floating,My_GPIO_Speed_50MHz);
		/**/
		APB_USART_Clock = PCLK1;
    }	
  /**/
		div =(double) (APB_USART_Clock/ (2*8*baudrate));
		nguyen = (uint32_t)div;
		tmp = div - nguyen;
		tmp = tmp*16;
		du = (uint32_t)tmp;
		USARTx->BRR = (nguyen << 4)|( du << 0);
		USARTx->CR1  |= (1<<2)|(1<<3)|(1<<13);
	}
void MY_UART_Config(My_UART* UARTx, UART_Parameter_Config* UART_Parameter){
	uint64_t APB_USART_Clock;
	double div;
	uint32_t nguyen;
	double tmp;
	uint32_t du;
	if(UARTx == UART1_Base_Address){
		MY_RCC->APB2ENR |= (1<<14);
		/*Tx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_9, GPIO_Mode_AF_Push_Pull,My_GPIO_Speed_50MHz);
		/*Rx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_10, GPIO_Mode_Input_Floating,My_GPIO_Speed_50MHz);
		/**/
		APB_USART_Clock = PCLK2;
		}
	if(UARTx == UART2_Base_Address){
		MY_RCC->APB1ENR |= 1<<17;
		/*Tx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_2, GPIO_Mode_AF_Push_Pull,My_GPIO_Speed_50MHz);
		/*Rx*/
		GPIO_Pin_Config(MY_GPIOA, My_GPIO_Pin_3, GPIO_Mode_Input_Floating,My_GPIO_Speed_50MHz);
		/**/
		APB_USART_Clock = PCLK1;
		}
	if(UARTx == UART3_Base_Address){
		MY_RCC->APB1ENR |= (uint32_t)(1<<18);
		/*Tx*/
		GPIO_Pin_Config(MY_GPIOB, My_GPIO_Pin_10, GPIO_Mode_AF_Push_Pull,My_GPIO_Speed_50MHz);
		/*Rx*/
		GPIO_Pin_Config(MY_GPIOB, My_GPIO_Pin_11, GPIO_Mode_Input_Floating,My_GPIO_Speed_50MHz);
		/**/
		APB_USART_Clock = PCLK1;
    }
	div = ((double)APB_USART_Clock/ (2*8*UART_Parameter->Baudrate));
	nguyen = (uint32_t)div;
	tmp = div - nguyen;
  tmp = tmp*16;
	du = (uint32_t)tmp;
	UARTx->BRR = 0;
  UARTx->BRR = (nguyen << 4)|( du << 0); 	
	/*CR1*/
	UARTx->CR1 &= (uint32_t)(~0x160C);
	UARTx->CR1 |= UART_Parameter->Data_Len;
	UARTx->CR1 |= UART_Parameter->Parity_Control;
	UARTx->CR1 |= UART_Parameter->Parity_Selection;
	UARTx->CR1 |= UART_Parameter->UART_Mode;
	/*CR2*/
	UARTx->CR2 &= (~(0x3000));
	UARTx->CR2 |= UART_Parameter->Stop_Bit;
	/**/
	UARTx->CR1 |= 1<<13;
	}
/**/

/**/
void UART_Data_Bit( My_UART* UARTx, uint16_t DataBit){
	
	}
/**/
void UART_Interrupt_config(My_UART* UARTx, uint16_t UART_IT_Mode, FunctionalState_Typedef New_state){
	uint32_t tmp = 0;
	if(New_state == ENABLE){
		tmp = UART_IT_Mode&0xFFFF;
		}
	if(New_state == DISABLE){
		tmp = UART_IT_Mode&0x0000;
		}
	UARTx->CR1 |= (uint16_t)tmp;
	}
/**/
uint16_t UART_Get_Interrupt_Status( My_UART* UARTx, uint16_t UART_IT_Flag){
	
	return UARTx->SR&UART_IT_Flag;
	}
/**/
void UART_Clear_Flag( My_UART* UARTx, uint16_t UART_IT_Flag){
	UARTx->SR &= ~(UART_IT_Flag);
	}
void UART_Send_Byte( My_UART* UARTx,char Data){
	while((UARTx->SR&(1<<6)) == 0);
	UARTx->DR = Data;
	}
void USART1_Send_String(My_UART* UARTx, const char *String)
	{
	while(*String)
	
		UART_Send_Byte(UARTx,*String++);
	}
/**/

/**/
/*
void USART1_IRQHandler(void){
	static uint8_t pos = 0;
	if(MY_UART1->SR&(1<<5)){
		
	  }
	}
*/
