#ifndef __Servo_UART_Config_H__
#define __Servo_UART_Config_H__

#include "MyDrivers.h"

int16_t Uart_Read(void);
void Uart_Flush(void);
void Uart_Send(uint8_t *buf , uint8_t len);

#endif
