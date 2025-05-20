//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 1000

// Generate a random matrix
int** generate_matrix(int size) {
  int** matrix = (int**)malloc(size * sizeof(int*));
  for (int i = 0; i < size; i++) {
    matrix[i] = (int*)malloc(size * sizeof(int));
    for (int j = 0; j < size; j++) {
      matrix[i][j] = rand() % 100;
    }
  }
  return matrix;
}

// Free the memory allocated for the matrix
void free_matrix(int** matrix, int size) {
  for (int i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Perform matrix multiplication
int** multiply_matrices(int** matrix1, int** matrix2, int size) {
  int** result = (int**)malloc(size * sizeof(int*));
  for (int i = 0; i < size; i++) {
    result[i] = (int*)malloc(size * sizeof(int));
    for (int j = 0; j < size; j++) {
      result[i][j] = 0;
      for (int k = 0; k < size; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

// Print the matrix
void print_matrix(int** matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Generate two random matrices
  int** matrix1 = generate_matrix(MATRIX_SIZE);
  int** matrix2 = generate_matrix(MATRIX_SIZE);

  // Start the timer
  clock_t start = clock();

  // Perform matrix multiplication
  int** result = multiply_matrices(matrix1, matrix2, MATRIX_SIZE);

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken for matrix multiplication
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the result
  // printf("Result:\n");
  // print_matrix(result, MATRIX_SIZE);

  // Print the time taken
  printf("Time taken: %f seconds\n", time_taken);

  // Free the memory allocated for the matrices
  free_matrix(matrix1, MATRIX_SIZE);
  free_matrix(matrix2, MATRIX_SIZE);
  free_matrix(result, MATRIX_SIZE);

  return 0;
}