# MemMang Test

This is a test of the memory manager. It is a simple program that allocates and frees memory in a variety of ways. It is designed to test the memory manager's ability to handle a variety of memory allocation and reallocation scenarios.

## Testing

In this test we will be testing the following functions:

- `malloc` (best-fit)
- `malloc` (worst-fit)
- `realloc`

To run the test, simply run the following command:

For **best-fit**:

```bash
make test-bestfit
```

For **worst-fit**:

```bash
make test-worstfit
```

For **realloc**:

```bash
make test-realloc
```
