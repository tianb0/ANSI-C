// sort lines

#include <stdio.h>
#include <string.h>

// max #lines to be sorted
#define MAXLINES 5000

// pointer to lines
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qksort(char *lineptr[], int left, int right);

int main() {
  // number of input lines read
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qksort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

// max length of any input line
#define MAXLEN 1000
int getline_(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline_(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      /* printf("will return %d %p \n", len, p); */
      return -1; // error
    }
    else {
      line[len - 1] = '\0'; // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

// writelines: write output lines
void writelines(char *lineptr[], int nlines) {
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

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
    /* printf("should return %p\n", allocp - n); */
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

/* getLine: get line into s, return length */
int getline_(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

// sort v[left]...v[right] into increasing order
void qksort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qksort(v, left, last - 1);
  qksort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
