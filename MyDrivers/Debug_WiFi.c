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
	* @brief  ����·����
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
	* @brief  ����tcp
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
	* @brief  TCP����
	* @param  None
	* @retval None   
*/
char WIFI_Connect(void)
{
/*0��������λ*/
//	u1_printf ("0��׼��������λ!\r\n");
//	if(WIFI_Config0(100))
//	{
//		u1_printf ("������λʧ��!\r\n");
//		return 1;
//	}
//	else
//		u1_printf ("������λ�ɹ�!\r\n");
//	u1_printf ("\r\n");
	
/*1������WIFIģʽ*/
//	u1_printf ("1��׼������WIFIģʽ!\r\n");
	if(WIFI_Config(50,"AT+CWMODE=1\r\n","OK"))
	{
//		u1_printf ("����WIFIģʽʧ��!\r\n");
		return 2;
	} 
	else
//		u1_printf ("����WIFIģʽ�ɹ�!\r\n");	                        
//	u1_printf ("\r\n");	
/*2������(���ʽ)*/	
//	u1_printf ("2��׼����λ!\r\n");
	if(WIFI_Config(50,"AT+RST\r\n","ready"))
	{
//		u1_printf ("��λʧ��!\r\n");
		return 3;
	}
	else
	{
//		u1_printf ("��λ�ɹ�!\r\n");		
	}
//	u1_printf ("\r\n");
/*3��ȡ���Զ�����*/		
//	u1_printf ("3��׼��ȡ���Զ�����\r\n");
	if(WIFI_Config(50,"AT+CWAUTOCONN=0\r\n","OK"))
	{
//		u1_printf ("ȡ���Զ�����ʧ��!\r\n");
		return 4;
	}
	else
	{
//		u1_printf ("ȡ���Զ����ӳɹ�!\r\n");
	}	
//	u1_printf ("\r\n");
/*4������·����*/	
//	u1_printf ("4��׼������·����\r\n");
	if(WIFI_Router(50))
	{
//		u1_printf ("����·����ʧ��!\r\n");
		return 5;
	}
	else
	{
//		u1_printf ("����·�����ɹ�!\r\n");
	}
//	u1_printf ("\r\n");
/*5�����õ�·����ģʽ*/		
//	u1_printf ("5��׼�����õ�·����ģʽ!\r\n");
	if(WIFI_Config(50,"AT+CIPMUX=0\r\n","OK"))
	{
//		u1_printf ("���õ�·����ģʽʧ��!\r\n");
		return 6;
	}
	else
	{
//		u1_printf ("���õ�·����ģʽ�ɹ�!\r\n");
	}
//	u1_printf ("\r\n");
/*6������͸��ģʽ*/		
//	u1_printf ("6��׼������͸��ģʽ\r\n");
	if(WIFI_Config(50,"AT+CIPMODE=1\r\n","OK"))
	{
//		u1_printf ("����͸��ģʽʧ��!\r\n");
		return 7;
	}
	else
	{
//		u1_printf ("����͸��ģʽ�ɹ�!\r\n");
	}
//	u1_printf ("\r\n");
/*7������TCP����*/		
//	u1_printf ("7��׼������TCP����\r\n");
	if(WIFI_ConnectTCP(50))
	{
		u1_printf ("����TCP����ʧ��!\r\n");
		return 8;
	}
	else
	{
		u1_printf ("����TCP���ӳɹ�!\r\n");
	}
//	u1_printf ("\r\n");
/*8������͸��ģʽ*/	
//	u1_printf ("8��׼������͸��ģʽ\r\n");
	if(WIFI_Config(50,"AT+CIPSEND\r\n","\r\nOK\r\n\r\n>"))
	{
		u1_printf ("����͸��ģʽʧ��!\r\n");
		return 9;
	}
	else
	{
		u1_printf ("����͸��ģʽ�ɹ�!\r\n");
	}
	return 0;
}



