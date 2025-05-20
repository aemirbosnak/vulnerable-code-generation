//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matrix_operations(int **a, int **b, int **c) {
  int i, j, k;
  int rows_a = *a;
  int cols_a = **a;
  int rows_b = *b;
  int cols_b = **b;
  int rows_c = rows_a + rows_b - 1;
  int cols_c = cols_a + cols_b - 1;

  *c = (int *)malloc(rows_c * cols_c * sizeof(int));

  for (i = 0; i < rows_c; i++) {
    for (j = 0; j < cols_c; j++) {
      c[i][j] = 0;
      for (k = 0; k < rows_a && k < cols_b; k++) {
        if (a[k][0] == b[0][k]) {
          c[i][j] += a[k][1] * b[1][k];
        }
      }
    }
  }
}

int main() {
  int a_rows = 3;
  int a_cols = 2;
  int b_rows = 2;
  int b_cols = 2;
  int c_rows = a_rows + b_rows - 1;
  int c_cols = a_cols + b_cols - 1;

  int **a = (int **)malloc(a_rows * sizeof(int *));
  for (int i = 0; i < a_rows; i++) {
    a[i] = (int *)malloc(a_cols * sizeof(int));
  }

  int **b = (int **)malloc(b_rows * sizeof(int *));
  for (int i = 0; i < b_rows; i++) {
    b[i] = (int *)malloc(b_cols * sizeof(int));
  }

  int **c = (int **)malloc(c_rows * sizeof(int *));
  for (int i = 0; i < c_rows; i++) {
    c[i] = (int *)malloc(c_cols * sizeof(int));
  }

  matrix_operations(&a, &b, &c);

  for (int i = 0; i < c_rows; i++) {
    for (int j = 0; j < c_cols; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}