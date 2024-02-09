# MPS2-AN835 FreeRTOS

Setup a FreeRTOS project on a emulated mps2-an835 board and run some simple tasks.

## How to use FreeRTOS

In order to use FreeRTOS we need to compile the FreeRTOS source code and link it with our main code.

The core RTOS code is contained in three files:
- `tasks.c`
- `queue.c`
- `list.c`

those files can be found in `FreeRTOS/FreeRTOS/Source` directory.

Each processor architecture require a small amount of architecture specific RTOS code. This is the RTOS portable layer, and it is located in the `FreeRTOS/FreeRTOS/Source/portable/[compiler]/[architecture]` directory. In our case the architecture is `ARM_CM3` and the compiler is `GCC`.

The memory management files are located in the `FreeRTOS/FreeRTOS/Source/portable/MemMang` and are called `heap_x.c`, we will use `heap_4.c` for our project.

In order to use FreeRTOS we need to include the `FreeRTOSCOnfig.h` file in our project, this file will contain the configuration of the RTOS.

## Compile

Everything needed to build the project is in the build directory

To compile the project run this command in the build directory 

```bash
make
```

to run the project on QEMU use this command instead

```bash
make qemu
```

to clear all build artifacts run

```bash
make clean
```