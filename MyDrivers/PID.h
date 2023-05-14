#ifndef __PID_H__
#define __PID_H__

#include "MyDrivers.h"

typedef struct
{
	float SetValue;      //�û����� ֵ��Ҳ������������ϵͳ���ڵ������ֵȻ���ȶ�����һ״̬
  float pid_Calc_out;  //PID����������ֵ����������ִ�л���
  float error;         //��ǰƫ��ֵ
  float error_last;    //��һ�μ����ƫ��ֵ
  float error_pre;     //����һ�μ����ƫ��ֵ��������ʽ���õ�
  float Kp;            //����ϵ��
  float Ki;            //����ϵ��
  float Kd;            //΢��ϵ��
  float integral;      //����ֵ
}Position_PID_t;

extern Position_PID_t Position_PID_Z;

void Position_PID_Init(Position_PID_t *Position_PID);

float Position_PID_Calc(Position_PID_t *Position_PID, float Next_val, float actual);

float Position_PID_Calc_1(Position_PID_t *Position_PID, float actual);

#endif
