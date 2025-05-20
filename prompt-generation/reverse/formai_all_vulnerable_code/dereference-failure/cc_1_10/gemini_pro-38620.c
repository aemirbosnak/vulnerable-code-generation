//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int **matrix;
  int rows;
  int cols;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->matrix = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix->matrix[i] = malloc(cols * sizeof(int));
  }
  return matrix;
}

void free_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->matrix[i]);
  }
  free(matrix->matrix);
  free(matrix);
}

void print_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  int rows = rand() % 10 + 1;
  int cols = rand() % 10 + 1;
  Matrix *matrix = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix->matrix[i][j] = rand() % 10 + 1;
    }
  }
  print_matrix(matrix);
  free_matrix(matrix);
  return 0;
}