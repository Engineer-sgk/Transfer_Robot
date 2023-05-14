#include "MyDrivers.h"
/*
1�Ŷ������ֵԽС����ʱ��ת����2613ʱ�������ҹ涨����㡣
2�Ŷ������ֵԽС��Խ�����ϼ��ƶ���
3�Ŷ������ֵԽС��Խ�����ϼ��ƶ���
4�Ŷ����(1440)��צ���ſ���1760צ�Ӻϲ���
*/

/*--------------------��е����̬���ú�������������--------------------*/
/*--------------------------------------------------------------------
1. Robot_Arm_Init()------��е�۳�ʼ��̬���۵�״̬��
2. Robot_Arm_Pose(uint8_t num)------��е����̬.
---------------------------------num----------------------------------
0��ץȡ��̬��ֱ���� 
1���ϲ��м�����ץȡ�� 23 ���ϲ��������ץȡ��24 ���ϲ��ұ�����ץȡ��
2�����Ϸ��ú�ɫ���ϼܡ�3�����Ϸ�����ɫ���ϼܡ�4�����Ϸ�����ɫ���ϼܡ�
5����ӹ����ĺ�ɫλ�á�6����ӹ�������ɫλ�á�7����ӹ�������ɫλ�á�
8��ȡ����ɫ���õ���ɫ���ϼ��ϡ�9��ȡ����ɫ�����õ���ɫ���ϼ��ϡ�10��ȡ����ɫ�����õ���ɫ���ϼ��ϡ�
11����Ʒ���ײ��ɫ����λ�á�  12����Ʒ���ײ���ɫ����λ�á�      13����Ʒ���ײ���ɫ����λ�á�
14����Ʒ�������ɫ����λ�á�  15����Ʒ��������ɫ����λ�á�      16����Ʒ�������ɫ����λ�á�
17��׼��ȡ���ײ����ϣ�ֱ��--->צ�ӳ�ץȡ״̬��   18��צ�Ӻϲ���ץס���ϡ�
19��ȡ��ԭ�����ײ��ɫ���ϲ����õ����ϼܺ�ɫλ�á�20��ȡ��ԭ�����ײ���ɫ���ϲ����õ����ϼ���ɫλ�á�
21��ȡ��ԭ�����ײ���ɫ���ϲ����õ����ϼ���ɫλ�á�
25��ȡ�ײ��� 26��ȡ�ײ���
--------------------------------------------------------------------*/
/*
	* @name   Robot_Arm_Init
	* @brief  ��е�۳�ʼ��̬
	* @param  None
	* @retval None   
*/
void Robot_Arm_Init(void)
{
	RegWritePosEx(1, 2613, 2000, 0);
	RegWritePosEx(2, 1700, 2000, 0);
	RegWritePosEx(3, 3152, 2000, 0);
	RegWritePosEx(4, 1440, 2000, 0);
	RegWriteAction(); 
	Delay_ms(300);
}

/*
	* @name   Robot_Arm_Pose
	* @brief  ��е����̬
	* @param  None
	* @retval None   
*/
void Robot_Arm_Pose(uint8_t num)
{
	switch(num)
	{
		case 0: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1440, 2000, 0);RegWriteAction(); Delay_s(1); 
		break;
		//�ϲ��м�����ץȡ
		case 1:RegWritePosEx(1, 2575, 2000, 0);RegWritePosEx(2, 2920, 2000, 0);//2940
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_s(1); //
		WritePosEx(4, 1770, 2000, 0);
		Delay_ms(600);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//�ϲ��������ץȡ
		case 23: RegWritePosEx(1, 2630, 2000, 0);RegWritePosEx(2, 2920, 2000, 0);//2940
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_s(1); //
		WritePosEx(4, 1770, 2000, 0);
		Delay_ms(600);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//�ϲ��ұ�����ץȡ
		case 24:RegWritePosEx(1, 2520, 2000, 0);RegWritePosEx(2, 2920, 2000, 0);//2940
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_ms(800); //
		WritePosEx(4, 1770, 2000, 0);
		Delay_ms(600);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//����---��ɫ��̬
		case 2:  RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		
		RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();Delay_ms(200);WritePosEx(1, 2613, 2000, 0);
		break;
		//����---��ɫ��̬
		case 3: RegWritePosEx(1, 2593, 2000, 0);RegWritePosEx(2, 1971, 3000, 0);RegWritePosEx(3, 759, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();
		break;
		//����---��ɫ��̬
		case 4: RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1940, 3000, 0);RegWritePosEx(3, 775, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		
		RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWritePosEx(4, 1460, 2000, 0);RegWriteAction();Delay_ms(200);
		WritePosEx(1, 2613, 2000, 0);
		break;
		
		//��ӹ������ú�ɫ��1.�����ϼ���ȡ����ɫ���ϡ� 2. ׼�����ú�ɫ���ϡ� 3. ���á� 4. ����׼�����ơ�
		case 5: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction(); Delay_ms(400);//ֱ�����ƣ�׼�����ƣ���
		//�����ϼ���ȡ����ɫ���ϡ�
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//ֱ��
		WritePosEx(2, 2192, 2000, 0); WritePosEx(3, 1579, 2000, 0); WritePosEx(1, 2535, 3000, 0); //2590
		//��������
		WritePosEx(2, 3543, 2000, 0);Delay_s(1);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//����
		//ֱ������
		RegWritePosEx(1, 2535, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;

		//��ӹ�������---��ɫ��1.�����ϼ���ȡ����ɫ���ϡ� 2. ׼�����ú�ɫ���ϡ� 3. ���á� 4. ����׼�����ơ�
		case 6: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();Delay_ms(400);//ֱ�����ƣ�׼�����ƣ���
		//�����ϼ���ȡ����ɫ���ϡ�
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);//849
		RegWriteAction();Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(400);
		//ֱ��׼��
		RegWritePosEx(1, 2570, 3000, 0); RegWritePosEx(2, 3580, 2000, 0);RegWritePosEx(3, 1579, 2000, 0); //1579
		RegWriteAction();Delay_ms(400);
		//����
		WritePosEx(2, 3543, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3543
		//ֱ�����ƣ�׼�����ƣ���
		RegWritePosEx(1, 2570, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0); 
		break;
		
		//��ӹ�������---��ɫ
		case 7: 
			//ֱ��
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);
		RegWriteAction();Delay_ms(400);
		//�����ϼ���ȡ����ɫ���ϡ�
		RegWritePosEx(1, 2265, 2000, 0);RegWritePosEx(2, 1900, 3000, 0);RegWritePosEx(3, 794, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(300);
		//ֱ����׼������
		RegWritePosEx(1, 2640, 3000, 0); RegWritePosEx(2, 3580, 2000, 0);RegWritePosEx(3, 1595, 2000, 0); //1579
		RegWriteAction();Delay_ms(400);
		//��������
		WritePosEx(2, 3530, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3543
		//ֱ�����ƣ�׼�����ƣ���
		RegWritePosEx(1, 2640, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0); 
		break;
		
		//�Ӱ�ӹ�����---��ɫ����---����С����ɫ���ϼ�λ��
		case 8: RegWritePosEx(2, 2192, 2000, 0); RegWritePosEx(1, 2613, 3000, 0); RegWritePosEx(3, 1579, 2000, 0);
		RegWritePosEx(4, 1440, 3000, 0);//2618->2668
		RegWriteAction();Delay_ms(400);  //ֱ��׼��,�б�Ҫ��Ҫ�����Ŷ����ץȡ׼����
		//ץȡ��������
		WritePosEx(2, 3523, 2000, 0);Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(500);
		//ֱ�����ƣ�׼�����ƣ���
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 794, 2000, 0);
		RegWriteAction();Delay_ms(800);
		//���õ���ɫ���ϼ�
		WritePosEx(1, 2255, 2000, 0);Delay_ms(200); RegWritePosEx(2, 1940, 3000, 0);RegWritePosEx(3, 790, 2000, 0);
		RegWriteAction(); Delay_ms(500); WritePosEx(4, 1480, 2000, 0); Delay_ms(300);
		//�ָ���ֱ��״̬
		RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500); 
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		
		break;
		
		//�Ӱ�ӹ�����---��ɫ����---����С����ɫ���ϼ�λ��
		case 9: RegWritePosEx(2, 2192, 2000, 0); RegWritePosEx(1, 2570, 3000, 0); RegWritePosEx(3, 1600, 2000, 0);RegWritePosEx(4, 1440, 3000, 0);
		RegWriteAction(); Delay_ms(400);  //ֱ��׼��,�б�Ҫ��Ҫ�����Ŷ����ץȡ׼����
		//��ʼץȡ��������
		WritePosEx(2, 3520, 2000, 0); Delay_ms(800); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//ֱ�����ƣ�׼�����ƣ���
		RegWritePosEx(1, 2613, 2000, 0); RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 739, 2000, 0);
		RegWriteAction();Delay_ms(600);
		//����ɫ���Ϸ��õ����ϼ��ϡ�
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);//849
		RegWriteAction();Delay_ms(300);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//����ɫ���Ϸ��õ����ϼ��ϡ�
		//�ָ���ֱ��״̬
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_ms(800); 
		break;
		
		//�Ӱ�ӹ�����---��ɫ����---����С����ɫ���ϼ�λ��
		case 10: RegWritePosEx(2, 2192, 2000, 0); RegWritePosEx(1, 2535, 3000, 0); RegWritePosEx(3, 1579, 2000, 0);RegWritePosEx(4, 1440, 3000, 0);
		RegWriteAction();Delay_ms(400);  
		//ץȡ��������
		WritePosEx(2, 3523, 2000, 0);Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(500);
		//ֱ�����ƣ�׼�����ƣ���
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(600);
		//����ɫ���Ϸ��õ����ϼ��ϡ�
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction();Delay_ms(600);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);
		//�ָ���ֱ��״̬
		WritePosEx(3, 1906, 2000, 0); Delay_ms(300); WritePosEx(2, 2192, 3000, 0); WritePosEx(1, 2613, 2000, 0);
		Delay_ms(800); 
		break;
		
		//��Ʒ����ɫ�ײ�λ��
		case 11:RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction(); Delay_ms(400);//ֱ�����ƣ�׼�����ƣ���
		//�����ϼ���ȡ����ɫ���ϡ�
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//ֱ��׼��
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2540, 3000, 0);RegWritePosEx(3, 1746, 2000, 0);
		RegWriteAction();Delay_ms(500);

		WritePosEx(2, 3370, 2000, 0);Delay_ms(800);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3387

		RegWritePosEx(1, 2540, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//ֱ�����ƣ�׼�����ƣ���
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//��Ʒ����ɫλ��
		case 12: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);RegWriteAction();Delay_ms(400);
		//�����ϼ�ȡ����ɫ����
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);//849
		RegWriteAction();Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(400);
		//ֱ��
		RegWritePosEx(2, 3580, 2000, 0);RegWritePosEx(1, 2564, 3000, 0);RegWritePosEx(3, 1720, 2000, 0);
		RegWriteAction();Delay_ms(500);//ֱ��׼��
		//��������
		WritePosEx(2, 3350, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2564, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//ֱ�����ƣ�׼�����ƣ���
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//��Ʒ���ײ���ɫλ��
		case 13: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);RegWritePosEx(4, 1460, 2000, 0);Delay_ms(400);//ֱ�����ƣ�׼�����ƣ���
		
		RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1900, 3000, 0);RegWritePosEx(3, 785, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(300);//�����ϼ���ȡ����ɫ���ϡ�
		
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2615, 3000, 0);RegWritePosEx(3, 1760, 2000, 0);
		RegWriteAction();Delay_ms(500);//ֱ��׼��

		WritePosEx(2, 3340, 2000, 0);Delay_ms(800);WritePosEx(4, 1330, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2615, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//ֱ�����ƣ�׼�����ƣ���
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//��Ʒ�������ɫλ��
		case 14: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction(); Delay_ms(400);//ֱ�����ƣ�׼�����ƣ���
		//�����ϼ���ȡ����ɫ���ϡ�
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(500);
		//ֱ��׼��
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2540, 3000, 0);RegWritePosEx(3, 2136, 2000, 0);
		RegWriteAction();Delay_ms(500);

		WritePosEx(2, 3020, 2000, 0);Delay_ms(800);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);//3387

		RegWritePosEx(1, 2540, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//ֱ�����ƣ�׼�����ƣ���
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//������ɫλ��
		case 15: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1460, 2000, 0);RegWriteAction();Delay_ms(400);
		//�����ϼ�ȡ����ɫ����
		RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 1941, 2000, 0);RegWritePosEx(3, 739, 2000, 0);
		RegWriteAction();Delay_ms(800);WritePosEx(4, 1770, 2000, 0);Delay_ms(400);//�����ϼ���ȡ����ɫ���ϡ�
		//ֱ��
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2560, 3000, 0);RegWritePosEx(3, 2136, 2000, 0);
		RegWriteAction();Delay_ms(500);//ֱ��׼��
		//��������
		WritePosEx(2, 3020, 2000, 0);Delay_ms(500);WritePosEx(4, 1460, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2560, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//ֱ�����ƣ�׼�����ƣ���
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		//��Ʒ��������������ɫλ��
		case 16: RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);RegWritePosEx(4, 1460, 2000, 0);Delay_ms(400);//ֱ�����ƣ�׼�����ƣ���
		
		RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1900, 3000, 0);RegWritePosEx(3, 785, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1770, 2000, 0); Delay_ms(300);//�����ϼ���ȡ����ɫ���ϡ�
		
		RegWritePosEx(2, 2192, 2000, 0);RegWritePosEx(1, 2610, 3000, 0);RegWritePosEx(3, 2136, 2000, 0);
		RegWriteAction();Delay_ms(500);//ֱ��׼��

		WritePosEx(2, 3020, 2000, 0);Delay_ms(800);WritePosEx(4, 1330, 2000, 0);Delay_ms(500);

		RegWritePosEx(1, 2610, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 849, 2000, 0);
		RegWriteAction();//ֱ�����ƣ�׼�����ƣ���
		Delay_ms(500); WritePosEx(3, 1906, 2000, 0);
		break;
		
		/* ��ԭ�����ײ�ȡ����ɫ���õ���ɫ���ϼܡ�1. ֱ����2. ץȡ״̬��3. ��ǰ����4. צ�Ӻϲ��� 5. �����ˡ� 
	  6. ֱ���� 7. ���õ����ϼܡ�*/
		//ȡ�м�
		case 17:
			//1. ֱ����
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1440, 2000, 0);RegWriteAction();
		  //2. ץȡ״��
		RegWritePosEx(2, 3410, 2000, 0);RegWritePosEx(1, 2590, 3000, 0);RegWritePosEx(3, 1680, 2000, 0);
		RegWriteAction();Delay_ms(500); 
		break;
		//ȡ���
		case 25:
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1440, 2000, 0);RegWriteAction();
		  //2. ץȡ״��
		RegWritePosEx(2, 3410, 2000, 0);RegWritePosEx(1, 2610, 3000, 0);RegWritePosEx(3, 1680, 2000, 0);
		RegWriteAction();Delay_ms(500); 
		break;
		//ȡ�ұ�
		case 26:
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWritePosEx(4, 1440, 2000, 0);RegWriteAction();
		  //2. ץȡ״��
		RegWritePosEx(2, 3410, 2000, 0);RegWritePosEx(1, 2560, 3000, 0);RegWritePosEx(3, 1680, 2000, 0);
		RegWriteAction();Delay_ms(500); 
		break;
		
		case 18:
		  //4. צ�Ӻϲ���
		Delay_ms(500);WritePosEx(4, 1770, 2000, 0);Delay_ms(500); break;
		
		/* ��ԭ�����ײ�ȡ����ɫ���õ���ɫ���ϼܡ�1. ֱ����2. ץȡ״��3. ��ǰ����4. צ�Ӻϲ��� 5. �����ˡ� 
	  6. ֱ���� 7. ���õ����ϼܡ�*/
		case 19:       
			 //6. ֱ����
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);
		  //7. ���õ����ϼܡ�
		RegWritePosEx(1, 2897, 2000, 0);RegWritePosEx(2, 1887, 3000, 0);RegWritePosEx(3, 809, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1460, 2000, 0); Delay_ms(300);
		  //8. ֱ����е��
		RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500);
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		break;			
		
		/* ��ԭ�����ײ�ȡ����ɫ���õ���ɫ���ϼܡ�1. ֱ����2. ץȡ״��3. ��ǰ����4. צ�Ӻϲ��� 5. �����ˡ� 
	  6. ֱ���� 7. ���õ����ϼܡ�*/
		case 20:       
			 //6. ֱ����
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);
		  //7. ���õ����ϼܡ�
		RegWritePosEx(1, 2593, 2000, 0);RegWritePosEx(2, 1971, 3000, 0);RegWritePosEx(3, 759, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1440, 2000, 0); Delay_ms(300);
		  //8. ֱ����е��
		RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500);
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		break;	
		
		/* ��ԭ�����ײ�ȡ����ɫ���õ���ɫ���ϼܡ�1. ֱ����2. ץȡ״��3. ��ǰ����4. צ�Ӻϲ��� 5. �����ˡ� 
	  6. ֱ���� 7. ���õ����ϼܡ�*/
		case 21:       
			 //6. ֱ����
		RegWritePosEx(1, 2613, 2000, 0);RegWritePosEx(2, 2192, 3000, 0);RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();Delay_ms(500);
		  //7. ���õ����ϼܡ�
		RegWritePosEx(1, 2275, 2000, 0);RegWritePosEx(2, 1940, 3000, 0);RegWritePosEx(3, 775, 2000, 0);
		RegWriteAction(); Delay_ms(700); WritePosEx(4, 1440, 2000, 0); Delay_ms(300);
		  //8. ֱ����е��
		RegWritePosEx(2, 2192, 3000, 0); RegWritePosEx(3, 1906, 2000, 0);RegWriteAction();Delay_ms(500);
		WritePosEx(1, 2613, 2000, 0);Delay_ms(100); 
		break;		
		
		case 22:RegWritePosEx(1, 2583, 2000, 0);RegWritePosEx(2, 2957, 2000, 0);//2613
		RegWritePosEx(3, 2155, 2000, 0);RegWriteAction(); Delay_s(1); //
		WritePosEx(4, 1640, 2000, 0);
		Delay_s(1);
		RegWritePosEx(1, 2613, 2000, 0);
		RegWritePosEx(2, 2192, 2000, 0);
		RegWritePosEx(3, 1906, 2000, 0);
		RegWriteAction();
		Delay_s(1); 
		break;
		
		
		
		default: Assert_Failed();break;
	}
}

