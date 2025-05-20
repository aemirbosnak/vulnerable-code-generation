//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to create a new matrix
int **create_matrix(int rows, int cols) {
  int **matrix = (int **)malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(sizeof(int) * cols);
  }
  return matrix;
}

// Function to free a matrix
void free_matrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
int **add_matrices(int **matrix1, int **matrix2, int rows, int cols) {
  int **result_matrix = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return result_matrix;
}

// Function to subtract two matrices
int **subtract_matrices(int **matrix1, int **matrix2, int rows, int cols) {
  int **result_matrix = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  return result_matrix;
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
  if (cols1 != rows2) {
    printf("Matrices cannot be multiplied.\n");
    return NULL;
  }
  int **result_matrix = create_matrix(rows1, cols2);
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      result_matrix[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result_matrix;
}

int main() {
  // Create two matrices
  int **matrix1 = create_matrix(3, 3);
  int **matrix2 = create_matrix(3, 3);

  // Initialize the matrices
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix1[i][j] = i + j;
      matrix2[i][j] = i - j;
    }
  }

  // Print the matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1, 3, 3);
  printf("\nMatrix 2:\n");
  print_matrix(matrix2, 3, 3);

  // Add the matrices
  int **result_matrix = add_matrices(matrix1, matrix2, 3, 3);

  // Print the result matrix
  printf("\nResult of addition:\n");
  print_matrix(result_matrix, 3, 3);

  // Subtract the matrices
  result_matrix = subtract_matrices(matrix1, matrix2, 3, 3);

  // Print the result matrix
  printf("\nResult of subtraction:\n");
  print_matrix(result_matrix, 3, 3);

  // Multiply the matrices
  result_matrix = multiply_matrices(matrix1, matrix2, 3, 3, 3, 3);

  // Print the result matrix
  printf("\nResult of multiplication:\n");
  print_matrix(result_matrix, 3, 3);

  // Free the matrices
  free_matrix(matrix1, 3);
  free_matrix(matrix2, 3);
  free_matrix(result_matrix, 3);

  return 0;
}