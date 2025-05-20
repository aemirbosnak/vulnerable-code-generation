//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the size of the matrices
#define ROWS 3
#define COLS 3

// Function to print a matrix
void printMatrix(int matrix[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = 0;
      for (int k = 0; k < COLS; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

// Function to find the transpose of a matrix
void transposeMatrix(int matrix[ROWS][COLS], int transpose[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      transpose[j][i] = matrix[i][j];
    }
  }
}

// Function to find the determinant of a matrix
int determinant(int matrix[ROWS][COLS]) {
  int det = 0;
  if (ROWS != COLS) {
    return 0;  // Determinant is not defined for non-square matrices
  }
  if (ROWS == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  }
  for (int i = 0; i < COLS; i++) {
    int submatrix[ROWS - 1][COLS - 1];
    for (int j = 1; j < ROWS; j++) {
      for (int k = 0; k < COLS; k++) {
        if (k == i) {
          continue;
        }
        submatrix[j - 1][k - (k > i)] = matrix[j][k];
      }
    }
    det += matrix[0][i] * determinant(submatrix) * ((i % 2) ? -1 : 1);
  }
  return det;
}

// Function to find the inverse of a matrix
int inverse(int matrix[ROWS][COLS], int inverse[ROWS][COLS]) {
  if (ROWS != COLS) {
    return 0;  // Inverse is not defined for non-square matrices
  }
  int det = determinant(matrix);
  if (det == 0) {
    return 0;  // Inverse does not exist for matrices with determinant 0
  }
  int adjoint[ROWS][COLS];
  transposeMatrix(matrix, adjoint);
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      inverse[i][j] = adjoint[i][j] / det;
    }
  }
  return 1;
}

// Main function
int main() {
  // Initialize the matrices
  int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int result[ROWS][COLS];

  // Print the original matrices
  printf("Matrix 1:\n");
  printMatrix(matrix1);
  printf("\nMatrix 2:\n");
  printMatrix(matrix2);

  // Add the matrices
  addMatrices(matrix1, matrix2, result);
  printf("\nSum of the matrices:\n");
  printMatrix(result);

  // Subtract the matrices
  subtractMatrices(matrix1, matrix2, result);
  printf("\nDifference of the matrices:\n");
  printMatrix(result);

  // Multiply the matrices
  multiplyMatrices(matrix1, matrix2, result);
  printf("\nProduct of the matrices:\n");
  printMatrix(result);

  // Find the transpose of matrix1
  int transpose[ROWS][COLS];
  transposeMatrix(matrix1, transpose);
  printf("\nTranspose of matrix1:\n");
  printMatrix(transpose);

  // Find the determinant of matrix1
  int det = determinant(matrix1);
  printf("\nDeterminant of matrix1: %d\n", det);

  // Find the inverse of matrix1
  if (inverse(matrix1, result)) {
    printf("\nInverse of matrix1:\n");
    printMatrix(result);
  } else {
    printf("Inverse does not exist for matrix1.\n");
  }

  return 0;
}