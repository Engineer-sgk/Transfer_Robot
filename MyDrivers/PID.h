#ifndef __PID_H__
#define __PID_H__

#include "MyDrivers.h"

typedef struct
{
	float SetValue;      //用户期望 值，也就是我们期望系统调节到输出此值然后稳定在这一状态
  float pid_Calc_out;  //PID计算输出结果值，用来驱动执行机构
  float error;         //当前偏差值
  float error_last;    //上一次计算的偏差值
  float error_pre;     //上上一次计算的偏差值，在增量式里用到
  float Kp;            //比例系数
  float Ki;            //积分系数
  float Kd;            //微分系数
  float integral;      //积分值
}Position_PID_t;

extern Position_PID_t Position_PID_Z;

void Position_PID_Init(Position_PID_t *Position_PID);

float Position_PID_Calc(Position_PID_t *Position_PID, float Next_val, float actual);

float Position_PID_Calc_1(Position_PID_t *Position_PID, float actual);

#endif
