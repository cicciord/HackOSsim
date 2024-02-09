# Demo and Projects

_Go back to the [main page](../README.md)_

This section is dedicated on using QEMU and FreeRTOS to develope embedded projects.

- [demo](#demo)
    - [example 1](#example-1)
    - [example 2](#example-2)
- [Projects](#projects)
    - [LED Blink](#led-blink)
    - [Tasks Priority](#tasks-priority)

## Demo

Two demo have been developed with the focus on how to use QEMU and set up a project, with and without FreeRTOS.

The first demo is focused on how to emulate a board and execute some simple code on it; the second one will also integrate FreeRTOS.

The following demo can be found in the folder [Demo](../Demo/).

### example 1

This example shows what is needed to emulate a board and get it up and running. It simply prints a "Hello, World!" message on the screen.

A complete description is given [here](../Demo/example_1/README.md)

### example 2

This example instead aims to show how to include FreeRTOS in a project and create some simple task. This exercise wants to show what are the files needed for FreeRTOS to work and how to include them.

A complete description is given [here](../Demo/example_2/README.md)

## Projects

Projects developed are thought to show a more realistic example. For this reason a NUCLEO-F103RB board has been choosen, since is a very common and easy to find board. The project has been initialized with STM32CubeMX, a software provided by STM which generate the initialization code for a board provided some initial configutation.  

Also in this projects a fork of QEMU is used, xPaxk QEMU, which as a complete implementation of a wide range of boards, included the NUCLEO-F103RB. This gives the possibility to emulate the board and also have a nice graphic view of the board.

The following projects can be found in the folder [Projects](../Projects/).

### LED Blink

The LED Blink projects objective is to show how to use the Hardware Abstraction Layer (HAL) to interact with hardware components. Here a simple task is create which blinks a LED, the LED is choosen since the result can be easly visualized on screen.

A complete description is given [here](../Projects/NUCLEO_F103RB_FREERTOS_BLINK_LED/README.md)

### Tasks Priority

This Project wants to show how the scheduler handles different tasks based on the priority assigned and the FreeRTOS configuration. The [example 2](#example-2) is copied here, but a walk-through on changing different parameters to experiment different scheduler behaviours is provided.

A complete description is given [here](../Projects/NUCLEO_F103RB_FREERTOS_TASK_PRIORITY/README.md)
