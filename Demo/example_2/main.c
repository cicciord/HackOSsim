/// TODO: Make a demo application where multiple tasks are created and show how the scheduling is handled with same or different priorities.
//In this first example , two task has got the same priority , Freertos use  "Round-robin" which means that tasks that share a priority take turns entering the Running state
#include <stdint.h>
#include <stdio.h>
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "list.h"

//Task handle
TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

// Task stack sizes 
#define TASK_STACK_SIZE  520

/* Task priorities. */
#define TASK1_PRIORITY			  ( tskIDLE_PRIORITY + 4 )
#define TASK2_PRIORITY            ( tskIDLE_PRIORITY + 4 )

void vTaskFunction1(void *params);
void vTaskFunction2(void *params);

/* printf() output uses the UART.  These constants define the addresses of the
required UART registers. */
#define UART0_ADDRESS (0x40004000UL)
#define UART0_DATA (*(((volatile uint32_t *)(UART0_ADDRESS + 0UL))))
#define UART0_STATE (*(((volatile uint32_t *)(UART0_ADDRESS + 4UL))))
#define UART0_CTRL (*(((volatile uint32_t *)(UART0_ADDRESS + 8UL))))
#define UART0_BAUDDIV (*(((volatile uint32_t *)(UART0_ADDRESS + 16UL))))
#define TX_BUFFER_MASK (1UL)

/*
 * Printf() output is sent to the serial port.  Initialise the serial hardware.
 */
static void prvUARTInit(void);

void main(void) {
	
  prvUARTInit();

  xTaskCreate(vTaskFunction1,"Task-1",TASK_STACK_SIZE,NULL,TASK1_PRIORITY,&xTaskHandle1);
  xTaskCreate(vTaskFunction2,"Task-2",TASK_STACK_SIZE,NULL,TASK2_PRIORITY,&xTaskHandle2);
  
  /* Start the scheduler. */
	vTaskStartScheduler();


}

static void prvUARTInit(void) {
  UART0_BAUDDIV = 16;
  UART0_CTRL = 1;
}

//Task 1 function
void vTaskFunction1(void *params){
	(void)params; // Evita il warning "unused parameter"

	for(;;){

		printf("hello from task 1");

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

//Task 2 function
void vTaskFunction2(void *params){
	(void)params; // Evita il warning "unused parameter"

	for(;;){

		printf("hello from task 2");

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}