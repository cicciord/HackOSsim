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

The main.c file initializes peripherals, sets up a real-time operating system (RTOS) with multiple tasks, and demonstrates task management, inter-task communicataion, and synchronization mechanisms. The aim is to create a stable, efficient, and responsive system capable of handling concurrent tasks and time-critical operations.

The code initializes the MCU, clock system, GPIO, and USART. It includes the main function, which is the entry point of the program. The main function initializes the HAL library, sets up the clock system, initializes GPIO and USART, and starts the FreeRTOS scheduler. The SystemClock_Config function configures the system clock to use the High-Speed Internal (HSI) oscillator as the main clock source.

The MX_FREERTOS_Init function initializes FreeRTOS by creating tasks, semaphores, timers, and queues. The project includes two tasks, prvTaskTX and prvTaskRX, that handle sending and receiving data via USART, respectively. A binary semaphore and a queue are used for inter-task communication and synchronization. The transmit task sends the count value to the queue when the semaphore is given, and the receive task receives the new value from the queue and prints the tick count.

The system clock configuration is essential for the proper functioning of the embedded system. The SystemClock_Config function configures the system clock to a working state, which is necessary to ensure proper timing and synchronization of the microcontroller's internal peripherals and external devices. This is a crucial step in setting up any embedded system, as the clock system is responsible for controlling the timing of all the system's operations.   

