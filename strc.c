// copy t to s
void strc(char *s, char *t) {
  while (*s++ = *t++) // while ((*s++ = *t++) != '\0')
    ;
}

// returns negative, zero or positive if s is lexicographically less than, equal to, or greater than 0
int strcmp1(char *s, char *t) {
  for (; *s == *t; s++, t++) 
    if (*s == '\0')
      return 0;
  return *s - *t;
}
