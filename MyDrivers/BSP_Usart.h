#ifndef __BSP_Usart_H__
#define __BSP_Usart_H__

#include "MyDrivers.h"

void USART1_Init(uint32_t BaudRate);
void USART2_Init(uint32_t BaudRate);
void USART3_Init(uint32_t BaudRate);
void USART1_Remap(uint8_t RemapX);
void USART2_Remap(uint8_t RemapX);
void USART3_Remap(uint8_t RemapX);
void USART1_Printf(uint8_t *dat);
void USART2_Printf(uint8_t *dat);
void USART3_Printf(uint8_t *dat);

void u1_printf(char* fmt,...) ;

#endif
