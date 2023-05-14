#include "MyDrivers.h"

//电机速度
int X_Dir_Speed = 0, Y_Dir_Speed = 0, Z_Dir_Speed = 0;

//坐标、姿态有关数据
float pos_x  = 0;
float pos_y  = 0;
float zangle = 0; 
//float xangle = 0; 
//float yangle = 0; 
//float w_z    = 0;

float Last_Pos_x = 0;
float Last_Pos_y = 0;
float Lsat_zangle = 0;

//中断控制标志位
//uint8_t Controll_Flag = 0;
System_t System = 
{
	0,
};

//计数标志位
uint16_t Count_Flag = 0;

//左右循迹结果保存变量
int16_t X_Positive_Tracking_Value = 0, Y_Positive_Tracking_Value = 0;

//目标航向角
float Expect_Yaw = 0.0;

//二维码扫描结果
uint8_t QR_Code[2][4] = {{'0','0','0',0},{'0','0','0',0}};

//颜色扫描结果
uint8_t Color_Code[2][4] = {{'0','0','0',0},{'0','0','0',0}};

//串口1重映射标志位
uint8_t USART1_Remap_Flag = FALSE;

//串口3重映射标志位
uint8_t USART3_Remap_Flag = FALSE;

//串口3缓存及标志位
uint8_t USART3_RX_Buff[9];
uint8_t USART3_Flag = FALSE;

Usart3_t Usart3 = 
{
	FALSE,
};

//串口舵机有关
//UART 读数据缓冲区
__IO uint8_t uartBuf[128];
__IO int head = 0;
__IO int tail  = 0;

//Debug_WiFi 连接计数有关
uint16_t WiFi_RxCounter = 0;

//Debug_WiFi 连接发送容器有关
char WiFi_RX_BUF[1024];




