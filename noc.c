#include <stdio.h>

/* count characters in input */
int main() {
  long nc; /* int is around 32k if it's 16 bit which is too small while long can
              be 2 billion if it's 32 bit */
  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n", nc);
}
