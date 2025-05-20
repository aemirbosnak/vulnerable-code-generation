//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the size of the matrix
#define SIZE 3

// Define the matrix
int matrix[SIZE][SIZE] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};

// Print the matrix
void printMatrix() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

// Add two matrices
void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix1[i][j] += matrix2[i][j];
    }
  }
}

// Subtract two matrices
void subtractMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix1[i][j] -= matrix2[i][j];
    }
  }
}

// Multiply two matrices
void multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
  int result[SIZE][SIZE];

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      result[i][j] = 0;

      for (int k = 0; k < SIZE; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Copy the result back to matrix1
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix1[i][j] = result[i][j];
    }
  }
}

// Transpose a matrix
void transposeMatrix(int matrix1[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = i + 1; j < SIZE; j++) {
      int temp = matrix1[i][j];
      matrix1[i][j] = matrix1[j][i];
      matrix1[j][i] = temp;
    }
  }
}

// Find the determinant of a matrix
int determinant(int matrix[SIZE][SIZE]) {
  int det = 0;

  if (SIZE == 2) {
    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  } else {
    for (int i = 0; i < SIZE; i++) {
      // Create a new matrix without the ith row and jth column
      int newMatrix[SIZE - 1][SIZE - 1];

      for (int j = 0; j < SIZE; j++) {
        if (j == i) {
          continue;
        }

        for (int k = 1; k < SIZE; k++) {
          newMatrix[k - 1][j - 1] = matrix[k][j];
        }
      }

      det += matrix[0][i] * determinant(newMatrix) * ((i % 2) * 2 - 1);
    }
  }

  return det;
}

// Find the inverse of a matrix
void inverseMatrix(int matrix1[SIZE][SIZE]) {
  int det = determinant(matrix1);

  if (det == 0) {
    printf("The matrix is not invertible.\n");
    return;
  }

  int adjMatrix[SIZE][SIZE];

  // Find the adjoint matrix
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      // Create a new matrix without the ith row and jth column
      int newMatrix[SIZE - 1][SIZE - 1];

      for (int k = 0; k < SIZE; k++) {
        if (k == i) {
          continue;
        }

        for (int l = 0; l < SIZE; l++) {
          if (l == j) {
            continue;
          }

          newMatrix[k - 1][l - 1] = matrix1[k][l];
        }
      }

      adjMatrix[i][j] = determinant(newMatrix) * ((i + j) % 2 * 2 - 1);
    }
  }

  // Transpose the adjoint matrix
  transposeMatrix(adjMatrix);

  // Multiply the adjoint matrix by 1/det
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matrix1[i][j] = adjMatrix[i][j] / det;
    }
  }
}

int main() {
  // Print the original matrix
  printf("Original matrix:\n");
  printMatrix();

  // Add two matrices
  int matrix2[SIZE][SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  addMatrices(matrix, matrix2);

  // Print the resulting matrix
  printf("Result of addition:\n");
  printMatrix();

  // Subtract two matrices
  subtractMatrices(matrix, matrix2);

  // Print the resulting matrix
  printf("Result of subtraction:\n");
  printMatrix();

  // Multiply two matrices
  int matrix3[SIZE][SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };

  multiplyMatrices(matrix, matrix3);

  // Print the resulting matrix
  printf("Result of multiplication:\n");
  printMatrix();

  // Transpose a matrix
  transposeMatrix(matrix);

  // Print the resulting matrix
  printf("Result of transposition:\n");
  printMatrix();

  // Find the determinant of a matrix
  int det = determinant(matrix);

  // Print the determinant
  printf("Determinant: %d\n", det);

  // Find the inverse of a matrix
  inverseMatrix(matrix);

  // Print the resulting matrix
  printf("Result of inversion:\n");
  printMatrix();

  return 0;
}