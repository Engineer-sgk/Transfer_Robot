#include "MyDrivers.h"

/*
	* @name   Middle_Filter_x
	* @brief  中值滤波
	* @param  参数：None
	* @retval None   
*/
int16_t Middle_Filter_x(void)
{
	#define tN 5
	int16_t value_buff[tN] = {0};
	int8_t count, i, j, temp;
	for(count = 0; count < tN; count++)
   {
       value_buff[count] = pos_x;
       //delay(); //如果采集数据比较慢，那么就需要延时或中断1819    }
			 for(j = 0; j < tN; j++)
			 {
					 if(value_buff[i] > value_buff[i + 1])
					 {
							 temp = value_buff[i];
							 value_buff[i] = value_buff[i + 1];
							 value_buff[i + 1] = temp;
					 }
			 }
	}
	 return value_buff[(tN - 1) / 2];
}

/*
	* @name   Middle_Filter_y
	* @brief  中值滤波
	* @param  参数：None
	* @retval None   
*/
int16_t Middle_Filter_y(void)
{
	#define tN 5
	int16_t value_buff[tN] = {0};
	int8_t count, i, j, temp;
	for(count = 0; count < tN; count++)
   {
       value_buff[count] = pos_y;
       //delay(); //如果采集数据比较慢，那么就需要延时或中断1819    }
			 for(j = 0; j < tN; j++)
			 {
					 if(value_buff[i] > value_buff[i + 1])
					 {
							 temp = value_buff[i];
							 value_buff[i] = value_buff[i + 1];
							 value_buff[i + 1] = temp;
					 }
			 }
	}
	 return value_buff[(tN - 1) / 2];
}


