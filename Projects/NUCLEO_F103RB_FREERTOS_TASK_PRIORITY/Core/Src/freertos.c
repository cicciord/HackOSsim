/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "ProjectConfig.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TASK1_PRIO  (tskIDLE_PRIORITY + PRIORITY_TASK_1)
#define TASK2_PRIO  (tskIDLE_PRIORITY + PRIORITY_TASK_2)

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void vTask1_handler(void *argument);
void vTask2_handler(void *argument);

/* USER CODE END FunctionPrototypes */

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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

  /* USER CODE BEGIN RTOS_TASKS */
  xTaskCreate(  vTask1_handler,
                "Task-1",
                configMINIMAL_STACK_SIZE,
                NULL,
                TASK1_PRIO,
                &xTaskHandle1 );

  xTaskCreate(  vTask2_handler,
                "Task-2",
                configMINIMAL_STACK_SIZE,
                NULL,
                TASK2_PRIO,
                &xTaskHandle2 );
  /* USER CODE END RTOS_TASKS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_vTask1_handler */
/**
  * @brief  Function implementing a task that prints a string.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_vTask1_handler */
void vTask1_handler(void *argument)
{
  /* USER CODE BEGIN vTask1_handler */
  /* Infinite loop */
  for(;;)
  {
    printf("Hello from Task 1\n\r");
    #if ( TASK_1_DELAY_ENABLE )
      vTaskDelay(TASK_1_DELAY_VALUE);
    #endif
  }
  /* USER CODE END vTask1_handler */
}

/* USER CODE BEGIN Header_vTask2_handler */
/**
  * @brief  Function implementing a task that prints a string.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_vTask2_handler */
void vTask2_handler(void *argument)
{
  /* USER CODE BEGIN vTask2_handler */
  /* Infinite loop */
  for(;;)
  {
    printf("Hello from Task 2\n\r");
    #if ( TASK_2_DELAY_ENABLE )
      vTaskDelay(TASK_2_DELAY_VALUE);
    #endif
  }
  /* USER CODE END vTask2_handler */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/*---------------------------------------------------------------------------*/

/* Callback function prototypes */
extern void vApplicationIdleHook (void);
extern void vApplicationTickHook (void);
extern void vApplicationMallocFailedHook (void);

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/*---------------------------------------------------------------------------*/

/* Callback function prototypes */
extern void vApplicationIdleHook (void);
extern void vApplicationTickHook (void);
extern void vApplicationMallocFailedHook (void);
extern void vApplicationDaemonTaskStartupHook (void);
extern void vApplicationStackOverflowHook (TaskHandle_t xTask, signed char *pcTaskName);

/**
  Dummy implementation of the callback function vApplicationIdleHook().
*/
#if (configUSE_IDLE_HOOK == 1)
__WEAK void vApplicationIdleHook (void){}
#endif

/**
  Dummy implementation of the callback function vApplicationTickHook().
*/
#if (configUSE_TICK_HOOK == 1)
 __WEAK void vApplicationTickHook (void){}
#endif

/**
  Dummy implementation of the callback function vApplicationMallocFailedHook().
*/
#if (configUSE_MALLOC_FAILED_HOOK == 1)
__WEAK void vApplicationMallocFailedHook (void){}
#endif

/**
  Dummy implementation of the callback function vApplicationDaemonTaskStartupHook().
*/
#if (configUSE_DAEMON_TASK_STARTUP_HOOK == 1)
__WEAK void vApplicationDaemonTaskStartupHook (void){}
#endif

/**
  Dummy implementation of the callback function vApplicationStackOverflowHook().
*/
#if (configCHECK_FOR_STACK_OVERFLOW > 0)
__WEAK void vApplicationStackOverflowHook (TaskHandle_t xTask, signed char *pcTaskName) {
  (void)xTask;
  (void)pcTaskName;
}
#endif

/*---------------------------------------------------------------------------*/

/* External Idle and Timer task static memory allocation functions */
extern void vApplicationGetIdleTaskMemory  (StaticTask_t **ppxIdleTaskTCBBuffer,  StackType_t **ppxIdleTaskStackBuffer,  uint32_t *pulIdleTaskStackSize);
extern void vApplicationGetTimerTaskMemory (StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize);

/* Idle task control block and stack */
static StaticTask_t Idle_TCB;
static StackType_t  Idle_Stack[configMINIMAL_STACK_SIZE];

/* Timer task control block and stack */
static StaticTask_t Timer_TCB;
static StackType_t  Timer_Stack[configTIMER_TASK_STACK_DEPTH];

/*
  vApplicationGetIdleTaskMemory gets called when configSUPPORT_STATIC_ALLOCATION
  equals to 1 and is required for static memory allocation support.
*/
void vApplicationGetIdleTaskMemory (StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) {
  *ppxIdleTaskTCBBuffer   = &Idle_TCB;
  *ppxIdleTaskStackBuffer = &Idle_Stack[0];
  *pulIdleTaskStackSize   = (uint32_t)configMINIMAL_STACK_SIZE;
}

/*
  vApplicationGetTimerTaskMemory gets called when configSUPPORT_STATIC_ALLOCATION
  equals to 1 and is required for static memory allocation support.
*/
void vApplicationGetTimerTaskMemory (StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize) {
  *ppxTimerTaskTCBBuffer   = &Timer_TCB;
  *ppxTimerTaskStackBuffer = &Timer_Stack[0];
  *pulTimerTaskStackSize   = (uint32_t)configTIMER_TASK_STACK_DEPTH;
}

/* USER CODE END Application */

