#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

/*-----------------------------------------------------------
 * Configuration parameters for the project.
 * Change them in order to experiment different behaviours of
 * the scheduler
 *----------------------------------------------------------*/

#define USE_PREEMPTION          1       // Scheduler uses preemption
#define PRIORITY_TASK_1         2       // Task 1 priority value
#define PRIORITY_TASK_2         2       // Task 2 priority value
#define TASK_1_DELAY_ENABLE     1       // Enable delay for task 1
#define TASK_2_DELAY_ENABLE     1       // Enable delay for task 2
#define TASK_1_DELAY_VALUE      1000    // Delay of task 1 in ms
#define TASK_2_DELAY_VALUE      1000    // Delay of task 2 in ms

#endif

