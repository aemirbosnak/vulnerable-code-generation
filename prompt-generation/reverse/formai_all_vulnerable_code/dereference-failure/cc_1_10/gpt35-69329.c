//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/* Define the matrix struct */
typedef struct Matrix {
  int rows;
  int cols;
  int **data;
} Matrix;

/* Function to create a matrix */
Matrix create_matrix(int rows, int cols) {
  Matrix m;
  m.rows = rows;
  m.cols = cols;
  m.data = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    m.data[i] = malloc(cols * sizeof(int));
  }
  return m;
}

/* Function to print a matrix */
void print_matrix(Matrix m) {
  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < m.cols; j++) {
      printf("%d ", m.data[i][j]);
    }
    printf("\n");
  }
}

/* Function to add two matrices */
Matrix add_matrices(Matrix m1, Matrix m2) {
  if (m1.rows != m2.rows || m1.cols != m2.cols) {
    printf("Error: matrices must have the same dimensions to be added.\n");
    exit(1);
  }
  Matrix result = create_matrix(m1.rows, m1.cols);
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.cols; j++) {
      result.data[i][j] = m1.data[i][j] + m2.data[i][j];
    }
  }
  return result;
}

/* Function to subtract two matrices */
Matrix subtract_matrices(Matrix m1, Matrix m2) {
  if (m1.rows != m2.rows || m1.cols != m2.cols) {
    printf("Error: matrices must have the same dimensions to be subtracted.\n");
    exit(1);
  }
  Matrix result = create_matrix(m1.rows, m1.cols);
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m1.cols; j++) {
      result.data[i][j] = m1.data[i][j] - m2.data[i][j];
    }
  }
  return result;
}

/* Function to multiply two matrices */
Matrix multiply_matrices(Matrix m1, Matrix m2) {
  if (m1.cols != m2.rows) {
    printf("Error: number of columns in matrix 1 must match number of rows in matrix 2.\n");
    exit(1);
  }
  Matrix result = create_matrix(m1.rows, m2.cols);
  for (int i = 0; i < m1.rows; i++) {
    for (int j = 0; j < m2.cols; j++) {
      result.data[i][j] = 0;
      for (int k = 0; k < m1.cols; k++) {
        result.data[i][j] += m1.data[i][k] * m2.data[k][j];
      }
    }
  }
  return result;
}

int main() {

  /* Create two matrices */
  Matrix m1 = create_matrix(2, 3);
  m1.data[0][0] = 1;
  m1.data[0][1] = 2;
  m1.data[0][2] = 3;
  m1.data[1][0] = 4;
  m1.data[1][1] = 5;
  m1.data[1][2] = 6;
  Matrix m2 = create_matrix(3, 2);
  m2.data[0][0] = 7;
  m2.data[0][1] = 8;
  m2.data[1][0] = 9;
  m2.data[1][1] = 10;
  m2.data[2][0] = 11;
  m2.data[2][1] = 12;

  /* Print the matrices */
  printf("Matrix 1:\n");
  print_matrix(m1);
  printf("Matrix 2:\n");
  print_matrix(m2);

  /* Add the matrices */
  Matrix sum = add_matrices(m1, m2);
  printf("Matrix sum:\n");
  print_matrix(sum);

  /* Subtract the matrices */
  Matrix difference = subtract_matrices(m1, m2);
  printf("Matrix difference:\n");
  print_matrix(difference);

  /* Multiply the matrices */
  Matrix product = multiply_matrices(m1, m2);
  printf("Matrix product:\n");
  print_matrix(product);

  return 0;
}