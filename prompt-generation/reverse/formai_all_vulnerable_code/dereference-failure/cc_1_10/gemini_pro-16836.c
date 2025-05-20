//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a matrix
typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

// Create a new matrix with the given dimensions
Matrix *create_matrix(int rows, int cols) {
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
void free_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

// Print a matrix to the console
void print_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

// Add two matrices together
Matrix *add_matrices(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Error: matrices must have the same dimensions\n");
    return NULL;
  }

  Matrix *c = create_matrix(a->rows, a->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      c->data[i][j] = a->data[i][j] + b->data[i][j];
    }
  }
  return c;
}

// Subtract two matrices
Matrix *subtract_matrices(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Error: matrices must have the same dimensions\n");
    return NULL;
  }

  Matrix *c = create_matrix(a->rows, a->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      c->data[i][j] = a->data[i][j] - b->data[i][j];
    }
  }
  return c;
}

// Multiply two matrices together
Matrix *multiply_matrices(Matrix *a, Matrix *b) {
  if (a->cols != b->rows) {
    printf("Error: number of columns in first matrix must equal number of rows in second matrix\n");
    return NULL;
  }

  Matrix *c = create_matrix(a->rows, b->cols);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      c->data[i][j] = 0;
      for (int k = 0; k < a->cols; k++) {
        c->data[i][j] += a->data[i][k] * b->data[k][j];
      }
    }
  }
  return c;
}

// Transpose a matrix
Matrix *transpose_matrix(Matrix *a) {
  Matrix *b = create_matrix(a->cols, a->rows);
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      b->data[j][i] = a->data[i][j];
    }
  }
  return b;
}

int main() {
  // Create two matrices
  Matrix *a = create_matrix(2, 3);
  a->data[0][0] = 1;
  a->data[0][1] = 2;
  a->data[0][2] = 3;
  a->data[1][0] = 4;
  a->data[1][1] = 5;
  a->data[1][2] = 6;

  Matrix *b = create_matrix(3, 2);
  b->data[0][0] = 7;
  b->data[0][1] = 8;
  b->data[1][0] = 9;
  b->data[1][1] = 10;
  b->data[2][0] = 11;
  b->data[2][1] = 12;

  // Print the original matrices
  printf("Matrix A:\n");
  print_matrix(a);

  printf("Matrix B:\n");
  print_matrix(b);

  // Add the two matrices
  Matrix *c = add_matrices(a, b);

  // Print the resulting matrix
  printf("Matrix A + Matrix B:\n");
  print_matrix(c);

  // Subtract the two matrices
  Matrix *d = subtract_matrices(a, b);

  // Print the resulting matrix
  printf("Matrix A - Matrix B:\n");
  print_matrix(d);

  // Multiply the two matrices
  Matrix *e = multiply_matrices(a, b);

  // Print the resulting matrix
  printf("Matrix A * Matrix B:\n");
  print_matrix(e);

  // Transpose the first matrix
  Matrix *f = transpose_matrix(a);

  // Print the resulting matrix
  printf("Transpose of Matrix A:\n");
  print_matrix(f);

  // Free the memory allocated for the matrices
  free_matrix(a);
  free_matrix(b);
  free_matrix(c);
  free_matrix(d);
  free_matrix(e);
  free_matrix(f);

  return 0;
}