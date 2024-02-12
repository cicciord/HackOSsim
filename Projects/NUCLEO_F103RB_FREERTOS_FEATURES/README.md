# NUCLEO-F103RB FreeRTOS Feature

This project implements a basic application on the NUCLEO-F103RB board using FreeRTOS as a real-time operating system. The application is designed to initialize a FreeRTOS instance with two basic tasks, demonstrating the behavior of the scheduler with different system configuration settings and task priorities.

## Table of Contents

- [NUCLEO-F103RB FreeRTOS Feature](#nucleo-f103rb-freertos-feature)
  - [Table of Contents](#table-of-contents)
  - [Requirements](#requirements)
  - [Usage](#usage)
    - [Run Simulation](#run-simulation)
    - [Compile](#compile)
    - [Debug](#debug)
      - [Command Line](#command-line)
      - [Visual Studio Code](#visual-studio-code)
    - [Clean](#clean)
  - [How it works](#how-it-works)
    - [Initialization](#initialization)
    - [Timer](#timer)
    - [Task TX](#task-tx)
    - [Task RX](#task-rx)
    - [Memory Management](#memory-management)

A **NUCLEO-F103RB** board simulated on QEMU is used.

## Requirements

To run the project you need the following requirements:

- **xPack QEMU**
- **Arm GNU Toolchian**

_refer to the [tutorial section](../../docs/qemu.md) to the guide on how to install those packages._

## Usage

### Run Simulation

To compile the project run this command in the **NUCLEO_F103RB_FREERTOS_FEATURES** directory

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
arm-none-eabi-gdb build/NUCLEO_F103RB_FREERTOS_FEATUERS.elf -ex "target remote localhost:1234"
```

#### Visual Studio Code

To have a nice interface to debug the project you can use the extension for C/C++ for VS Code.

Run this command to set the project

```bash
cp -R .vscode.example .vscode
```

You might need to change some fields in `.vscode/launch.json` and `.vscode/tasks.json` according to your system.

### Clean

To clean all the build files run

```bash
make clean
```

## How it works

 This project demonstrates the interaction between semaphores, queues, and tasks in the FreeRTOS environment. The timer periodically expires and gives a semaphore. When the semaphore is given, the TX task sends a value to the queue. The RX task, waiting for an item in the queue, receives the value and prints it. This process repeats continuously.

### Initialization 

The MX_FREERTOS_Init function is called to initialize the necessary data structures. It creates a binary semaphore *(xSemphr)*, a timer *(xTimer)*, a queue *(xQueue)*, and two tasks *(prvTaskTX* and *prvTaskRX)*.

### Timer

The timer is set to expire every 1000 milliseconds (defined by *TIMER_PERIOD_MS*). When the timer expires, it calls the callback function vTimerCallback, which in turn gives the semaphore *(xSemaphoreGive)*.

### Task TX

The TX task *(prvTaskTX)* is waiting for the semaphore. When the semaphore is given, the TX task takes the semaphore *(xSemaphoreTake)* and sends a value to the queue *(xQueueSend)*. The value sent is a counter that is incremented each loop.

### Task RX

The RX task *(prvTaskRX)* is waiting for an item in the queue. When an item arrives in the queue, the RX task receives it *(xQueueReceive)* and prints the received value and the current tick count.

### Memory Management

The functions *vApplicationGetIdleTaskMemory* and *vApplicationGetTimerTaskMemory* are used to provide static memory for the idle task and the timer task, respectively. These functions are invoked when *configSUPPORT_STATIC_ALLOCATION* is set to 1, indicating that static memory allocation is enabled.