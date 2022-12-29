#include <stdio.h>

#define    LOWER   0      /* lower limit of table */
#define    UPPER   300    /* upper limit of table */
#define    STEP    20     /* step size */

/* print Fahrenheit-Celsius table */
int main() {
  printf("%3c %6c\n", 'F', 'C');
  for (int fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
