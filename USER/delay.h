#ifndef __delay_H__
#define __delay_H__

#include "MyDrivers.h"

void Delay_Init(void);
void Delay_us(uint32_t nus);
void Delay_ms(uint32_t nms);
void Delay_s(uint32_t ns);
#endif
