//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>

// Function to print a matrix
void printMatrix(int m[][3], int rows, int cols) {
  printf("\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void add(int a[][3], int b[][3], int result[][3], int rows, int cols) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      result[i][j] = a[i][j] + b[i][j];
    }
  }
}

// Function to subtract two matrices
void subtract(int a[][3], int b[][3], int result[][3], int rows, int cols) {
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      result[i][j] = a[i][j] - b[i][j];
    }
  }
}

// Function to multiply two matrices
void multiply(int a[][3], int b[][3], int result[][3], int rows1, int cols1, int rows2, int cols2) {
  if(cols1 != rows2) {
    printf("\nInvalid operation. Cannot multiply these matrices.");
    return;
  }
  for(int i = 0; i < rows1; i++) {
    for(int j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for(int k = 0; k < cols1; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main() {
  int rows, cols;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  int a[rows][cols];
  int b[rows][cols];
  int result[rows][cols];

  printf("\nEnter the elements of matrix A:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      printf("A[%d][%d]: ", i, j);
      scanf("%d", &a[i][j]);
    }
  }

  printf("\nEnter the elements of matrix B:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      printf("B[%d][%d]: ", i, j);
      scanf("%d", &b[i][j]);
    }
  }

  printf("\nMatrix A:\n");
  printMatrix(a, rows, cols);

  printf("\nMatrix B:\n");
  printMatrix(b, rows, cols);

  // Add matrix A and B
  add(a, b, result, rows, cols);
  printf("\nMatrix A + B:\n");
  printMatrix(result, rows, cols);

  // Subtract matrix B from A
  subtract(a, b, result, rows, cols);
  printf("\nMatrix A - B:\n");
  printMatrix(result, rows, cols);

  // Multiply matrix A and B
  multiply(a, b, result, rows, cols, rows, cols);
  printf("\nMatrix A * B:\n");
  printMatrix(result, rows, cols);

  return 0;
}