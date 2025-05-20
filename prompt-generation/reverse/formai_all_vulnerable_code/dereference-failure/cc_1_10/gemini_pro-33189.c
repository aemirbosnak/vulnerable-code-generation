//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the matrix
#define ROWS 100
#define COLS 100

// Create a function to allocate memory for a matrix
double **allocate_matrix(int rows, int cols) {
  // Allocate memory for the rows of the matrix
  double **matrix = malloc(rows * sizeof(double *));

  // Allocate memory for the columns of the matrix
  for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(double));
  }

  // Return the matrix
  return matrix;
}

// Create a function to free the memory allocated for a matrix
void free_matrix(double **matrix, int rows, int cols) {
  // Free the memory allocated for the columns of the matrix
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }

  // Free the memory allocated for the rows of the matrix
  free(matrix);
}

// Create a function to fill a matrix with random numbers
void fill_matrix(double **matrix, int rows, int cols) {
  // Initialize the random number generator
  srand(time(NULL));

  // Fill the matrix with random numbers
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand() / (double)RAND_MAX;
    }
  }
}

// Create a function to print a matrix
void print_matrix(double **matrix, int rows, int cols) {
  // Print the matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.2f ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Allocate memory for the matrix
  double **matrix = allocate_matrix(ROWS, COLS);

  // Fill the matrix with random numbers
  fill_matrix(matrix, ROWS, COLS);

  // Print the matrix
  print_matrix(matrix, ROWS, COLS);

  // Free the memory allocated for the matrix
  free_matrix(matrix, ROWS, COLS);

  return 0;
}