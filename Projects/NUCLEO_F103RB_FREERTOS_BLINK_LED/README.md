# NUCLEO-F103RB FREERTOS BLINK LED

This project implements a task on FreeRTOS to blink a LED on a NUCLEO-F103RB board.

- [NUCLEO-F103RB FREERTOS BLINK LED](#nucleo-f103rb-freertos-blink-led)
  - [Requirements](#requirements)
  - [Usage](#usage)
    - [Run Simulation](#run-simulation)
    - [Compile](#compile)
    - [Debug](#debug)
      - [Command Line](#command-line)
      - [Visual Studio Code](#visual-studio-code)
    - [Clean](#clean)
  - [TUTORIAL](#tutorial)
    - [Task Creation](#task-creation)
    - [LED Blinking Logic](#led-blinking-logic)
    - [Scheduler Initialization](#scheduler-initialization)
    - [Infinite Loop](#infinite-loop)
    - [Conclusion](#conclusion)

A **NUCLEO-F103RB** board simulated on QEMU is used.

## Requirements

To run the project you need the following requirements:

- **xPack QEMU**
- **Arm GNU Toolchian**

_refer to the tutorial section to the guide on how to install those packages._

## Usage

### Run Simulation

To compile the project run this command in the **NUCLEO_F103RB_FREERTOS_BLINK_LED** directory

```bash
make qemu
```

### Compile

If you just want to compile the project run

```bash
make
```

### Debug

#### Command Line

To debug the project from command line run this commands

```bash
make qemu-gdb
```

and in another terminal session

```bash
arm-none-eabi-gdb build/NUCLEO_F103RB_FREERTOS_BLINK_LED.elf -ex "target remote localhost:1234"
```

#### Visual Studio Code

To have a nice interface to debug the project you can use the extension for C/C++ for VS Code.

You might need to change the `.vscode/launch.json` and `.vscode/tasks.json` according to your system.

### Clean

To clean all the build files run

```bash
make clean
```

## TUTORIAL

The project is a simple example of using FreeRTOS to blink an LED on a NUCLEO-F103RB board.

### Task Creation

In the `main` function, a task named `Task-Blink-LED` is created using the `xTaskCreate` function. This task is associated with the `vTaskBlinkLED_handler` function, which contains the logic for toggling the LED.

### LED Blinking Logic

The `vTaskBlinkLED_handler` function, executed by the created task, contains a continuous loop that toggles the state of the LED pin (LD2_Pin) using `HAL_GPIO_TogglePin` every 1000 milliseconds (1 second) with `vTaskDelay(1000)`.

```c
void vTaskBlinkLED_handler(void *params)
{
  while(1) {
    HAL_GPIO_TogglePin(GPIOA, LD2_Pin);
    vTaskDelay(1000);
  }
}
```

### Scheduler Initialization

The FreeRTOS scheduler is started using `vTaskStartScheduler()`, allowing the created task to run.

```c
vTaskStartScheduler();
```

### Infinite Loop

Since the scheduler takes control, the `while(1)` loop in the `main` function is never reached, and the control is handed over to the FreeRTOS scheduler.

### Conclusion

The LED blinking mechanism is achieved through the continuous execution of the `vTaskBlinkLED_handler` task, which toggles the LED pin state at a regular interval. The scheduler ensures the task runs concurrently with other tasks in the FreeRTOS environment.
