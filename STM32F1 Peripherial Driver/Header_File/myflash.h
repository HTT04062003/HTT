#ifndef __MYFLASH_H_
#define __MYFLASH_H_
#include "mystartup.h"
/*MY_FLASH_CR*/
#define MY_FLASH_CR_PG 0x0001
#define MY_FLASH_CR_PER 0x0002
#define MY_FLASH_CR_MER 0x0004
#define MY_FLASH_CR_OPTPG 0x0010
#define MY_FLASH_CR_OPTER 0x0020
#define MY_FLASH_CR_STRT 0x0040
#define MY_FLASH_CR_LOCK 0x0080
#define MY_FLASH_CR_OPTWRE 0x0200
#define MY_FLASH_CR_
/*MY_FLASH_SR*/
#define MY_FLASH_SR_BSY 0x00000001
#define MY_FLASH_SR_PG_ERR 0x00000004
#define MY_FLASH_SR_PG_EOP 0x00000040
/*FLASH_Key_Value*/
#define KEY1 0x45670123
#define KEY2 0xCDEF89AB
/**/

/**/
void MY_FLASH_CLOCK(void);
void MY_FLASH_UNCLOCK(void);
void MY_FLASH_ERASE( uint32_t u32_Page_Address);

void MY_FLASH_Program_HalfWord( uint32_t u32Address, uint16_t Value);
void FLASH_WRITE_Int_Data(uint32_t u32StartAddress, int Data);
int FLASH_READ_Int_Data( uint32_t u32StartAddress);
void FLASH_WRITE_FLOAT_Data(uint32_t u32StartAddress, float Data);
float FLASH_READ_FLOAT_Data( uint32_t u32StartAddress);
void FLASH_WRITE_BYTE_ARRAY( uint32_t u32StartAddress, uint8_t* Byte_Array, uint32_t Len);
void FLASH_READ_BYTE_ARRAY_Data( uint32_t u8StartAddress, uint8_t* ByteArray, uint16_t Len);
/**/

#endif