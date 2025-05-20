//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the matrix structure
typedef struct Matrix {
  int rows;
  int cols;
  int **data;
} Matrix;

// Create a new matrix
Matrix* matrix_new(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = malloc(cols * sizeof(int));
  }
  return matrix;
}

// Free the memory allocated for a matrix
void matrix_free(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

// Print the matrix to the console
void matrix_print(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

// Add two matrices
Matrix* matrix_add(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Error: matrices must have the same dimensions\n");
    return NULL;
  }

  Matrix *c = matrix_new(a->rows, a->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      c->data[i][j] = a->data[i][j] + b->data[i][j];
    }
  }
  return c;
}

// Multiply two matrices
Matrix* matrix_multiply(Matrix *a, Matrix *b) {
  if (a->cols != b->rows) {
    printf("Error: matrices cannot be multiplied\n");
    return NULL;
  }

  Matrix *c = matrix_new(a->rows, b->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      int sum = 0;
      for (int k = 0; k < a->cols; k++) {
        sum += a->data[i][k] * b->data[k][j];
      }
      c->data[i][j] = sum;
    }
  }
  return c;
}

// Generate a random matrix
Matrix* matrix_random(int rows, int cols) {
  Matrix *matrix = matrix_new(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix->data[i][j] = rand() % 10;
    }
  }
  return matrix;
}

// Main function
int main() {
  // Create two random matrices
  Matrix *a = matrix_random(3, 3);
  Matrix *b = matrix_random(3, 3);

  // Print the matrices
  printf("Matrix A:\n");
  matrix_print(a);
  printf("\nMatrix B:\n");
  matrix_print(b);

  // Add the matrices
  Matrix *c = matrix_add(a, b);
  printf("\nMatrix A + Matrix B:\n");
  matrix_print(c);

  // Multiply the matrices
  Matrix *d = matrix_multiply(a, b);
  printf("\nMatrix A * Matrix B:\n");
  matrix_print(d);

  // Free the memory allocated for the matrices
  matrix_free(a);
  matrix_free(b);
  matrix_free(c);
  matrix_free(d);

  return 0;
}