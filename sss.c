#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("len abc is %ld\n", strlen("abc"));

  system("date");

  void *p1 = malloc(200); // 200 byte
  printf("len p1 %ld, len *p1 %ld\n", sizeof(p1), sizeof(*p1));
  free(p1);

  int *p2 = calloc(4, sizeof(int));

  printf("len p2 %ld *p2 %ld\n", sizeof(p2), sizeof(*p2));
  free(p2);
}
