//FormAI DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>

// function to initialize the matrix with random values between 0 and 10
void initMatrix(int rows, int cols, int matrix[rows][cols]) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      matrix[row][col] = rand() % 10;
    }
  }
}

// function to print the contents of a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      printf("%d ", matrix[row][col]);
    }
    printf("\n");
  }
}

// function to add two matrices
void addMatrix(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      result[row][col] = matrix1[row][col] + matrix2[row][col];
    }
  }
}

int main() {
  // define the size of the matrices
  int rows = 3;
  int cols = 3;

  // define the matrices and initialize them
  int matrix1[rows][cols];
  int matrix2[rows][cols];
  int result[rows][cols];
  initMatrix(rows, cols, matrix1);
  initMatrix(rows, cols, matrix2);

  // print the matrices before addition
  printf("Matrix 1: \n");
  printMatrix(rows, cols, matrix1);
  printf("\n");

  printf("Matrix 2: \n");
  printMatrix(rows, cols, matrix2);
  printf("\n");

  // add the matrices and print the result
  addMatrix(rows, cols, matrix1, matrix2, result);
  printf("Result: \n");
  printMatrix(rows, cols, result);
  printf("\n");

  return 0;
}