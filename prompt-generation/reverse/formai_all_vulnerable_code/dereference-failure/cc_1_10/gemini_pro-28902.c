//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *n, *b;
  int i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
  printf("Enter a number: ");
  scanf("%s", &n);
  printf("Enter the base of the number: ");
  scanf("%s", &b);
  i = atoi(n);
  j = atoi(b);
  if (j < 2 || j > 16) {
    printf("Invalid base");
    return 0;
  }
  k = i;
  l = 0;
  while (k > 0) {
    l++;
    k /= j;
  }
  m = 0;
  o = l;
  p = 0;
  q = 0;
  r = 0;
  s = 0;
  t = 0;
  u = 0;
  v = 0;
  w = 0;
  x = 0;
  y = 0;
  z = 0;
  while (i > 0) {
    k = i % j;
    m++;
    if (k < 10) {
      p = k + 48;
      printf("%c", p);
    } else {
      q = k + 87;
      printf("%c", q);
    }
    i /= j;
  }
  printf("\n");
  return 0;
}