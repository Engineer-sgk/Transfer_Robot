#include "MyDrivers.h"

#if 1

#define ID         "202Classroom"                     
#define PASSWORD   "999999999" 

#else

#define ID         "sgk123"                     
#define PASSWORD   "123456123" 

#endif

#define ServerIP   "192.168.0.103"
#define ServerPort "8888"

/*
	* @name   WIFI_Config0
	* @brief  WIFI_Config0
	* @param  None
	* @retval None   
*/
char WIFI_Config0(int time)
{
	memset(WiFi_RX_BUF,0,1024);
	WiFi_RxCounter = 0;
	while(time--)
	{
		Delay_ms(100);
		if(strstr(WiFi_RX_BUF,"ready"))
			break;
		//u1_printf ("%d ",time); 
	}
	if(time>0)
       return 0; 
    else
       return 1;
}

/*
	* @name   WIFI_Config
	* @brief  WIFI_Config
	* @param  None
	* @retval None   
*/
char WIFI_Config(int time,char*cmd,char*response)
{
	memset(WiFi_RX_BUF,0,1024);
	WiFi_RxCounter = 0;
	u1_printf("%s\r\n",cmd); 
	while(time--)
	{
		Delay_ms(100);
		if(strstr(WiFi_RX_BUF,response))
			break;
		//u1_printf ("%d ",time); 
	}
	if(time>0)
       return 0; 
    else
       return 1;
}

/*
	* @name   WIFI_Router
	* @brief  连接路由器
	* @param  None
	* @retval None   
*/
char WIFI_Router(int time)
{
	memset(WiFi_RX_BUF,0,1024);
	WiFi_RxCounter = 0;
	u1_printf("AT+CWJAP=\"%s\",\"%s\"\r\n",ID, PASSWORD);
	while(time--)
	{
		Delay_s(1);
		if(strstr(WiFi_RX_BUF,"OK"))
			break;
//		u1_printf ("%d ",time); 
	}
	if(time>0)
       return 0; 
    else
       return 1;
}

/*
	* @name   WIFI_ConnectTCP
	* @brief  连接tcp
	* @param  None
	* @retval None   
*/
char WIFI_ConnectTCP(int time)
{
	memset(WiFi_RX_BUF,0,1024);
	WiFi_RxCounter = 0;
	u1_printf("AT+CIPSTART=\"TCP\",\"%s\",%s\r\n",ServerIP, ServerPort);
	while(time--)
	{
		Delay_s(1);
		if(strstr(WiFi_RX_BUF,"OK"))
			break;
//		u1_printf ("%d ",time); 
	}
	if(time>0)
       return 0; 
    else
       return 1;
}

/*
	* @name   WIFI_Connect
	* @brief  TCP连接
	* @param  None
	* @retval None   
*/
char WIFI_Connect(void)
{
/*0、按键复位*/
//	u1_printf ("0、准备按键复位!\r\n");
//	if(WIFI_Config0(100))
//	{
//		u1_printf ("按键复位失败!\r\n");
//		return 1;
//	}
//	else
//		u1_printf ("按键复位成功!\r\n");
//	u1_printf ("\r\n");
	
/*1、配置WIFI模式*/
//	u1_printf ("1、准备配置WIFI模式!\r\n");
	if(WIFI_Config(50,"AT+CWMODE=1\r\n","OK"))
	{
//		u1_printf ("配置WIFI模式失败!\r\n");
		return 2;
	} 
	else
//		u1_printf ("配置WIFI模式成功!\r\n");	                        
//	u1_printf ("\r\n");	
/*2、重启(命令方式)*/	
//	u1_printf ("2、准备复位!\r\n");
	if(WIFI_Config(50,"AT+RST\r\n","ready"))
	{
//		u1_printf ("复位失败!\r\n");
		return 3;
	}
	else
	{
//		u1_printf ("复位成功!\r\n");		
	}
//	u1_printf ("\r\n");
/*3、取消自动连接*/		
//	u1_printf ("3、准备取消自动连接\r\n");
	if(WIFI_Config(50,"AT+CWAUTOCONN=0\r\n","OK"))
	{
//		u1_printf ("取消自动连接失败!\r\n");
		return 4;
	}
	else
	{
//		u1_printf ("取消自动连接成功!\r\n");
	}	
//	u1_printf ("\r\n");
/*4、连接路由器*/	
//	u1_printf ("4、准备连接路由器\r\n");
	if(WIFI_Router(50))
	{
//		u1_printf ("连接路由器失败!\r\n");
		return 5;
	}
	else
	{
//		u1_printf ("连接路由器成功!\r\n");
	}
//	u1_printf ("\r\n");
/*5、配置单路连接模式*/		
//	u1_printf ("5、准备配置单路连接模式!\r\n");
	if(WIFI_Config(50,"AT+CIPMUX=0\r\n","OK"))
	{
//		u1_printf ("配置单路连接模式失败!\r\n");
		return 6;
	}
	else
	{
//		u1_printf ("配置单路连接模式成功!\r\n");
	}
//	u1_printf ("\r\n");
/*6、开启透传模式*/		
//	u1_printf ("6、准备开启透传模式\r\n");
	if(WIFI_Config(50,"AT+CIPMODE=1\r\n","OK"))
	{
//		u1_printf ("开启透传模式失败!\r\n");
		return 7;
	}
	else
	{
//		u1_printf ("开启透传模式成功!\r\n");
	}
//	u1_printf ("\r\n");
/*7、建立TCP连接*/		
//	u1_printf ("7、准备建立TCP连接\r\n");
	if(WIFI_ConnectTCP(50))
	{
		u1_printf ("建立TCP连接失败!\r\n");
		return 8;
	}
	else
	{
		u1_printf ("建立TCP连接成功!\r\n");
	}
//	u1_printf ("\r\n");
/*8、进入透传模式*/	
//	u1_printf ("8、准备进入透传模式\r\n");
	if(WIFI_Config(50,"AT+CIPSEND\r\n","\r\nOK\r\n\r\n>"))
	{
		u1_printf ("进入透传模式失败!\r\n");
		return 9;
	}
	else
	{
		u1_printf ("进入透传模式成功!\r\n");
	}
	return 0;
}



