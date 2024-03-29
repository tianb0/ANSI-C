// cat1: concatenate files, v1
#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1)
    // no args, copy standard input
    filecopy(stdin, stdout);
  else {
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
        printf("cat: can't open %s\n", *argv);
        return 1;
      } else {
        filecopy(fp, stdout);
        fclose(fp); // also flush buffer
      }
  }
  return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
  int c;
  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
