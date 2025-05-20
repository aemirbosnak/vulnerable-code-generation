//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(int **a, int n) {
  int i, j, k, l, count = 0, t = 0, b[MAX], *c = NULL;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] != 0) {
        count++;
      }
    }
  }

  c = malloc(count * sizeof(int));

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] != 0) {
        b[t++] = a[i][j];
      }
    }
  }

  for (i = 0; i < count; i++) {
    c[i] = b[i];
  }

  free(a);
  a = NULL;

  printf("Compressed size: %d\n", count);

  for (i = 0; i < count; i++) {
    printf("%d ", c[i]);
  }

  printf("\n");
}

int main() {
  int **a = NULL;
  int n = 5;

  a = malloc(n * n * sizeof(int));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % 2;
    }
  }

  compress(a, n);

  return 0;
}