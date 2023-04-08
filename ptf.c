// pointer to function

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

// lineptr is an array of char pointers
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qksort(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));

int numcmp(char *, char *);

int main(int argc, char *argv[]) {
  int nlines;
  int numberic = 0;

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numberic = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qksort((void **) lineptr, 0, nlines - 1,
    (int (*) (void *, void *))(numberic ? numcmp : strcmp)
  );
      writelines(lineptr, nlines);
    return 0;
  } else {
    return 1;
  }
}
