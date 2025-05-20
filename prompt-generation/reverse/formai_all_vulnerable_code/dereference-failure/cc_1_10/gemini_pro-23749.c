//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

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

void free_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

void print_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Create two matrices
  Matrix *a = create_matrix(2, 3);
  Matrix *b = create_matrix(3, 2);

  // Initialize the matrices
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      a->data[i][j] = rand() % 10;
    }
  }

  for (int i = 0; i < b->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      b->data[i][j] = rand() % 10;
    }
  }

  // Print the matrices
  printf("Matrix A:\n");
  print_matrix(a);

  printf("Matrix B:\n");
  print_matrix(b);

  // Compute the product of the matrices
  Matrix *c = create_matrix(a->rows, b->cols);
  for (int i = 0; i < c->rows; i++) {
    for (int j = 0; j < c->cols; j++) {
      c->data[i][j] = 0;
      for (int k = 0; k < a->cols; k++) {
        c->data[i][j] += a->data[i][k] * b->data[k][j];
      }
    }
  }

  // Print the product of the matrices
  printf("Product of A and B:\n");
  print_matrix(c);

  // Free the matrices
  free_matrix(a);
  free_matrix(b);
  free_matrix(c);

  return 0;
}