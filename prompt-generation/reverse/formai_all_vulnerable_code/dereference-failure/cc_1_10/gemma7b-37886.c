//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void matrix_transposition(int **a, int n) {
  int i, j, k;
  int **b = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    b[i] = (int *)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++) {
        b[j][k] = a[k][i];
      }
    }
  }

  free(a);
  free(b);
}

int main() {
  int n = 3;
  int **a = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
  }

  a[0][0] = 1;
  a[0][1] = 2;
  a[0][2] = 3;
  a[1][0] = 4;
  a[1][1] = 5;
  a[1][2] = 6;
  a[2][0] = 7;
  a[2][1] = 8;
  a[2][2] = 9;

  matrix_transposition(a, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  free(a);
  return 0;
}