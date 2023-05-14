#include "MyDrivers.h"
/* Public variables-----------------------------------------------------------*/
/*
	* @name   QR_Scan_Trig
	* @brief  二维码识别模块触发，低电平触发
	* @param  None   
	* @retval None   
*/
void QR_Scan_Trig(void)
{
	PCout(10) = 0;
	Delay_ms(100);
	PCout(10) = 1;
	Delay_ms(80);
}

/*
	* @name   QR_Scan
	* @brief  二维码识别模块触发，低电平触发
	* @param  None   
	* @retval None   
*/
void QR_Scan(void)
{
	do
	{
		QR_Scan_Trig();
	}
	while(Usart3.Flag == FALSE);
	QR_Display(0, QR_Code[0]);
	QR_Display(1, QR_Code[1]);
	Usart3.Flag = FALSE;
}




