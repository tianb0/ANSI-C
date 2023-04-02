#include <stdio.h>

// size of available space
#define ALLOCSIZE 10000

// storage for alloc
static char allocbuf[ALLOCSIZE];

// next free position
static char *allocp = allocbuf;

// return pointer to n characters
char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {       // no enough space
    return NULL; // return 0
  }
}

// free storage pointed to by p
void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

// return length of string s
int strl(char *s) {
  char *p = s;
  while (*p != '\0')
    p++;
  return p - s;
}
