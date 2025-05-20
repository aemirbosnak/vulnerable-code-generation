//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

// Function to create a matrix
int **create_matrix(int rows, int cols) {
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
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
    printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
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
  int **matrix1 = create_matrix(ROWS, COLS);
  int **matrix2 = create_matrix(ROWS, COLS);

  // Fill the matrices with some values
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      matrix1[i][j] = rand() % 10;
      matrix2[i][j] = rand() % 10;
    }
  }

  // Print the original matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1, ROWS, COLS);
  printf("\nMatrix 2:\n");
  print_matrix(matrix2, ROWS, COLS);

  // Add the two matrices
  int **result_matrix1 = add_matrices(matrix1, matrix2, ROWS, COLS);

  // Print the result matrix
  printf("\nResult of adding the two matrices:\n");
  print_matrix(result_matrix1, ROWS, COLS);
  free_matrix(result_matrix1, ROWS);

  // Subtract the two matrices
  int **result_matrix2 = subtract_matrices(matrix1, matrix2, ROWS, COLS);

  // Print the result matrix
  printf("\nResult of subtracting the two matrices:\n");
  print_matrix(result_matrix2, ROWS, COLS);
  free_matrix(result_matrix2, ROWS);

  // Multiply the two matrices
  int **result_matrix3 = multiply_matrices(matrix1, matrix2, ROWS, COLS, ROWS, COLS);

  // Print the result matrix
  printf("\nResult of multiplying the two matrices:\n");
  print_matrix(result_matrix3, ROWS, COLS);
  free_matrix(result_matrix3, ROWS);

  // Free the memory allocated to the matrices
  free_matrix(matrix1, ROWS);
  free_matrix(matrix2, ROWS);

  return 0;
}