//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication(int **a, int **b, int **c, int n) {
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
  int n = 3;
  int **a = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
  }
  a[0][0] = 1;
  a[1][1] = 2;
  a[2][2] = 3;

  int **b = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    b[i] = (int *)malloc(n * sizeof(int));
  }
  b[0][0] = 2;
  b[1][1] = 3;
  b[2][2] = 4;

  int **c = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    c[i] = (int *)malloc(n * sizeof(int));
  }

  matrix_multiplication(a, b, c, n);

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