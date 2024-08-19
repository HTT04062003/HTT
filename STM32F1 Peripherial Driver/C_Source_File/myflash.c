#include "myflash.h"
/**/
void MY_FLASH_CLOCK(void){
	/**/
	MY_FLASH->CR |= MY_FLASH_CR_LOCK;
	}
/**/
void MY_FLASH_UNCLOCK(void){
	MY_FLASH->KEYR = KEY1;
	MY_FLASH->KEYR = KEY2;
	}
/**/
void MY_FLASH_ERASE( uint32_t u32_Page_Address){
	/**/
	if((MY_FLASH->CR&MY_FLASH_CR_LOCK) != 0) MY_FLASH_UNCLOCK();
	MY_FLASH->CR |= MY_FLASH_CR_PER;
	MY_FLASH->AR = u32_Page_Address;
	MY_FLASH->CR |= MY_FLASH_CR_STRT;
	while((MY_FLASH->CR&MY_FLASH_SR_BSY) != 0);
	MY_FLASH->CR &= (uint32_t)(~MY_FLASH_CR_PER);
	MY_FLASH_CLOCK();
	}
/**/
void MY_FLASH_Program_HalfWord( uint32_t u32Address, uint16_t Value){
	if((MY_FLASH->CR&MY_FLASH_CR_LOCK) != 0) MY_FLASH_UNCLOCK();
	MY_FLASH->CR |= MY_FLASH_CR_PG;
	*(uint16_t*)u32Address = Value;
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) != 0);
	MY_FLASH_CLOCK();
	}
/**/
void FLASH_WRITE_Int_Data(uint32_t u32StartAddress, int Data){
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) == MY_FLASH_SR_BSY);
	MY_FLASH_UNCLOCK();
	MY_FLASH->CR |= MY_FLASH_CR_PG;
	*(uint16_t*) u32StartAddress = (uint16_t)(Data >> 0);
	*(uint16_t*) (u32StartAddress + 2) = (uint16_t)(Data>>16);
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) == MY_FLASH_SR_BSY);
	MY_FLASH->CR &= (uint32_t)(~(MY_FLASH_CR_PG));
  MY_FLASH_CLOCK();
	}
void FLASH_WRITE_FLOAT_Data(uint32_t u32StartAddress, float Data){
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) == MY_FLASH_SR_BSY);
	MY_FLASH_UNCLOCK();
	MY_FLASH->CR |= MY_FLASH_CR_PG;
	uint16_t tmp[2];
	*(float*)tmp = Data;
	
	*(uint16_t*)(u32StartAddress ) = (uint16_t)*(tmp);
	*(uint16_t*)(u32StartAddress + 2) = (uint16_t)*(tmp + 1);
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) == MY_FLASH_SR_BSY);
	MY_FLASH->CR &= (uint32_t)(~(MY_FLASH_CR_PG));
  MY_FLASH_CLOCK();
	}
void FLASH_WRITE_BYTE_ARRAY( uint32_t u32StartAddress, uint8_t* Byte_Array, uint32_t Len){
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) == MY_FLASH_SR_BSY);
	MY_FLASH_UNCLOCK();
	MY_FLASH->CR |= MY_FLASH_CR_PG;
	uint16_t* ptr = (uint16_t*)Byte_Array;
	for(uint16_t i = 0; i< (Len/2 + 1); i++){
		*(uint16_t*)(u32StartAddress + 2*i) = (uint16_t)*ptr; 
		ptr++;
		}
	while((MY_FLASH->SR&MY_FLASH_SR_BSY) == MY_FLASH_SR_BSY);
	MY_FLASH->CR &= (uint32_t)(~(MY_FLASH_CR_PG));
  MY_FLASH_CLOCK();
	}
int FLASH_READ_Int_Data( uint32_t u32StartAddress){
	return *(int*)u32StartAddress;
	}
float FLASH_READ_FLOAT_Data( uint32_t u32StartAddress){
	uint32_t tmp = 0;
	tmp|= *(uint32_t*)u32StartAddress;
	return *(float*)&tmp;
	}
void FLASH_READ_BYTE_ARRAY_Data( uint32_t u8StartAddress, uint8_t* ByteArray, uint16_t Len){
	for(uint16_t i = 0; i<= Len; i++){
			*ByteArray++ = *(uint8_t*)u8StartAddress++;
		}
	}
