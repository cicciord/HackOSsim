# MPS2-AN835 Hello World

Run a Hello World program on a emulated mps2-an835 board.

## How it works
To use a cortex-m3 processor we need to compile a startup file and a linker script. Those two can be found in the build directory (`startup_gcc.c` and `mps2_m3.ld`).

The startup file is a simple file that sets up the stack pointer, the ISR vector and calls the main function.

The linker script is a file that tells the linker where to put the different sections of the program in memory.

The main code is developed in `main.c` and is a simple program that prints "Hello World" to the console.

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