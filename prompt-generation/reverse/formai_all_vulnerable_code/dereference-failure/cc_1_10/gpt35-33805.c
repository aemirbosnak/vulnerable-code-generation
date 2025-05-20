//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
  printf("Matrix:\n");
  for (int i = 0; i < rows; i++) {
    printf("| ");
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("|\n");
  }
}

// Function to add two matrices
int **add_matrices(int **matrix1, int **matrix2, int rows, int cols) {
  int **result = (int **) malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    result[i] = (int *) malloc(cols * sizeof(int));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return result;
}

// Function to subtract two matrices
int **subtract_matrices(int **matrix1, int **matrix2, int rows, int cols) {
  int **result = (int **) malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    result[i] = (int *) malloc(cols * sizeof(int));
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  return result;
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
  if (cols1 != rows2) {
    printf("Cannot multiply matrices of these dimensions\n");
    return NULL;
  }
  int **result = (int **) malloc(rows1 * sizeof(int *));
  for (int i = 0; i < rows1; i++) {
    result[i] = (int *) malloc(cols2 * sizeof(int));
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      int sum = 0;
      for (int k = 0; k < cols1; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      result[i][j] = sum;
    }
  }
  return result;
}

int main() {
  // Create two matrices to perform operations on
  int rows = 3;
  int cols = 3;
  int **matrix1 = (int **) malloc(rows * sizeof(int *));
  int **matrix2 = (int **) malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix1[i] = (int *) malloc(cols * sizeof(int));
    matrix2[i] = (int *) malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
      matrix1[i][j] = i + j;
      matrix2[i][j] = i * j;
    }
  }
  
  // Print the original matrices
  print_matrix(matrix1, rows, cols);
  print_matrix(matrix2, rows, cols);
  
  // Add the matrices
  int **matrix_sum = add_matrices(matrix1, matrix2, rows, cols);
  printf("\nMatrix sum:\n");
  print_matrix(matrix_sum, rows, cols);
  
  // Subtract the matrices
  int **matrix_diff = subtract_matrices(matrix1, matrix2, rows, cols);
  printf("\nMatrix difference:\n");
  print_matrix(matrix_diff, rows, cols);
  
  // Multiply the matrices
  int rows2 = 3;
  int cols2 = 2;
  int **matrix3 = (int **) malloc(rows2 * sizeof(int *));
  for (int i = 0; i < rows2; i++) {
    matrix3[i] = (int *) malloc(cols2 * sizeof(int));
    for (int j = 0; j < cols2; j++) {
      matrix3[i][j] = i - j;
    }
  }
  int **matrix_product = multiply_matrices(matrix1, matrix3, rows, cols, rows2, cols2);
  printf("\nMatrix product:\n");
  print_matrix(matrix_product, rows, cols2);
  
  // Free all allocated memory
  for (int i = 0; i < rows; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
    free(matrix_sum[i]);
    free(matrix_diff[i]);
  }
  for (int i = 0; i < rows2; i++) {
    free(matrix3[i]);
  }
  for (int i = 0; i < rows; i++) {
    free(matrix_product[i]);
  }
  free(matrix1);
  free(matrix2);
  free(matrix_sum);
  free(matrix_diff);
  free(matrix3);
  free(matrix_product);
  
  return 0;
}