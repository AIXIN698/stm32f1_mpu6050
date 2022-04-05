#include "test.h"

void test_task_1(void)
{
	short aacx,aacy,aacz;			//加速度传感器原始数据
  short gyrox,gyroy,gyroz;	//陀螺仪原始数据
  float temp;								//温度数据
	float pitch,roll,yaw;   	//欧拉角数据	
	
	while(mpu_dmp_get_data(&pitch,&roll,&yaw) != 0){}    // 获取欧拉角数据
		
	  MPU_Get_Accelerometer(&aacx,&aacy,&aacz);  				 // 获取加速度xyz轴数据
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);    			 // 获取角速度xyz轴数据
		temp=MPU_Get_Temperature();                        // 获取mpu6050芯片温度值
		
		printf("aacx = %5d  aacy = %5d  aacz = %5d  \r\n", aacx,aacy,aacz);        // 输出加速度xyz轴数据
		printf("gyrox = %5d  gyroy = %5d  gyroz = %5d  \r\n", gyrox,gyroy,gyroz);  // 输出角速度xyz轴数据
		printf("temp = %2.2f\r\n",temp);                                           // 输出mpu6050芯片温度值数据
		printf("pitch = %.2f  roll = %.2f  yaw = %.2f  \r\n", pitch,roll,yaw);           // 输出俯仰角 翻滚角 航向角数据
		
}

void test_task_2(void)
{

	HAL_GPIO_WritePin(LED_Test_GPIO_Port, LED_Test_Pin, GPIO_PIN_SET);
	osDelay(200);
	HAL_GPIO_WritePin(LED_Test_GPIO_Port, LED_Test_Pin, GPIO_PIN_RESET);
	osDelay(200);
	
}



