#include "MyDrivers.h"

/* Public variables-----------------------------------------------------------*/

/*
	* @name   USART1_Init
	* @brief  USART1_Init初始化,准备与WIFI模块、舵机驱动板通信
	* @param  BaudRate：115200
	* @retval None   
*/
void USART1_Init(uint32_t BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  USART_DeInit(USART1);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	
	USART_ClearFlag(USART1, USART_FLAG_TC);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_9);	
	GPIO_SetBits(GPIOA, GPIO_Pin_10);
	GPIO_SetBits(GPIOB, GPIO_Pin_6);	
	GPIO_SetBits(GPIOB, GPIO_Pin_7);	
}                     

/*
	* @name   USART1_Remap
	* @brief  USART1分时复用
	* @param  RemapX = 1 ？不映射(PA9 PA10 WIFI) ：全映射与舵机通信(PB6 PB7).
	* @retval None   
*/
void USART1_Remap(uint8_t RemapX)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	if(RemapX)
	{
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		
		GPIO_PinRemapConfig(GPIO_Remap_USART1, DISABLE);
		USART1_Remap_Flag = FALSE;
	}
	else
	{
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOA, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		
		GPIO_PinRemapConfig(GPIO_Remap_USART1, ENABLE);
		USART1_Remap_Flag = TRUE;
	}
}

/*
	* @name   fputc
	* @brief  重映射
	* @param  None
	* @retval None   
*/
int fputc(int ch, FILE *f)
{
    /* 将Printf内容发往串口 */
    USART_SendData(USART1, (unsigned char)ch);
    while (!USART_GetFlagStatus(USART1, USART_FLAG_TC));
    USART_ClearFlag(USART1, USART_FLAG_TC);

    return (ch);
}

/*
	* @name   USART2_Init
	* @brief  USART2_Init初始化,、全场定位模块通信。
	* @param  BaudRate：115200
	* @retval None   
*/
void USART2_Init(uint32_t BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
  USART_DeInit(USART2); 
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	
	USART_ClearFlag(USART2, USART_FLAG_TC);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);
}

/*
	* @name   USART3_Init
	* @brief  USART3_Init初始化,颜色识别模块通信,PC11接收/PC10触发与扫码模块通信。
	* @param  BaudRate：9600
	* @retval None   
*/
void USART3_Init(uint32_t BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3 ,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  USART_DeInit(USART3);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	

	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx;
	USART_Init(USART3, &USART_InitStructure);
	
	USART_ClearFlag(USART3, USART_FLAG_TC);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART3,ENABLE);
	
	GPIO_SetBits(GPIOB,GPIO_Pin_10);
	GPIO_SetBits(GPIOB,GPIO_Pin_11);
	GPIO_SetBits(GPIOC,GPIO_Pin_10);
	GPIO_SetBits(GPIOC,GPIO_Pin_11);
}

/*
	* @name   USART3_Remap
	* @brief  USART3分时复用
	* @param  RemapX = 1 ？不映射（PB10,B11,颜色识别模块) ：部分映射（PC10,C11，二维码识别模块）
	* @retval None   
*/
void USART3_Remap(uint8_t RemapX )
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	if(RemapX)
	{
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//tx
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//输出低电平，触发颜色识别模块。
		GPIO_Init(GPIOB, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOC, &GPIO_InitStructure);
		GPIO_PinRemapConfig(GPIO_PartialRemap_USART3, DISABLE);
		USART3_Remap_Flag = FALSE;
	}
	else 
	{
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//tx
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		GPIO_Init(GPIOB,&GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出才能触发扫码
		GPIO_Init(GPIOC,&GPIO_InitStructure);
		GPIO_PinRemapConfig(GPIO_PartialRemap_USART3, ENABLE);//部分映射，连接二维码识别模块。
		USART3_Remap_Flag = TRUE;
	}
}

/*
	* @name   USART1_Printf
	* @brief  USART1打印字符串
	* @param  不定长字符串
	* @retval None   
*/
void USART1_Printf(uint8_t *dat)
{
	do
	{
  	USART_SendData(USART1,*dat++);
	  while(!(USART_GetFlagStatus(USART1,USART_FLAG_TC)));
	  USART_ClearFlag(USART1,USART_FLAG_TC);
	}
	while(*dat!='\0');
}

/*
	* @name   USART_SendByte
	* @brief  指定USART
	* @param  不定长字符串
	* @retval None   
*/
void USART_SendByte(USART_TypeDef* USARTx, uint16_t Data)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_DATA(Data)); 
    
  /* Transmit Data */
  USARTx->DR = (Data & (uint16_t)0x01FF);
  while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);

}

/*
	* @name   u1_printf
	* @brief  指定USART1
	* @param  不定长字符串
	* @retval None   
*/
__align(8) char USART1_TxBuff[256];  

void u1_printf(char* fmt,...) 
{  
	unsigned int i =0,length=0;
	
	va_list ap;
	va_start(ap,fmt);
	vsprintf(USART1_TxBuff,fmt,ap);
	va_end(ap);
	
	length=strlen((const char*)USART1_TxBuff);
	while(i<length)
	{
		USART_SendByte(USART1,USART1_TxBuff[i]);		
		i++;		
	}
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
}

/*
	* @name   USART2_Printf
	* @brief  USART1打印字符串
	* @param  不定长字符串
	* @retval None   
*/
void USART2_Printf(uint8_t *dat)
{
	do
	{
  	USART_SendData(USART2,*dat++);
	  while(!(USART_GetFlagStatus(USART2,USART_FLAG_TC)));
	  USART_ClearFlag(USART2,USART_FLAG_TC);
	}
	while(*dat!='\0');
}

/*
	* @name   USART3_Printf
	* @brief  USART3打印字符串
	* @param  不定长字符串
	* @retval None   
*/
void USART3_Printf(uint8_t *dat)
{
	do
	{
  	USART_SendData(USART3,*dat++);
	  while(!(USART_GetFlagStatus(USART3,USART_FLAG_TC)));
	  USART_ClearFlag(USART3,USART_FLAG_TC);
	}
	while(*dat!='\0');
}
