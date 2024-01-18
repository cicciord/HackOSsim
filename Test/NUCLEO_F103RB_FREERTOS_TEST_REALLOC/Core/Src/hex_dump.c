/*
 *   This function prints hex dump of memory specified as a pointer.
 *   Reference: http://stackoverflow.com/questions/7775991/how-to-get-hexdump-of-a-structure-data
 */ 
#include <stdio.h>

void hexDump(char *desc, void *addr, int len)
{
  int i;
  unsigned char buff[9];
  unsigned char *pc = (unsigned char*)addr;

  // Output description if given.
  if (desc != NULL)
    printf ("%s:\n", desc);

  // print header
  printf(" offset b0 b1 b2 b3 b4 b5 b6 b7   ASCII\n");

  // Process every byte in the data.
  for (i = 0; i < len; i++) {
    // Multiple of 8 means new line (with line offset).
    if ((i % 8) == 0) {
      // Just don't print ASCII for the zeroth line.
      if (i != 0)
        printf ("  %s\n", buff);

      // Output the offset.
      printf ("  %04x ", i);
    }

    // Now the hex code for the specific character.
    printf (" %02x", pc[i]);

    // And store a printable ASCII character for later.
    if ((pc[i] < 0x20) || (pc[i] > 0x7e))
      buff[i % 8] = '.';
    else
      buff[i % 8] = pc[i];
    buff[(i % 8) + 1] = '\0';
  }

  // Pad out last line if not exactly 8 characters.
  while ((i % 8) != 0) {
    printf ("   ");
    i++;
  }

  // And print the final ASCII bit.
  printf ("  %s\n", buff);
}
