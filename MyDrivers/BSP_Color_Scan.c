#include "MyDrivers.h"

/*
	* @name   Color_Scan
	* @brief  ��ɫʶ��ʶ��ģ�鴥�����͵�ƽ����
	* @param  None   
	* @retval None   
*/
void Color_Scan(void)
{
	PBout(10) = 0;//����
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


