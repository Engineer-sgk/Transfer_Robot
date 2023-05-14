#ifndef __timer_H__
#define __timer_H__

#include "MyDrivers.h"

//定义枚举类型
typedef enum
{
	TIMER4_10mS  	= (uint16_t)2,
	TIMER4_50mS  	= (uint16_t)10,
	TIMER4_100mS	= (uint16_t)20,
	TIMER4_200mS	= (uint16_t)40,
	TIMER4_500mS	= (uint16_t)100,
	TIMER4_1S     = (uint16_t)250,
	TIMER4_2S     = (uint16_t)400,
	TIMER4_3S     = (uint16_t)600,
	TIMER4_5S     = (uint16_t)1000,
	TIMER4_10S    = (uint16_t)2000,
	TIMER4_3min   = (uint16_t)36000,
}TIMER4_Value_t;

void Timer4_5ms_Init(void);
void Timer6_1ms_Init(void);

#endif




