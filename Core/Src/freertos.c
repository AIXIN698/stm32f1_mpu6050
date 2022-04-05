/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "test.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId Task_1Handle;
osThreadId Task_2Handle;
osThreadId Task_3Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Start_Task_i(void const * argument);
void Start_Task_2(void const * argument);
void Start_Task_3(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of Task_1 */
  osThreadDef(Task_1, Start_Task_i, osPriorityNormal, 0, 128);
  Task_1Handle = osThreadCreate(osThread(Task_1), NULL);

  /* definition and creation of Task_2 */
  osThreadDef(Task_2, Start_Task_2, osPriorityIdle, 0, 128);
  Task_2Handle = osThreadCreate(osThread(Task_2), NULL);

  /* definition and creation of Task_3 */
  osThreadDef(Task_3, Start_Task_3, osPriorityIdle, 0, 128);
  Task_3Handle = osThreadCreate(osThread(Task_3), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Start_Task_i */
/**
  * @brief  Function implementing the Task_1 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Start_Task_i */
void Start_Task_i(void const * argument)
{
  /* USER CODE BEGIN Start_Task_i */
	
	/* MPU6050 Init */
	while(MPU_Init()){
		
		printf("MPU6050 ERROR! \r\n");
	}
	printf("MPU6050 Init OK!\r\n");
	while(mpu_dmp_init()){
	
		printf("MPU6050_MDP_Init ERROR! \r\n");
	}
	printf("MPU6050 MDP OK!\r\n");
	
  /* Infinite loop */
  for(;;)
  {

		test_task_1();
		
    osDelay(500);
  }
  /* USER CODE END Start_Task_i */
}

/* USER CODE BEGIN Header_Start_Task_2 */
/**
* @brief Function implementing the Task_2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Task_2 */
void Start_Task_2(void const * argument)
{
  /* USER CODE BEGIN Start_Task_2 */
  /* Infinite loop */
  for(;;)
  {
		
		test_task_2();
		
    osDelay(100);
  }
  /* USER CODE END Start_Task_2 */
}

/* USER CODE BEGIN Header_Start_Task_3 */
/**
* @brief Function implementing the Task_3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_Task_3 */
void Start_Task_3(void const * argument)
{
  /* USER CODE BEGIN Start_Task_3 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(100);
  }
  /* USER CODE END Start_Task_3 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
