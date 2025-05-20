//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 3
#define COLS 3

typedef struct {
  double real;
  double imag;
} complex_number;

complex_number **create_matrix(int rows, int cols) {
  complex_number **matrix = (complex_number **)malloc(rows * sizeof(complex_number *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (complex_number *)malloc(cols * sizeof(complex_number));
  }
  return matrix;
}

void free_matrix(complex_number **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void print_matrix(complex_number **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("(%f, %f) ", matrix[i][j].real, matrix[i][j].imag);
    }
    printf("\n");
  }
}

complex_number **add_matrices(complex_number **matrix1, complex_number **matrix2, int rows, int cols) {
  complex_number **result = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j].real = matrix1[i][j].real + matrix2[i][j].real;
      result[i][j].imag = matrix1[i][j].imag + matrix2[i][j].imag;
    }
  }
  return result;
}

complex_number **subtract_matrices(complex_number **matrix1, complex_number **matrix2, int rows, int cols) {
  complex_number **result = create_matrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j].real = matrix1[i][j].real - matrix2[i][j].real;
      result[i][j].imag = matrix1[i][j].imag - matrix2[i][j].imag;
    }
  }
  return result;
}

complex_number **multiply_matrices(complex_number **matrix1, complex_number **matrix2, int rows1, int cols1, int rows2, int cols2) {
  complex_number **result = create_matrix(rows1, cols2);
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      result[i][j].real = 0;
      result[i][j].imag = 0;
      for (int k = 0; k < cols1; k++) {
        result[i][j].real += matrix1[i][k].real * matrix2[k][j].real - matrix1[i][k].imag * matrix2[k][j].imag;
        result[i][j].imag += matrix1[i][k].real * matrix2[k][j].imag + matrix1[i][k].imag * matrix2[k][j].real;
      }
    }
  }
  return result;
}

int main() {
  complex_number **matrix1 = create_matrix(ROWS, COLS);
  complex_number **matrix2 = create_matrix(ROWS, COLS);
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      matrix1[i][j].real = rand() / (double)RAND_MAX;
      matrix1[i][j].imag = rand() / (double)RAND_MAX;
      matrix2[i][j].real = rand() / (double)RAND_MAX;
      matrix2[i][j].imag = rand() / (double)RAND_MAX;
    }
  }

  printf("Matrix 1:\n");
  print_matrix(matrix1, ROWS, COLS);
  printf("\n");

  printf("Matrix 2:\n");
  print_matrix(matrix2, ROWS, COLS);
  printf("\n");

  complex_number **added_matrix = add_matrices(matrix1, matrix2, ROWS, COLS);
  printf("Added Matrix:\n");
  print_matrix(added_matrix, ROWS, COLS);
  printf("\n");

  complex_number **subtracted_matrix = subtract_matrices(matrix1, matrix2, ROWS, COLS);
  printf("Subtracted Matrix:\n");
  print_matrix(subtracted_matrix, ROWS, COLS);
  printf("\n");

  complex_number **multiplied_matrix = multiply_matrices(matrix1, matrix2, ROWS, COLS, ROWS, COLS);
  printf("Multiplied Matrix:\n");
  print_matrix(multiplied_matrix, ROWS, COLS);
  printf("\n");

  free_matrix(matrix1, ROWS);
  free_matrix(matrix2, ROWS);
  free_matrix(added_matrix, ROWS);
  free_matrix(subtracted_matrix, ROWS);
  free_matrix(multiplied_matrix, ROWS);

  return 0;
}