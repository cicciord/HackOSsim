# QEMU demo

Make a demo application where multiple tasks are created and show how the scheduling is handled with same priorities.
Here, Round Robin is used so tasks that share a priority take turns entering the Running state
## Compile

Everything needed to build the project is in the build directory

To compile the project go in the build directory

```bash
cd build/gcc
```

and run this command

```bash
make
```

to run the project on QEMU

```bash
make qemu
```
