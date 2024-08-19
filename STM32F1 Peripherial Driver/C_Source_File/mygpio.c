#include "mygpio.h"
        
/**/

/**/
void GPIO_Pin_Config(My_GPIO_Typedef* GPIOx, uint16_t GPIO_Pin, GPIO_Mode Mode, uint32_t GPIO_Speed){
	
	if(GPIOx == GPIOA_Base_Address) MY_RCC->APB2ENR |= 1<<2;
	if(GPIOx == GPIOB_Base_Address) MY_RCC->APB2ENR |= 1<<3;
	if(GPIOx == GPIOC_Base_Address) MY_RCC->APB2ENR |= 1<<4;
	if(GPIOx == GPIOD_Base_Address) MY_RCC->APB2ENR |= 1<<5;
	/**/
	if((Mode == GPIO_Mode_Input_Floating) || (Mode == GPIO_Mode_Input_Pull_Up)) GPIO_Speed = 0x0;
	uint32_t tmp;
	tmp = (uint32_t)Mode|GPIO_Speed;
	/*CRL config*/
	if(GPIO_Pin < My_GPIO_Pin_8){
		GPIOx->CRL &= (uint32_t)(~(0xF << (GPIO_Pin*4)));
		GPIOx->CRL |= (uint32_t)(tmp)<<(GPIO_Pin*4);
		}
	/*CRH config*/
	if(GPIO_Pin >= My_GPIO_Pin_8){
		GPIOx->CRH &= (uint32_t)(~(0xF << ((GPIO_Pin - 8)*4)));
		GPIOx->CRH |= (uint32_t)(tmp<<((GPIO_Pin - 8)*4));
		}
}
/**/
void GPIO_Set_Pin( My_GPIO_Typedef* GPIOx, uint16_t GPIO_pin){
	GPIOx->ODR |= 1<<GPIO_pin;
	}
/**/
void GPIO_Reset_Pin( My_GPIO_Typedef* GPIOx, uint16_t GPIO_pin){
  GPIOx->ODR &=(~(1<<GPIO_pin));
  }	
/**/
void GPIO_Write_Pin( My_GPIO_Typedef* GPIOx, uint16_t GPIO_pin, uint8_t New_State){
	if(New_State == 0){
		GPIOx->ODR &=  (~(1<<GPIO_pin));
		}
	if(New_State != 0){
		GPIOx->ODR |=  1<<GPIO_pin;
		}
	}
