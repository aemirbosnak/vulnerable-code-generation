//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define matrix operations
int matrix_add(int **a, int **b, int **c, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return 0;
}

int matrix_subtract(int **a, int **b, int **c, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = a[i][j] - b[i][j];
    }
  }
  return 0;
}

int matrix_multiply(int **a, int **b, int **c, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for (int k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return 0;
}

int matrix_print(int **a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main() {
  // Declare and initialize matrices
  int n = 3;
  int **a = (int **)malloc(n * sizeof(int *));
  int **b = (int **)malloc(n * sizeof(int *));
  int **c = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
    b[i] = (int *)malloc(n * sizeof(int));
    c[i] = (int *)malloc(n * sizeof(int));
  }

  // Initialize matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = i + j;
      b[i][j] = i - j;
    }
  }

  // Print original matrices
  printf("Matrix A:\n");
  matrix_print(a, n);
  printf("Matrix B:\n");
  matrix_print(b, n);

  // Perform matrix operations
  matrix_add(a, b, c, n);
  printf("Matrix A + B:\n");
  matrix_print(c, n);
  matrix_subtract(a, b, c, n);
  printf("Matrix A - B:\n");
  matrix_print(c, n);
  matrix_multiply(a, b, c, n);
  printf("Matrix A * B:\n");
  matrix_print(c, n);

  // Free allocated memory
  for (int i = 0; i < n; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}