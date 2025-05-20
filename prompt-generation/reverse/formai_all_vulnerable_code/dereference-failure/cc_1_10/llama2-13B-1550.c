//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

void reverse_words(char *str) {
  char *p, *q, *r;
  int len = strlen(str);

  p = str;
  q = str + len - 1;
  r = p;

  while (p < q) {
    char temp = *p;
    *p = *q;
    *q = temp;
    p++;
    q--;
  }
}

int main() {
  char str[MAX_LENGTH];
  int i, j, k;

  printf("Enter a string: ");
  fgets(str, MAX_LENGTH, stdin);

  reverse_words(str);

  for (i = 0; i < strlen(str); i++) {
    if (str[i] == ' ' || str[i] == '\n') {
      j = i;
      while (j > 0 && str[j - 1] == ' ') {
        j--;
      }
      k = j;
      while (k < i && str[k] == ' ') {
        k++;
      }
      str[i] = str[k];
      str[k] = str[j];
    }
  }

  printf("Reversed string: %s\n", str);

  return 0;
}