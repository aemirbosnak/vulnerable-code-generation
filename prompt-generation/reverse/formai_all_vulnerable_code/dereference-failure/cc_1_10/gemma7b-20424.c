//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **a, int **b) {
  int i, j, k = 0, l = 0, count = 0;
  char **c = (char **)malloc(MAX);

  for (i = 0; i < MAX; i++) {
    c[i] = NULL;
  }

  for (i = 0; i < **a; i++) {
    count = 1;
    for (j = i + 1; j < **a && a[i] == a[j]; j++) {
      count++;
    }

    if (count > 1) {
      c[k++] = a[i];
      c[k++] = count;
    } else {
      c[k++] = a[i];
    }
  }

  *b = k;
  *a = c;
}

int main() {
  char **a = (char **)malloc(MAX);
  int **b = (int *)malloc(MAX);

  a[0] = 'a';
  a[1] = 'a';
  a[2] = 'b';
  a[3] = 'b';
  a[4] = 'c';

  compress(a, b);

  printf("Number of bytes compressed: %d", *b);
  printf("\nCompressed data:");
  for (int i = 0; i < *b; i++) {
    printf(" %c", a[i]);
  }

  return 0;
}