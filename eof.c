#include <stdio.h>

/* print the value of EOF */
int main() {
  printf("EOF: %d\n", EOF);
  printf("char == EOF ? %d\n", 'c' == EOF);
  printf("char != EOF ? %d\n", 'c' != EOF);
}
