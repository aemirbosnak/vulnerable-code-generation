//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Create a new matrix with the given dimensions.
int** create_matrix(int rows, int cols) {
  int** matrix = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int*)malloc(cols * sizeof(int));
  }
  return matrix;
}

// Free the memory allocated for the given matrix.
void free_matrix(int** matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Print the given matrix to the console.
void print_matrix(int** matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Add two matrices of the same size.
int** add_matrices(int** matrix1, int** matrix2, int rows, int cols) {
  int** result = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return result;
}

// Multiply two matrices of compatible sizes.
int** multiply_matrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
  int** result = create_matrix(rows1, cols2);
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

int main() {
  // Create two matrices.
  int** matrix1 = create_matrix(2, 2);
  matrix1[0][0] = 1;
  matrix1[0][1] = 2;
  matrix1[1][0] = 3;
  matrix1[1][1] = 4;

  int** matrix2 = create_matrix(2, 2);
  matrix2[0][0] = 5;
  matrix2[0][1] = 6;
  matrix2[1][0] = 7;
  matrix2[1][1] = 8;

  // Add the two matrices.
  int** result1 = add_matrices(matrix1, matrix2, 2, 2);

  // Multiply the two matrices.
  int** result2 = multiply_matrices(matrix1, matrix2, 2, 2, 2, 2);

  // Print the results.
  printf("Matrix 1:\n");
  print_matrix(matrix1, 2, 2);

  printf("Matrix 2:\n");
  print_matrix(matrix2, 2, 2);

  printf("Result of adding the two matrices:\n");
  print_matrix(result1, 2, 2);

  printf("Result of multiplying the two matrices:\n");
  print_matrix(result2, 2, 2);

  // Free the memory allocated for the matrices.
  free_matrix(matrix1, 2);
  free_matrix(matrix2, 2);
  free_matrix(result1, 2);
  free_matrix(result2, 2);

  return 0;
}