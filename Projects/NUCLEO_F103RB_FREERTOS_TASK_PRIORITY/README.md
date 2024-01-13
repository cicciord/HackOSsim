# NUCLEO-F103RB FREERTOS TASK PRIORITY

This project implements 2 simple task on FreeRTOS to show how the scheduler behaves using different settings for the OS configuration and task priorities. 

- [Requirements](#requirements)
- [Usage](#usage)
    - [Run Simulation](#run-simulation)
    - [Compile](#compile)
    - [Debug](#debug)
        - [Command Line](#command-line)
        - [Visual Studio Code](#visual-studio-code)
    - [Clean](#clean)
- [TUTORIAL](#tutorial)

A **NUCLEO-F103RB** board simulated on QEMU is used.

## Requirements

To run the project you need the following requirements:

- **xPack QEMU**
- **Arm GNU Toolchian**

_refer to the [tutorial section](../../docs/qemu.md) to the guide on how to install those packages._

## Usage

### Run Simulation

To compile the project run this command in the **NUCLEO_F103RB_FREERTOS_TASK_PRIORITY** directory

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
arm-none-eabi-gdb build/NUCLEO_F103RB_FREERTOS_TASK_PRIORITY.elf -ex "target remote localhost:1234"
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

## TUTORIAL

The project is initialized with 2 task, each one prints a message in the console (_Hello from Task x_). Each task has equal priority and the scheduler is set to preemptive mode. A delay is added to each task, so it prints a message each second.

Run the project with the command `make qemu` to see the outcome.

You will see this in the console

```bash
Hello from Task 1
Hello from Task 2
Hello from Task 1
Hello from Task 2
...
```

To stop the simulation write 'q' and press Enter.

As you noticed each task is executed in a round-robin way as expected.

### Disable Preemprion

Now open the `ProjectConfig.h` file and set _USE_PREEMPTION_ to 0.

Run again the project.

Nothing changes. That's not what we would expected. If the scheduler does not use preemption when a task is executed it will not be stopped until it finishes its execution. Thus being our task infinite, _task 1_ should run forever and _task 2_ should never be executed.

This does not happens because we added a delay in our tasks. Thus after the print, each task is suspended for a second. The scheduler then execute the other task in the ready list.

Now go back in the `ProjectConfig.h` file and set _TASK_1_DELAY_ENABLE_ to 0, do the same for task 2.

Run again the project.

You should observe something like this

```bash
Hello from Task 1
Hello from Task 1
Hello from Task 1
Hello from Task 1
...
```

This is what we expected.

### Change Priority

Now set in `ProjectConfig.h` _PRIORITY_TASK_2_ to 3. We are ginving _task 2_ a higer priority then _task 1_.

Run again the project.

```bash
Hello from Task 2
Hello from Task 2
Hello from Task 2
Hello from Task 2
...
```

You can observe that now _task 2_ is executed forever and _task 1_ gets never executed.

You can also try to enable back the preemption, nothing will change since _task 2_ now has a higer priority.