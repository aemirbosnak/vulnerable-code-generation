//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

// Function declarations
void printMatrix(int **A, int rows, int cols);
int **addMatrix(int **A, int **B, int rows, int cols);
int **subtractMatrix(int **A, int **B, int rows, int cols);
int **multiplyMatrix(int **A, int **B, int rows_a, int cols_a, int cols_b);

// Main function
int main() {
  int rows_a, rows_b, cols_a, cols_b;

  // Matrix A input
  printf("Enter the number of rows for matrix A: ");
  scanf("%d", &rows_a);
  printf("Enter the number of columns for matrix A: ");
  scanf("%d", &cols_a);

  int **A = (int **)malloc(rows_a * sizeof(int *));
  for (int i = 0; i < rows_a; i++) {
    A[i] = (int *)malloc(cols_a * sizeof(int));
    for (int j = 0; j < cols_a; j++) {
      printf("Enter element %d%d for matrix A: ", i + 1, j + 1);
      scanf("%d", &A[i][j]);
    }
  }
  printf("Matrix A:\n");
  printMatrix(A, rows_a, cols_a);

  // Matrix B input
  printf("Enter the number of rows for matrix B: ");
  scanf("%d", &rows_b);
  printf("Enter the number of columns for matrix B: ");
  scanf("%d", &cols_b);

  int **B = (int **)malloc(rows_b * sizeof(int *));
  for (int i = 0; i < rows_b; i++) {
    B[i] = (int *)malloc(cols_b * sizeof(int));
    for (int j = 0; j < cols_b; j++) {
      printf("Enter element %d%d for matrix B: ", i + 1, j + 1);
      scanf("%d", &B[i][j]);
    }
  }
  printf("Matrix B:\n");
  printMatrix(B, rows_b, cols_b);

  // Matrix addition
  if (rows_a == rows_b && cols_a == cols_b) {
    int **C = addMatrix(A, B, rows_a, cols_a);
    printf("Addition of matrix A and matrix B:\n");
    printMatrix(C, rows_a, cols_a);
  } else {
    printf("Error: matrices A and B cannot be added.\n");
  }

  // Matrix subtraction
  if (rows_a == rows_b && cols_a == cols_b) {
    int **D = subtractMatrix(A, B, rows_a, cols_a);
    printf("Subtraction of matrix A and matrix B:\n");
    printMatrix(D, rows_a, cols_a);
  } else {
    printf("Error: matrices A and B cannot be subtracted.\n");
  }

  // Matrix multiplication
  if (cols_a == rows_b) {
    int **E = multiplyMatrix(A, B, rows_a, cols_a, cols_b);
    printf("Multiplication of matrix A and matrix B:\n");
    printMatrix(E, rows_a, cols_b);
  } else {
    printf("Error: matrices A and B cannot be multiplied.\n");
  }

  // Free memory
  for (int i = 0; i < rows_a; i++) {
    free(A[i]);
  }
  free(A);

  for (int i = 0; i < rows_b; i++) {
    free(B[i]);
  }
  free(B);

  return 0;
}

// Function to print a matrix
void printMatrix(int **A, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
int **addMatrix(int **A, int **B, int rows, int cols) {
  int **C = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    C[i] = (int *)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}

// Function to subtract two matrices
int **subtractMatrix(int **A, int **B, int rows, int cols) {
  int **D = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    D[i] = (int *)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
      D[i][j] = A[i][j] - B[i][j];
    }
  }
  return D;
}

// Function to multiply two matrices
int **multiplyMatrix(int **A, int **B, int rows_a, int cols_a, int cols_b) {
  int **E = (int **)malloc(rows_a * sizeof(int *));
  for (int i = 0; i < rows_a; i++) {
    E[i] = (int *)malloc(cols_b * sizeof(int));
    for (int j = 0; j < cols_b; j++) {
      E[i][j] = 0;
      for (int k = 0; k < cols_a; k++) {
        E[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return E;
}