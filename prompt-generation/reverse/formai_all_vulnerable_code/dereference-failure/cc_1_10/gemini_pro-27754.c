//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to create a matrix
double **create_matrix(int rows, int cols) {
  double **matrix = (double **)malloc(rows * sizeof(double *));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (double *)malloc(cols * sizeof(double));
  }
  return matrix;
}

// Function to free a matrix
void free_matrix(double **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Function to print a matrix
void print_matrix(double **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to calculate the mean of a matrix
double mean(double **matrix, int rows, int cols) {
  double sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sum += matrix[i][j];
    }
  }
  return sum / (rows * cols);
}

// Function to calculate the variance of a matrix
double variance(double **matrix, int rows, int cols) {
  double mean_value = mean(matrix, rows, cols);
  double sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sum += pow(matrix[i][j] - mean_value, 2);
    }
  }
  return sum / (rows * cols);
}

// Function to calculate the covariance of two matrices
double covariance(double **matrix1, double **matrix2, int rows, int cols) {
  double mean1 = mean(matrix1, rows, cols);
  double mean2 = mean(matrix2, rows, cols);
  double sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sum += (matrix1[i][j] - mean1) * (matrix2[i][j] - mean2);
    }
  }
  return sum / (rows * cols);
}

// Function to calculate the correlation coefficient of two matrices
double correlation_coefficient(double **matrix1, double **matrix2, int rows, int cols) {
  double covariance_value = covariance(matrix1, matrix2, rows, cols);
  double variance1 = variance(matrix1, rows, cols);
  double variance2 = variance(matrix2, rows, cols);
  return covariance_value / sqrt(variance1 * variance2);
}

int main() {
  // Create two matrices
  int rows = 10;
  int cols = 10;
  double **matrix1 = create_matrix(rows, cols);
  double **matrix2 = create_matrix(rows, cols);

  // Initialize the matrices with random values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix1[i][j] = rand() % 100;
      matrix2[i][j] = rand() % 100;
    }
  }

  // Print the matrices
  printf("Matrix 1:\n");
  print_matrix(matrix1, rows, cols);
  printf("\n");

  printf("Matrix 2:\n");
  print_matrix(matrix2, rows, cols);
  printf("\n");

  // Calculate the mean of the matrices
  double mean1 = mean(matrix1, rows, cols);
  double mean2 = mean(matrix2, rows, cols);
  printf("Mean of Matrix 1: %f\n", mean1);
  printf("Mean of Matrix 2: %f\n", mean2);
  printf("\n");

  // Calculate the variance of the matrices
  double variance1 = variance(matrix1, rows, cols);
  double variance2 = variance(matrix2, rows, cols);
  printf("Variance of Matrix 1: %f\n", variance1);
  printf("Variance of Matrix 2: %f\n", variance2);
  printf("\n");

  // Calculate the covariance of the matrices
  double covariance_value = covariance(matrix1, matrix2, rows, cols);
  printf("Covariance of Matrix 1 and Matrix 2: %f\n", covariance_value);
  printf("\n");

  // Calculate the correlation coefficient of the matrices
  double correlation_coefficient_value = correlation_coefficient(matrix1, matrix2, rows, cols);
  printf("Correlation Coefficient of Matrix 1 and Matrix 2: %f\n", correlation_coefficient_value);
  printf("\n");

  // Free the matrices
  free_matrix(matrix1, rows);
  free_matrix(matrix2, rows);

  return 0;
}