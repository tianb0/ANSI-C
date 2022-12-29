#include <stdio.h>

/* echo char input */
int main() {
  int ch;  /* EOF is an int */
  while ( (ch = getchar()) != EOF)
    putchar(ch);
}
