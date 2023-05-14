#include "MyDrivers.h"

/*
	* @name   Color_Scan
	* @brief  颜色识别识别模块触发，低电平触发
	* @param  None   
	* @retval None   
*/
void Color_Scan(void)
{
	PBout(10) = 0;//触发
	while(1)
	{
		if(Usart3.Flag == TRUE)
		{
			PBout(10) = 1;
			QR_Display(2, Color_Code[0]);
	    QR_Display(3, Color_Code[1]);
			Usart3.Flag = FALSE;
			break;
		}
	}
}


