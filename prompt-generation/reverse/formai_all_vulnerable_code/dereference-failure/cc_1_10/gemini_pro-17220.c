//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: authentic
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
  matrix->data = malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = malloc(sizeof(int) * cols);
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

Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
    return NULL;
  }
  Matrix *matrix3 = create_matrix(matrix1->rows, matrix1->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix1->cols; j++) {
      matrix3->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
    }
  }
  return matrix3;
}

Matrix *subtract_matrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
    return NULL;
  }
  Matrix *matrix3 = create_matrix(matrix1->rows, matrix1->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix1->cols; j++) {
      matrix3->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
    }
  }
  return matrix3;
}

Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->cols != matrix2->rows) {
    return NULL;
  }
  Matrix *matrix3 = create_matrix(matrix1->rows, matrix2->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix2->cols; j++) {
      int sum = 0;
      for (int k = 0; k < matrix1->cols; k++) {
        sum += matrix1->data[i][k] * matrix2->data[k][j];
      }
      matrix3->data[i][j] = sum;
    }
  }
  return matrix3;
}

int main() {
  Matrix *matrix1 = create_matrix(3, 3);
  matrix1->data[0][0] = 1;
  matrix1->data[0][1] = 2;
  matrix1->data[0][2] = 3;
  matrix1->data[1][0] = 4;
  matrix1->data[1][1] = 5;
  matrix1->data[1][2] = 6;
  matrix1->data[2][0] = 7;
  matrix1->data[2][1] = 8;
  matrix1->data[2][2] = 9;

  Matrix *matrix2 = create_matrix(3, 3);
  matrix2->data[0][0] = 1;
  matrix2->data[0][1] = 2;
  matrix2->data[0][2] = 3;
  matrix2->data[1][0] = 4;
  matrix2->data[1][1] = 5;
  matrix2->data[1][2] = 6;
  matrix2->data[2][0] = 7;
  matrix2->data[2][1] = 8;
  matrix2->data[2][2] = 9;

  printf("Matrix 1:\n");
  print_matrix(matrix1);

  printf("Matrix 2:\n");
  print_matrix(matrix2);

  Matrix *matrix3 = add_matrices(matrix1, matrix2);
  printf("Matrix 1 + Matrix 2:\n");
  print_matrix(matrix3);
  free_matrix(matrix3);

  matrix3 = subtract_matrices(matrix1, matrix2);
  printf("Matrix 1 - Matrix 2:\n");
  print_matrix(matrix3);
  free_matrix(matrix3);

  matrix3 = multiply_matrices(matrix1, matrix2);
  printf("Matrix 1 * Matrix 2:\n");
  print_matrix(matrix3);
  free_matrix(matrix3);

  free_matrix(matrix1);
  free_matrix(matrix2);

  return 0;
}