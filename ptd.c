#include <stdio.h>

/* printd: print n in decimal */
void printd(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}

int main() {
  int i;
  scanf("%d", &i);
  printd(i);
}
