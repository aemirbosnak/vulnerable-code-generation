//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
void print_matrix(double**, int, int);
double** scalar_multiply(double, double**, int, int);
double** matrix_multiply(double**, double**, int, int, int);
double** transpose(double**, int, int);

int main() {
  // initialize matrices
  int rows = 3;
  int cols = 3;
  double A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double B[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

  // allocate memory for dynamic matrices
  double **A_dyn = (double**) malloc(rows * sizeof(double*));
  double **B_dyn = (double**) malloc(rows * sizeof(double*));

  for (int i = 0; i < rows; i++) {
    A_dyn[i] = (double*) malloc(cols * sizeof(double));
    B_dyn[i] = (double*) malloc(cols * sizeof(double));
    for (int j = 0; j < cols; j++) {
      A_dyn[i][j] = A[i][j];
      B_dyn[i][j] = B[i][j];
    }
  }

  // print original matrices
  printf("Matrix A:\n");
  print_matrix(A_dyn, rows, cols);

  printf("Matrix B:\n");
  print_matrix(B_dyn, rows, cols);

  // perform scalar multiplication
  double scalar = 2;
  double **A_scalar = scalar_multiply(scalar, A_dyn, rows, cols);
  printf("Scalar multiplication of A by %f:\n", scalar);
  print_matrix(A_scalar, rows, cols);

  // perform matrix multiplication
  double **AB_mult = matrix_multiply(A_dyn, B_dyn, rows, cols, cols);
  printf("Matrix multiplication of A and B:\n");
  print_matrix(AB_mult, rows, cols);

  // perform transpose of A
  double **A_transpose = transpose(A_dyn, rows, cols);
  printf("Transpose of A:\n");
  print_matrix(A_transpose, cols, rows);

  // free memory
  for (int i = 0; i < rows; i++) {
    free(A_dyn[i]);
    free(B_dyn[i]);
    free(A_scalar[i]);
    free(AB_mult[i]);
    free(A_transpose[i]);
  }
  free(A_dyn);
  free(B_dyn);
  free(A_scalar);
  free(AB_mult);
  free(A_transpose);

  return 0;
}

// function to print a matrix
void print_matrix(double **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }
}

// function to scalar multiply a matrix
double** scalar_multiply(double scalar, double **matrix, int rows, int cols) {
  double **result = (double**) malloc(rows * sizeof(double*));

  for (int i = 0; i < rows; i++) {
    result[i] = (double*) malloc(cols * sizeof(double));
    for (int j = 0; j < cols; j++) {
      result[i][j] = scalar * matrix[i][j];
    }
  }

  return result;
}

// function to multiply two matrices
double** matrix_multiply(double **matrix1, double **matrix2, int rows1, int cols1, int cols2) {
  double **result = (double**) malloc(rows1 * sizeof(double*));

  for (int i = 0; i < rows1; i++) {
    result[i] = (double*) malloc(cols2 * sizeof(double));
    for (int j = 0; j < cols2; j++) {
      result[i][j] = 0;
      for (int k = 0; k < cols1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  return result;
}

// function to transpose a matrix
double** transpose(double **matrix, int rows, int cols) {
  double **result = (double**) malloc(cols * sizeof(double*));

  for (int i = 0; i < cols; i++) {
    result[i] = (double*) malloc(rows * sizeof(double));
    for (int j = 0; j < rows; j++) {
      result[i][j] = matrix[j][i];
    }
  }

  return result;
}