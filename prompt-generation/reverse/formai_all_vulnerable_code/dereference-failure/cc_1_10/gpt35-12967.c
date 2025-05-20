//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void printMatrix(int**, int, int);
void addMatrix(int**, int**, int**, int, int);
void subtractMatrix(int**, int**, int**, int, int);
void multiplyMatrix(int**, int**, int**, int, int, int);

int main() {
  // initialize matrices
  int rows = 3, cols = 3;
  int **matrix1 = malloc(rows * sizeof(int *));
  int **matrix2 = malloc(rows * sizeof(int *));
  int **sumMatrix = malloc(rows * sizeof(int *));
  int **diffMatrix = malloc(rows * sizeof(int *));
  int **prodMatrix = malloc(rows * sizeof(int *));

  for (int i = 0 ; i < rows ; i++) {
    matrix1[i] = malloc(cols * sizeof(int));
    matrix2[i] = malloc(cols * sizeof(int));
    sumMatrix[i] = malloc(cols * sizeof(int));
    diffMatrix[i] = malloc(cols * sizeof(int));
    prodMatrix[i] = malloc(cols * sizeof(int));
  }

  // populate matrices
  matrix1[0][0] = 1; matrix1[0][1] = 8; matrix1[0][2] = 2;
  matrix1[1][0] = 3; matrix1[1][1] = 2; matrix1[1][2] = 0;
  matrix1[2][0] = 5; matrix1[2][1] = 1; matrix1[2][2] = 6;

  matrix2[0][0] = 7; matrix2[0][1] = 4; matrix2[0][2] = 9;
  matrix2[1][0] = 1; matrix2[1][1] = 6; matrix2[1][2] = 3;
  matrix2[2][0] = 2; matrix2[2][1] = 5; matrix2[2][2] = 8;

  // perform operations
  addMatrix(matrix1, matrix2, sumMatrix, rows, cols);
  subtractMatrix(matrix1, matrix2, diffMatrix, rows, cols);
  multiplyMatrix(matrix1, matrix2, prodMatrix, rows, cols, rows);

  // print matrices
  printf("Matrix 1:\n");
  printMatrix(matrix1, rows, cols);
  printf("\nMatrix 2:\n");
  printMatrix(matrix2, rows, cols);

  printf("\nSum Matrix:\n");
  printMatrix(sumMatrix, rows, cols);
  printf("\nDifference Matrix:\n");
  printMatrix(diffMatrix, rows, cols);
  printf("\nProduct Matrix:\n");
  printMatrix(prodMatrix, rows, cols);

  // deallocate memory
  for (int i = 0 ; i < rows ; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
    free(sumMatrix[i]);
    free(diffMatrix[i]);
    free(prodMatrix[i]);
  }
  free(matrix1);
  free(matrix2);
  free(sumMatrix);
  free(diffMatrix);
  free(prodMatrix);

  return 0;
}

// function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
  for (int i = 0 ; i < rows ; i++) {
    for (int j = 0 ; j < cols ; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// function to add two matrices
void addMatrix(int **matrix1, int **matrix2, int **result, int rows, int cols) {
  for (int i = 0 ; i < rows ; i++) {
    for (int j = 0 ; j < cols ; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

// function to subtract two matrices
void subtractMatrix(int **matrix1, int **matrix2, int **result, int rows, int cols) {
  for (int i = 0 ; i < rows ; i++) {
    for (int j = 0 ; j < cols ; j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

// function to multiply two matrices
void multiplyMatrix(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int cols2) {
  for (int i = 0 ; i < rows1 ; i++) {
    for (int j = 0 ; j < cols2 ; j++) {
      result[i][j] = 0;
      for (int k = 0 ; k < cols1 ; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}