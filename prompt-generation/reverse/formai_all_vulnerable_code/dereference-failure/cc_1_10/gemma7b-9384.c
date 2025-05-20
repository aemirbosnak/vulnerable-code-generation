//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void matrix_operations(int **a, int **b, int **c, int n) {
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main() {
  int n = 5;
  int **a = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
  }

  int **b = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    b[i] = (int *)malloc(n * sizeof(int));
  }

  int **c = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    c[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = rand() % MAX;
      b[i][j] = rand() % MAX;
    }
  }

  matrix_operations(a, b, c, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  free(c);

  return 0;
}