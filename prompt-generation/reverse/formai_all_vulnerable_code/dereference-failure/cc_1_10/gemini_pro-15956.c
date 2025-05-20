//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// a small function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// a function to multiply two matrices
int **multiply_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2,
                         int cols2) {
  // check if the matrices can be multiplied
  if (cols1 != rows2) {
    return NULL;
  }

  // create a new matrix to store the result
  int **result = (int **)malloc(rows1 * sizeof(int *));
  for (int i = 0; i < rows1; i++) {
    result[i] = (int *)malloc(cols2 * sizeof(int));
  }

  // multiply the matrices
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // return the result
  return result;
}

// a function to free the memory allocated for a matrix
void free_matrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// a function to generate a random matrix
int **generate_random_matrix(int rows, int cols) {
  // create a new matrix
  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  // fill the matrix with random numbers
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  // return the matrix
  return matrix;
}

int main() {
  // create two random matrices
  int **matrix1 = generate_random_matrix(3, 4);
  int **matrix2 = generate_random_matrix(4, 5);

  // print the matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1, 3, 4);
  printf("\n");
  printf("Matrix 2:\n");
  print_matrix(matrix2, 4, 5);
  printf("\n");

  // multiply the matrices
  int **result = multiply_matrices(matrix1, 3, 4, matrix2, 4, 5);

  // print the result
  printf("Result:\n");
  print_matrix(result, 3, 5);
  printf("\n");

  // free the memory allocated for the matrices
  free_matrix(matrix1, 3);
  free_matrix(matrix2, 4);
  free_matrix(result, 3);

  return 0;
}