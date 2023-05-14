#include "MyDrivers.h"

int main()
{
	Peripheral_Set();
	
	while(1)
	{
		System_Run();
	}
}

/*
	* @name   Assert_Failed
	* @brief  ��������������
	* @param  None
	* @retval None      
*/
void Assert_Failed()
{
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
}

/*
	* @name   Cmpmemory
	* @brief  �Ƚ�Ԫ�������Ƿ�һ��
	* @param  uint8_t *ptr1, uint8_t *ptr2, uint8_t len
	* @retval 0 / 1  
*/
uint8_t Cmpmemory(uint8_t *ptr1, uint8_t *ptr2, uint8_t len)
{
	while(len--)
		if(*ptr1++ != *ptr2++) return 0;
	return 1;
}
