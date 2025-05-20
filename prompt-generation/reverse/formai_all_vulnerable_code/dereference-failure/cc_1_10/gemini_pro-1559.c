//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define the matrix structure
typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

// Create a new matrix with the given dimensions
Matrix *createMatrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = malloc(cols * sizeof(int));
  }
  return matrix;
}

// Free the memory allocated for the matrix
void freeMatrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

// Print the matrix to the console
void printMatrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

// Add two matrices together
Matrix *addMatrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
    printf("Matrices must have the same dimensions to be added.\n");
    return NULL;
  }
  Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
  for (int i = 0; i < matrix1->rows; i++) {
    for (int j = 0; j < matrix1->cols; j++) {
      result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
    }
  }
  return result;
}

// Multiply two matrices together
Matrix *multiplyMatrices(Matrix *matrix1, Matrix *matrix2) {
  if (matrix1->cols != matrix2->rows) {
    printf("Matrices cannot be multiplied because their dimensions are incompatible.\n");
    return NULL;
  }
  Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
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

// Transpose a matrix
Matrix *transposeMatrix(Matrix *matrix) {
  Matrix *result = createMatrix(matrix->cols, matrix->rows);
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      result->data[j][i] = matrix->data[i][j];
    }
  }
  return result;
}

// Invert a matrix
Matrix *invertMatrix(Matrix *matrix) {
  if (matrix->rows != matrix->cols) {
    printf("Only square matrices can be inverted.\n");
    return NULL;
  }
  Matrix *result = createMatrix(matrix->rows, matrix->cols);
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      result->data[i][j] = 0;
      if (i == j) {
        result->data[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < matrix->rows; i++) {
    int pivot = matrix->data[i][i];
    for (int j = 0; j < matrix->cols; j++) {
      matrix->data[i][j] /= pivot;
      result->data[i][j] /= pivot;
    }
    for (int j = i + 1; j < matrix->rows; j++) {
      int factor = matrix->data[j][i];
      for (int k = 0; k < matrix->cols; k++) {
        matrix->data[j][k] -= factor * matrix->data[i][k];
        result->data[j][k] -= factor * result->data[i][k];
      }
    }
  }
  return result;
}

// Main function
int main() {
  // Create two matrices
  Matrix *matrix1 = createMatrix(2, 3);
  matrix1->data[0][0] = 1;
  matrix1->data[0][1] = 2;
  matrix1->data[0][2] = 3;
  matrix1->data[1][0] = 4;
  matrix1->data[1][1] = 5;
  matrix1->data[1][2] = 6;

  Matrix *matrix2 = createMatrix(3, 2);
  matrix2->data[0][0] = 7;
  matrix2->data[0][1] = 8;
  matrix2->data[1][0] = 9;
  matrix2->data[1][1] = 10;
  matrix2->data[2][0] = 11;
  matrix2->data[2][1] = 12;

  // Add the two matrices together
  Matrix *result1 = addMatrices(matrix1, matrix2);
  printf("The sum of the two matrices is:\n");
  printMatrix(result1);

  // Multiply the two matrices together
  Matrix *result2 = multiplyMatrices(matrix1, matrix2);
  printf("The product of the two matrices is:\n");
  printMatrix(result2);

  // Transpose the first matrix
  Matrix *result3 = transposeMatrix(matrix1);
  printf("The transpose of the first matrix is:\n");
  printMatrix(result3);

  // Invert the first matrix
  Matrix *result4 = invertMatrix(matrix1);
  printf("The inverse of the first matrix is:\n");
  printMatrix(result4);

  // Free the memory allocated for the matrices
  freeMatrix(matrix1);
  freeMatrix(matrix2);
  freeMatrix(result1);
  freeMatrix(result2);
  freeMatrix(result3);
  freeMatrix(result4);

  return 0;
}