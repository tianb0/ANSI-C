/* pointer and array */
#include <stdio.h>

/* strlen: return length of string s */
int strl(char *s) {
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

int main() {
  int a[10];
  int *pa;
  pa = &a[0];

  // strlen

  int l1 = strl("hello, world");

  char arr[] = "123";
  int l2 = strl(arr);

  printf("l1 %d, l2 %d\n", l1, l2);;
}
