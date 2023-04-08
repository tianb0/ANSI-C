#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
  char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

union u_tag {
  int ival;
  float fval;
  char *sval;
} u;

// bit fields

/* #define KEYWORD 01 */

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

struct {
  unsigned int is_keyword : 1;
  unsigned int is_extern : 1;
  unsigned int is_static : 1;
} flags;
