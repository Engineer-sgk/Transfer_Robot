#ifndef __Global_Variable_H__
#define __Global_Variable_H__

#include "MyDrivers.h"

//定义枚举类型 -> TRUE/FALSE位
typedef enum 
{
  FALSE = 0U, 
  TRUE = !FALSE
} FlagStatus_t;

extern int X_Dir_Speed, Y_Dir_Speed, Z_Dir_Speed;

typedef struct
{
	uint8_t Controll_Flag;
}System_t;

extern System_t System;


typedef struct
{
	uint8_t Flag;
}Usart3_t;

extern Usart3_t Usart3;



//extern uint8_t Controll_Flag;

extern float pos_x, pos_y, zangle, xangle, yangle, w_z;

extern uint8_t QR_Code[2][4];
extern uint8_t Color_Code[2][4];

extern uint8_t USART3_RX_Buff[9];
extern uint8_t USART3_Flag;
extern uint8_t USART3_Remap_Flag;

extern uint8_t USART1_Remap_Flag;

extern __IO uint8_t uartBuf[128];
extern __IO int head;
extern __IO int tail;

extern float Expect_Yaw;

extern uint16_t Count_Flag;

extern int16_t X_Positive_Tracking_Value, Y_Positive_Tracking_Value;

extern float Last_Pos_x;
extern float Last_Pos_y;
extern float Lsat_zangle;

extern uint16_t WiFi_RxCounter;

extern char WiFi_RX_BUF[1024];

#endif

