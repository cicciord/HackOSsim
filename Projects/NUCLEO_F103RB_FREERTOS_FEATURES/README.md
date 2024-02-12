# NUCLEO-F103RB FreeRTOS Feature

This project implements a basic application on the NUCLEO-F103RB board using FreeRTOS as a real-time operating system. The application is designed to initialize a FreeRTOS instance with two basic tasks, demonstrating the behavior of the scheduler with different system configuration settings and task priorities.

- [How it works](#how-it-works)
  - [Timer](#timer)
  - [Task TX](#task-tx)
  - [Task RX](#task-rx)
- [Requirements](#requirements)
- [Usage](#usage)
  - [Run Simulation](#run-simulation)
  - [Compile](#compile)
  - [Debug](#debug)
    - [Command Line](#command-line)
    - [Visual Studio Code](#visual-studio-code)
  - [Clean](#clean)

A **NUCLEO-F103RB** board simulated on QEMU is used.

## How it works

 This project demonstrates the interaction of tasks with semaphores, queues, and timers in the FreeRTOS environment.

 <!-- Draw schema of the exercise -->

### Timer

The **timer** is set to expire periodically every 1000 milliseconds. When the timer expires, it calls the callback function, which _gives_ the **semaphore**.

### Task TX

The TX task is waiting for the **semaphore**. When the semaphore is given, the TX task _takes_ the semaphore and a value to the **queue**. The value sent is a counter that is incremented each loop.

### Task RX

The RX task is waiting for an item in the **queue**. When an item arrives in the queue, the RX task receives it and prints the received value and the current tick count.

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