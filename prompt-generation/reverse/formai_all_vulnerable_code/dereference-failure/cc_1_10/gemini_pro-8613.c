//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  int a, b, c;
  float d, e, f;
  char *s1, *s2;

  a = 10;
  b = 20;
  c = 30;
  d = 40.0;
  e = 50.0;
  f = 60.0;
  s1 = "Hello";
  s2 = "World";

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %f\n", d);
  printf("e = %f\n", e);
  printf("f = %f\n", f);
  printf("s1 = %s\n", s1);
  printf("s2 = %s\n", s2);

  a += 10;
  b -= 10;
  c *= 10;
  d /= 10.0;
  e *= 10.0;
  f /= 10.0;
  s1 = (char *) malloc(strlen(s1) + 10);
  s2 = (char *) malloc(strlen(s2) + 10);

  strcpy(s1, "Hello World");
  strcpy(s2, "World Hello");

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %f\n", d);
  printf("e = %f\n", e);
  printf("f = %f\n", f);
  printf("s1 = %s\n", s1);
  printf("s2 = %s\n", s2);

  a++;
  b--;
  c = c + 1;
  d = d + 1.0;
  e = e - 1.0;
  f = f - 1.0;
  s1 = (char *) realloc(s1, strlen(s1) + 1);
  s2 = (char *) realloc(s2, strlen(s2) + 1);

  strcat(s1, "!");
  strcat(s2, "?");

  printf("a = %d\n", a);
  printf("b = %d\n", b);
  printf("c = %d\n", c);
  printf("d = %f\n", d);
  printf("e = %f\n", e);
  printf("f = %f\n", f);
  printf("s1 = %s\n", s1);
  printf("s2 = %s\n", s2);

  free(s1);
  free(s2);

  return 0;
}