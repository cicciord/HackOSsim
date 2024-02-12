# Custom FreeRTOS Features

_Go back to the [main page](../README.md)_

This project implements a custom memory manager for FreeRTOS. The implementation adds some features to the default FreeRTOS `heap_4.c` memory manager. The features are: **best-fit** and **worst-fit** memory allocation strategies, and a **realloc** function.

- [Best-fit](#best-fit)
- [Worst-fit](#worst-fit)
- [Realloc](#realloc)
- [usage](#usage)
  - [Configuration](#configuration)
- [Testing](#testing)

## Best-fit

FreeRTOS uses a first-fit memory allocation strategy. This means that the first block of memory that is large enough to satisfy the request is used. The best-fit strategy, on the other hand, searches the entire heap for the smallest block of memory that is large enough to satisfy the request. This strategy is generally slower than first-fit, but it can lead to less fragmentation and more efficient use of memory.

FreeRTOS handles free memory blocks in a linked list. To find the first block of memory that is large enough to satisfy the request, the list is traversed until a block is found. The best-fit strategy requires traversing the entire list, checking each block whether the difference between the requested size and the block size is the smallest so far. This is done by traversing the list and keeping track of the smallest difference found so far.

## Worst-fit

The worst-fit strategy is the opposite of the best-fit strategy. It searches the entire heap for the largest block of memory that is large enough to satisfy the request.

## Realloc

The `realloc` function changes the size of a previously allocated memory block. The realloc implementation provided accepts a pointer to a previously allocated memory block and a new size.

In case the pointer is a null pointer, the function behaves like `malloc` and allocates a new block of memory with the given size.

In case the size is zero, the function behaves like `free` and deallocates the memory block.

In case the pointer is not a null pointer and the size is not zero, the function allocates a new block of memory with the given size, copies the contents of the old block to the new block, and deallocates the old block.

## Usage

In order to use the custom memory manager, the `heap_4.c` provided must be compiled instead of the default `heap_4.c` provided by FreeRTOS.

### Configuration

The custom memory manager can be configured by defining configHEAP_ALLOCATION_TYPE in the `FreeRTOSConfig.h` file:

- `configHEAP_ALLOCATION_TYPE` = 0: First-fit memory allocation (default)
- `configHEAP_ALLOCATION_TYPE` = 1: Best-fit memory allocation
- `configHEAP_ALLOCATION_TYPE` = 2: Worst-fit memory allocation

## Testing

The custom memory manager is tested in the `Test` directory. Follow this [link](../Test/README.md) to see how to run the tests.