#include "test.h"

void test_task_1(void)
{
	short aacx,aacy,aacz;			//���ٶȴ�����ԭʼ����
  short gyrox,gyroy,gyroz;	//������ԭʼ����
  float temp;								//�¶�����
	float pitch,roll,yaw;   	//ŷ��������	
	
	while(mpu_dmp_get_data(&pitch,&roll,&yaw) != 0){}    // ��ȡŷ��������
		
	  MPU_Get_Accelerometer(&aacx,&aacy,&aacz);  				 // ��ȡ���ٶ�xyz������
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);    			 // ��ȡ���ٶ�xyz������
		temp=MPU_Get_Temperature();                        // ��ȡmpu6050оƬ�¶�ֵ
		
		printf("aacx = %5d  aacy = %5d  aacz = %5d  \r\n", aacx,aacy,aacz);        // ������ٶ�xyz������
		printf("gyrox = %5d  gyroy = %5d  gyroz = %5d  \r\n", gyrox,gyroy,gyroz);  // ������ٶ�xyz������
		printf("temp = %2.2f\r\n",temp);                                           // ���mpu6050оƬ�¶�ֵ����
		printf("pitch = %.2f  roll = %.2f  yaw = %.2f  \r\n", pitch,roll,yaw);           // ��������� ������ ���������
		
}

void test_task_2(void)
{

	HAL_GPIO_WritePin(LED_Test_GPIO_Port, LED_Test_Pin, GPIO_PIN_SET);
	osDelay(200);
	HAL_GPIO_WritePin(LED_Test_GPIO_Port, LED_Test_Pin, GPIO_PIN_RESET);
	osDelay(200);
	
}



