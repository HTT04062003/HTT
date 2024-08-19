#ifndef __MYEXTI_H_
#define __MYEXTI_H_
/**/
#include <stdint.h>              
#include "mystartup.h"

/*MY_EXTI_Linex_port_selection*/
#define MY_EXTI_Linex_Port_PAx 0x0
#define MY_EXTI_Linex_Port_PBx 0x1
#define MY_EXTI_Linex_Port_PCx 0x2
#define MY_EXTI_Linex_Port_PDx 0x3
#define MY_EXTI_Linex_Port_PEx 0x4
/*MY_EXTI_Line_Selection*/
#define MY_EXTI_Line_0 0
#define MY_EXTI_Line_1 1
#define MY_EXTI_Line_2 2
#define MY_EXTI_Line_3 3
#define MY_EXTI_Line_4 4
#define MY_EXTI_Line_5 5
#define MY_EXTI_Line_6 6
#define MY_EXTI_Line_7 7
#define MY_EXTI_Line_8 8
#define MY_EXTI_Line_9 9
#define MY_EXTI_Line_10 10
#define MY_EXTI_Line_11 11
#define MY_EXTI_Line_12 12
#define MY_EXTI_Line_13 13
#define MY_EXTI_Line_14 14
#define MY_EXTI_Line_15 15
/*MY_EXTI_Edge*/
#define MY_EXTI_Rising_Edge 0x0000
#define MY_EXTI_Falling_Edge 0xFFFF
/*MY_EXTI_Flag*/

/**/
void MY_EXTI_Line_config( uint16_t MY_EXTI_Line_Selection, uint16_t MY_EXTI_Port_Selection, uint16_t MY_EXTI_Edge);
uint16_t  MY_EXTI_Get_It_Status( uint16_t MY_EXTI_Line);
/**/
#endif