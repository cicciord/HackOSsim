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
#include "queue.h"
#include "timers.h"
#include "semphr.h"
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SEMPHR_TASK_PRIO  ( configMAX_PRIORITIES - 1 )  /* semaphore has maximum priority */
#define TASK_TX_PRIO      ( tskIDLE_PRIORITY + 1 )
#define TASK_RX_PRIO      ( tskIDLE_PRIORITY + 2 )

#define TIMER_PERIOD_MS   pdMS_TO_TICKS( 1000 )
#define QUEUE_LEN         ( 1 )

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
SemaphoreHandle_t xSemphr = NULL;
TimerHandle_t xTimer = NULL;
QueueHandle_t xQueue = NULL;
TaskHandle_t xTaskTX = NULL;
TaskHandle_t xTaskRX = NULL;

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void prvSemphrTask( void *pvParams );
void vTimerCallback( TimerHandle_t xTimer );
void prvTaskTX( void *pvParams );
void prvTaskRX( void *pvParams );

/* USER CODE END FunctionPrototypes */

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  printf("Start Exercise\n\r");

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  xSemphr = xSemaphoreCreateBinary();
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  xTimer = xTimerCreate(  ( const char * ) "Timer",
                          TIMER_PERIOD_MS,
                          pdTRUE,
                          ( void * ) 0,
                          vTimerCallback  );
  xTimerStart( xTimer, 0 );
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /// TODO: change type whene decide what values to pass
  xQueue = xQueueCreate(  QUEUE_LEN,
                          sizeof( uint32_t ) );
  /* USER CODE END RTOS_QUEUES */

  /* USER CODE BEGIN RTOS_TASKS */
  xTaskCreate(  prvTaskTX,
                "Task-TX",
                configMINIMAL_STACK_SIZE,
                NULL,
                TASK_TX_PRIO,
                &xTaskTX );

  xTaskCreate(  prvTaskRX,
                "Task-RX",
                configMINIMAL_STACK_SIZE,
                NULL,
                TASK_RX_PRIO,
                &xTaskRX );
  /* USER CODE END RTOS_TASKS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void vTimerCallback( TimerHandle_t xTimer )
{
  xSemaphoreGive( xSemphr );
}

void prvTaskTX( void *pvParams )
{
  uint32_t uwConut = 0UL;
  for(;;)
  {
    xSemaphoreTake( xSemphr, portMAX_DELAY );
    xQueueSend( xQueue, &uwConut, 0 );
    uwConut++;
  }
}

void prvTaskRX( void *pvParams )
{
  TickType_t xTick;
  uint32_t uwValueReceived;
  for(;;)
  {
    xQueueReceive( xQueue, &uwValueReceived, portMAX_DELAY );
    xTick = xTaskGetTickCount();
    printf("%03lu - Tick Count: %lu\n\r", uwValueReceived, xTick);
  }
}

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

