#include <stdint.h>
#include <stdio.h>

/* printf() output uses the UART.  These constants define the addresses of the
required UART registers. */
#define UART0_ADDRESS (0x40004000UL)
#define UART0_DATA (*(((volatile uint32_t *)(UART0_ADDRESS + 0UL))))
#define UART0_STATE (*(((volatile uint32_t *)(UART0_ADDRESS + 4UL))))
#define UART0_CTRL (*(((volatile uint32_t *)(UART0_ADDRESS + 8UL))))
#define UART0_BAUDDIV (*(((volatile uint32_t *)(UART0_ADDRESS + 16UL))))
#define TX_BUFFER_MASK (1UL)

/*
 * Printf() output is sent to the serial port.  Initialise the serial hardware.
 */
static void prvUARTInit(void);

void main(void) {
  prvUARTInit();

  printf("Hello, World!");
  for (;;)
    ;
}

static void prvUARTInit(void) {
  UART0_BAUDDIV = 16;
  UART0_CTRL = 1;
}
