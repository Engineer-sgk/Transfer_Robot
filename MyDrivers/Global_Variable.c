#include "MyDrivers.h"

//����ٶ�
int X_Dir_Speed = 0, Y_Dir_Speed = 0, Z_Dir_Speed = 0;

//���ꡢ��̬�й�����
float pos_x  = 0;
float pos_y  = 0;
float zangle = 0; 
//float xangle = 0; 
//float yangle = 0; 
//float w_z    = 0;

float Last_Pos_x = 0;
float Last_Pos_y = 0;
float Lsat_zangle = 0;

//�жϿ��Ʊ�־λ
//uint8_t Controll_Flag = 0;
System_t System = 
{
	0,
};

//������־λ
uint16_t Count_Flag = 0;

//����ѭ������������
int16_t X_Positive_Tracking_Value = 0, Y_Positive_Tracking_Value = 0;

//Ŀ�꺽���
float Expect_Yaw = 0.0;

//��ά��ɨ����
uint8_t QR_Code[2][4] = {{'0','0','0',0},{'0','0','0',0}};

//��ɫɨ����
uint8_t Color_Code[2][4] = {{'0','0','0',0},{'0','0','0',0}};

//����1��ӳ���־λ
uint8_t USART1_Remap_Flag = FALSE;

//����3��ӳ���־λ
uint8_t USART3_Remap_Flag = FALSE;

//����3���漰��־λ
uint8_t USART3_RX_Buff[9];
uint8_t USART3_Flag = FALSE;

Usart3_t Usart3 = 
{
	FALSE,
};

//���ڶ���й�
//UART �����ݻ�����
__IO uint8_t uartBuf[128];
__IO int head = 0;
__IO int tail  = 0;

//Debug_WiFi ���Ӽ����й�
uint16_t WiFi_RxCounter = 0;

//Debug_WiFi ���ӷ��������й�
char WiFi_RX_BUF[1024];




