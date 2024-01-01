# NUCLEO-F103RB FREERTOS BLINK LED

This project use FreeRTOS to implement one task that blinks an LED each second.

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

### Clean

To clean all the build files run

```bash
make clean
```
