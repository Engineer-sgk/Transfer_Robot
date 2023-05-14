#include "MyDrivers.h"

uint32_t IOTimeOut = 2;//输入输出超时
uint8_t wBuf[128];
uint8_t wLen = 0;
__IO uint32_t TimingMillis = 0;

uint32_t millis(void)
{
	return TimingMillis;
}

void delay(uint32_t ms)
{
    uint32_t end = millis() + ms;
    while (millis() < end);
}

/*
	* @name   TIM6_IRQHandler
	* @brief  Time6中断服务函数
	* @param  参数：None
	* @retval None   
*/
void TIM6_IRQHandler(void)   
{
 if(TIM_GetITStatus(TIM6, TIM_IT_Update) == SET)
	{
		TimingMillis++;
		if(pos_x <= -0.000001 && pos_x >= +0.000001) 
			Last_Pos_x = pos_x;
		if(pos_y <= -0.000001 && pos_y >= +0.000001)
			Last_Pos_y = pos_x;
		TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
	}
}

//UART 接收数据接口
int readSCS(unsigned char *nDat, int nLen)
{
	int Size = 0;
	int ComData;
	uint32_t t_begin = millis();
	uint32_t t_user;
	while(1){
		ComData = Uart_Read();
		if(ComData!=-1){
			if(nDat){
				nDat[Size] = ComData;
			}
			Size++;
			t_begin = millis();
		}
		if(Size>=nLen){
			break;
		}
		t_user = millis() - t_begin;
		if(t_user>IOTimeOut){
			break;
		}
	}
	return Size;
}

//UART 发送数据接口
int writeSCS(unsigned char *nDat, int nLen)
{
	while(nLen--){
		if(wLen<sizeof(wBuf)){
			wBuf[wLen] = *nDat;
			wLen++;
			nDat++;
		}
	}
	return wLen;
}

//接收缓冲区刷新
void rFlushSCS()
{
	Uart_Flush();
}

//发送缓冲区刷新
void wFlushSCS()
{
	if(wLen){
		Uart_Send(wBuf, wLen);
		wLen = 0;
	}
}










