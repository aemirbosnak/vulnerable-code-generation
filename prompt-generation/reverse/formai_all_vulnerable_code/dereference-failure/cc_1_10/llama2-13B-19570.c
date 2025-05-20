//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform matrix multiplication recursively
void recursive_mat_mult(int **mat1, int **mat2, int m1_rows, int m1_cols, int n1, int n2) {
  // Base case: When one of the matrices is a scalar
  if (n1 == 1 || n2 == 1) {
    int result[m1_cols];
    for (int i = 0; i < m1_cols; i++) {
      result[i] = mat1[0][i] * mat2[0][0];
    }
    printf("Product of two scalars: %d\n", result[0]);
    return;
  }

  // Recursive case: When both matrices are rectangular
  int result[m1_cols][n2];
  for (int i = 0; i < m1_rows; i++) {
    for (int j = 0; j < n2; j++) {
      int sum = 0;
      for (int k = 0; k < m1_cols; k++) {
        sum += mat1[i][k] * mat2[k][j];
      }
      result[i][j] = sum;
    }
  }
  recursive_mat_mult(mat1 + 1, mat2 + 1, m1_rows - 1, m1_cols, n1 - 1, n2 - 1);
}

int main() {
  int m1_rows = 3;
  int m1_cols = 4;
  int n1 = 2;
  int n2 = 3;
  int **mat1 = malloc(m1_rows * sizeof(int *));
  int **mat2 = malloc(n2 * sizeof(int *));
  for (int i = 0; i < m1_rows; i++) {
    mat1[i] = malloc(m1_cols * sizeof(int));
    for (int j = 0; j < m1_cols; j++) {
      mat1[i][j] = i * j;
    }
  }
  for (int i = 0; i < n2; i++) {
    mat2[i] = malloc(m1_cols * sizeof(int));
    for (int j = 0; j < m1_cols; j++) {
      mat2[i][j] = i * j;
    }
  }
  recursive_mat_mult(mat1, mat2, m1_rows, m1_cols, n1, n2);
  return 0;
}