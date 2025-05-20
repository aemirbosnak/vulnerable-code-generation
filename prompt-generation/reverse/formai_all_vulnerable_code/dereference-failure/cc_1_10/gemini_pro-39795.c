//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Define the matrix structure
typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

// Create a new matrix
Matrix *matrix_create(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = malloc(sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = malloc(sizeof(int) * cols);
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

// Get the value of an element in a matrix
int matrix_get(Matrix *matrix, int row, int col) {
  return matrix->data[row][col];
}

// Set the value of an element in a matrix
void matrix_set(Matrix *matrix, int row, int col, int value) {
  matrix->data[row][col] = value;
}

// Add two matrices
Matrix *matrix_add(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
    return NULL;
  }
  Matrix *result = matrix_create(matrix1->rows, matrix1->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix1->cols; j++) {
      result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
    }
  }
  return result;
}

// Subtract two matrices
Matrix *matrix_subtract(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
    return NULL;
  }
  Matrix *result = matrix_create(matrix1->rows, matrix1->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix1->cols; j++) {
      result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
    }
  }
  return result;
}

// Multiply two matrices
Matrix *matrix_multiply(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->cols != matrix2->rows) {
    return NULL;
  }
  Matrix *result = matrix_create(matrix1->rows, matrix2->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix2->cols; j++) {
      result->data[i][j] = 0;
      for (int k = 0; k < matrix1->cols; k++) {
        result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
      }
    }
  }
  return result;
}

// Print a matrix
void matrix_print(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create two matrices
  Matrix *matrix1 = matrix_create(2, 3);
  matrix_set(matrix1, 0, 0, 1);
  matrix_set(matrix1, 0, 1, 2);
  matrix_set(matrix1, 0, 2, 3);
  matrix_set(matrix1, 1, 0, 4);
  matrix_set(matrix1, 1, 1, 5);
  matrix_set(matrix1, 1, 2, 6);

  Matrix *matrix2 = matrix_create(3, 2);
  matrix_set(matrix2, 0, 0, 7);
  matrix_set(matrix2, 0, 1, 8);
  matrix_set(matrix2, 1, 0, 9);
  matrix_set(matrix2, 1, 1, 10);
  matrix_set(matrix2, 2, 0, 11);
  matrix_set(matrix2, 2, 1, 12);

  // Add the two matrices
  Matrix *result = matrix_add(matrix1, matrix2);

  // Print the result
  matrix_print(result);

  // Free the memory allocated for the matrices
  matrix_free(matrix1);
  matrix_free(matrix2);
  matrix_free(result);

  return 0;
}