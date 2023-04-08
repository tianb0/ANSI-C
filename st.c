#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point p1;
  struct point p2;
};

struct point pt;

int main() {
  struct point pt2 = { 3, 4 };
  printf("x=%d, y=%d", pt.x, pt.y);
  printf("x=%d, y=%d", pt2.x, pt2.y);
}
