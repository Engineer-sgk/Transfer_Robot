#ifndef __Tracking_H__
#define __Tracking_H__

#include "MyDrivers.h"
//Y+方向循迹模块：B: PB3 A:PB4 C:PB5，X+方向循迹模块：B: PC0 A: PC1 C:PC2

#define Middle_Sensor_1 PCin(1) 
#define Left_Sensor_1   PCin(2)
#define Right_Sensor_1  PCin(0)

#define Middle_Sensor_2 PBin(4)
#define Left1_Sensor_2  PBin(8)
#define Right1_Sensor_2 PBin(5)
#define Left2_Sensor_2  PBin(9)
#define Right2_Sensor_2 PBin(3)

//3号传感器 B:PC3： A:PA0  C:PA1
#define Middle_Sensor_3 PAin(0)
#define Left_Sensor_3   PCin(3)
#define Right_Sensor_3  PAin(1)

void Tracking_Init(void);
int16_t Tracking_X_Positive_Dir(void);

//int16_t Get_Tracking_Data1(void);
//int16_t Get_Tracking_Data2(void);

int16_t Tracking_Y_Positive_Dir(void);

#endif
