#include "MyDrivers.h"

/*
	* @name   Uart_Flush
	* @brief  Uart_Flush
	* @param  None
	* @retval None   
*/
void Uart_Flush(void)
{
	head = tail = 0;
}

/*
	* @name   Uart_Read
	* @brief  Uart_Read
	* @param  None
	* @retval None   
*/
int16_t Uart_Read(void)
{
	if(head!=tail){
		uint8_t Data = uartBuf[head];
		head =  (head+1)%128;
		return Data;
	}else{
		return -1;
	}
}

/*
	* @name   Uart_Send
	* @brief  Uart_Send
	* @param  None
	* @retval None   
*/
void Uart_Send(uint8_t *buf , uint8_t len)
{
	uint8_t i=0;
	for(i=0; i<len; i++){
		USART_SendData(USART1, buf[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}


