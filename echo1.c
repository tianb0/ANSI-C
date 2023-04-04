#include <stdio.h>

// echo
int main(int argc, char *argv[]) {
  int i;

  for (i = 1; i < argc; i++)
    printf((argc > 1) ? "%s " : "%s", *++argv);
  printf("\n");
}
