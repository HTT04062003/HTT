#ifndef __MYSTARTUP_H_
#define __MYSTARTUP_H_
#include <stdint.h>
/**/
typedef enum{
	DIS = 0,
	EN = !DIS,
	}FunctionalState_Typedef;
/*GPIO*/
#define GPIOA_Base_Address 0x40010800
#define GPIOB_Base_Address 0X40010C00
#define GPIOC_Base_Address 0x40011000
#define GPIOD_Base_Address 0x40011400
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
	}My_GPIO_Typedef;
#define MY_GPIOA ((My_GPIO_Typedef *)GPIOA_Base_Address)
#define MY_GPIOB ((My_GPIO_Typedef *)GPIOB_Base_Address)
#define MY_GPIOC ((My_GPIO_Typedef *)GPIOC_Base_Address)
#define MY_GPIOD ((My_GPIO_Typedef *)GPIOD_Base_Address)
/*RCC*/
#define RCC_Base_Address 0x40021000
	
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	}My_RCC_Typedef;

#define MY_RCC ((My_RCC_Typedef*)RCC_Base_Address)
/*TIM*/
#define MY_TIM1_BASE_ADDRESS 0x40012C00
#define MY_TIM2_BASE_ADDRESS 0x40000000
#define MY_TIM3_BASE_ADDRESS 0x40000400
#define MY_TIM4_BASE_ADDRESS 0x40000800\

typedef struct{
	volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SMCR;
  uint16_t  RESERVED2;
  volatile uint16_t DIER;
  uint16_t  RESERVED3;
  volatile uint16_t SR;
  uint16_t  RESERVED4;
  volatile uint16_t EGR;
  uint16_t  RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t  RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t  RESERVED7;
  volatile uint16_t CCER;
  uint16_t  RESERVED8;
  volatile uint16_t CNT;
  uint16_t  RESERVED9;
  volatile uint16_t PSC;
  uint16_t  RESERVED10;
  volatile uint16_t ARR;
  uint16_t  RESERVED11;
  volatile uint16_t RCR;
  uint16_t  RESERVED12;
  volatile uint16_t CCR1;
  uint16_t  RESERVED13;
  volatile uint16_t CCR2;
  uint16_t  RESERVED14;
  volatile uint16_t CCR3;
  uint16_t  RESERVED15;
  volatile uint16_t CCR4;
  uint16_t  RESERVED16;
  volatile uint16_t BDTR;
  uint16_t  RESERVED17;
  volatile uint16_t DCR;
  uint16_t  RESERVED18;
  volatile uint16_t DMAR;
  uint16_t  RESERVED19;
	}My_TIM;
#define MY_TIM1 ((My_TIM*) MY_TIM1_BASE_ADDRESS)
#define MY_TIM2 ((My_TIM*) MY_TIM2_BASE_ADDRESS)
#define MY_TIM3 ((My_TIM*) MY_TIM3_BASE_ADDRESS)
#define MY_TIM4 ((My_TIM*) MY_TIM4_BASE_ADDRESS)	

/*UART*/
#define UART1_Base_Address (uint32_t)0x40013800UL
#define UART2_Base_Address (uint32_t)0x40004400UL
#define UART3_Base_Address (uint32_t)0x40004800UL

typedef struct{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	}My_UART;

#define MY_UART1 ((My_UART*)UART1_Base_Address)
#define MY_UART2 ((My_UART*)UART2_Base_Address)
#define MY_UART3 ((My_UART*)UART3_Base_Address)
/*EXTI*/
#define EXTI_Base_Address 0x40010400
	
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
	}My_EXTI;
#define MY_EXTI ((My_EXTI*)EXTI_Base_Address)
/*AFIO*/
#define AFIO_Base_Address 0x40010000

typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	}My_AFIO;

#define MY_AFIO ((My_AFIO*)AFIO_Base_Address)
/*FLASH*/
#define MY_FLASH_BASE_ADDRESS 0x40022000
typedef struct{
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t AR;
	volatile uint32_t OBR;
	volatile uint32_t WRPR;
	}My_FLASH_Typedef;
#define MY_FLASH ((My_FLASH_Typedef*)MY_FLASH_BASE_ADDRESS)
/**/
#define SPT1_Base_Address 0x40013000
#define SPI2_Base_Address 0x40003800
typedef struct{
	volatile uint16_t CR1;
	volatile uint16_t padding_1;
	volatile uint16_t CR2;
	volatile uint16_t padding_2;
	volatile uint16_t padding_3;
	volatile uint16_t SR;
	volatile uint16_t padding_4;
	volatile uint16_t DR;
	volatile uint16_t padding_5;
	volatile uint16_t CRCPR;
	volatile uint16_t padding_6;
	volatile uint16_t RXCRCR;
	volatile uint16_t padding_7;
	volatile uint16_t TXCRCR;
	volatile uint16_t padding_8;
	}My_SPI_Typedef;
#define MY_SPI1 ((My_SPI_Typedef*)SPT1_Base_Address)
#define MY_SPI2 ((My_SPI_Typedef*)SPI2_Base_Address)
/*DMA*/
#define MY_DMA_Base_Address (uint32_t)0x40020000 
#define MY_DMA_Channel1_Base_Address (0x40020008)
#define MY_DMA_Channel2_Base_Address (MY_DMA_Base_Address + 0x08 + 20*2)
#define MY_DMA_Channel3_Base_Address (MY_DMA_Base_Address + 0x08 + 20*3)
#define MY_DMA_Channel4_Base_Address (MY_DMA_Base_Address + 0x08 + 20*4)
#define MY_DMA_Channel5_Base_Address (MY_DMA_Base_Address + 0x08 + 20*5)
#define MY_DMA_Channel6_Base_Address (MY_DMA_Base_Address + 0x08 + 20*6)
#define MY_DMA_Channel7_Base_Address (MY_DMA_Base_Address + 0x08 + 20*7)	
typedef struct{
	volatile uint32_t ISR;
	volatile uint32_t IFCR;
	}My_DMA_Typedef;

typedef struct{
	volatile uint32_t CCR;
	volatile uint32_t CNDTR;
	volatile uint32_t CPAR;
	volatile uint32_t CMAR;
	}My_DMA_Channelx_Typedef;
#define MY_DMA ((My_DMA_Typedef*)MY_DMA_Base_Address)
#define MY_DMA_Channel_1 ((My_DMA_Channelx_Typedef*)MY_DMA_Channel1_Base_Address)
#define MY_DMA_Channel_2 ((My_DMA_Channelx_Typedef*)MY_DMA_Channel2_Base_Address)
#define MY_DMA_Channel_3 ((My_DMA_Channelx_Typedef*)MY_DMA_Channel3_Base_Address)
#define MY_DMA_Channel_4 ((My_DMA_Channelx_Typedef*)MY_DMA_Channel4_Base_Address)	
#define MY_DMA_Channel_5 ((My_DMA_Channelx_Typedef*)MY_DMA_Channel5_Base_Address)	
/*CAN*/
#define bxCAN_Base_Address (uint32_t)0x40006400

typedef struct{
	volatile uint32_t TIR;
	volatile uint32_t TDTR;
	volatile uint32_t TDLR;
	volatile uint32_t TDHR;
	}My_CAN_TxMailBox_Typedef;
typedef struct{
	volatile uint32_t RIR;
	volatile uint32_t RDTR;
	volatile uint32_t RDLR;
	volatile uint32_t RDHR;
	}My_CAN_FIFO_Typedef;
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} My_CAN_FilterRegister_TypeDef;

typedef struct{
	volatile uint32_t MCR;
	volatile uint32_t MSR;
	volatile uint32_t TSR;
	volatile uint32_t RF0R;
	volatile uint32_t RF1R;
	volatile uint32_t IER;
	volatile uint32_t ESR;
	volatile uint32_t BTR;
	uint32_t REVERVE0[88];
	
	}My_CAN_Typedef;	

#endif