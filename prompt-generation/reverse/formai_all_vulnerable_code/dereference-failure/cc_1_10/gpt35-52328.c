//FormAI DATASET v1.0 Category: Matrix operations ; Style: random
// Welcome to the Matrix!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a matrix
void printMatrix(int** matrix, int rows, int columns) {
  for(int i=0;i<rows;i++) {
    for(int j=0;j<columns;j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
int** addMatrices(int** matrix1, int** matrix2, int rows, int columns) {
  int** result = (int**) malloc(rows * sizeof(int*));
  for(int i=0;i<rows;i++) {
    result[i] = (int*) malloc(columns * sizeof(int));
    for(int j=0;j<columns;j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  return result;
}

// Function to subtract two matrices
int** subtractMatrices(int** matrix1, int** matrix2, int rows, int columns) {
  int** result = (int**) malloc(rows * sizeof(int*));
  for(int i=0;i<rows;i++) {
    result[i] = (int*) malloc(columns * sizeof(int));
    for(int j=0;j<columns;j++) {
      result[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
  return result;
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int columns1, int rows2, int columns2) {
  int** result = (int**) malloc(rows1 * sizeof(int*));
  for(int i=0;i<rows1;i++) {
    result[i] = (int*) malloc(columns2 * sizeof(int));
    for(int j=0;j<columns2;j++) {
      result[i][j] = 0;
      for(int k=0;k<columns1;k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return result;
}

// Function to calculate the transpose of a matrix
int** transposeMatrix(int** matrix, int rows, int columns) {
  int** result = (int**) malloc(columns * sizeof(int*));
  for(int i=0;i<columns;i++) {
    result[i] = (int*) malloc(rows * sizeof(int));
    for(int j=0;j<rows;j++) {
      result[i][j] = matrix[j][i];
    }
  }
  return result;
}

int main() {
  srand(time(NULL));
  
  int rows1 = 3;
  int columns1 = 3;
  int rows2 = 3;
  int columns2 = 3;
  
  // Generate two random matrices
  int** matrix1 = (int**) malloc(rows1 * sizeof(int*));
  for(int i=0;i<rows1;i++) {
    matrix1[i] = (int*) malloc(columns1 * sizeof(int));
    for(int j=0;j<columns1;j++) {
      matrix1[i][j] = rand() % 10;
    }
  }
  
  int** matrix2 = (int**) malloc(rows2 * sizeof(int*));
  for(int i=0;i<rows2;i++) {
    matrix2[i] = (int*) malloc(columns2 * sizeof(int));
    for(int j=0;j<columns2;j++) {
      matrix2[i][j] = rand() % 10;
    }
  }
  
  printf("Matrix 1:\n");
  printMatrix(matrix1, rows1, columns1);
  printf("\n");
  
  printf("Matrix 2:\n");
  printMatrix(matrix2, rows2, columns2);
  printf("\n");
  
  // Add the two matrices
  printf("Matrix 1 + Matrix 2:\n");
  int** sum = addMatrices(matrix1, matrix2, rows1, columns1);
  printMatrix(sum, rows1, columns1);
  printf("\n");
  
  // Subtract the two matrices
  printf("Matrix 1 - Matrix 2:\n");
  int** difference = subtractMatrices(matrix1, matrix2, rows1, columns1);
  printMatrix(difference, rows1, columns1);
  printf("\n");
  
  // Multiply the two matrices
  printf("Matrix 1 * Matrix 2:\n");
  int** product = multiplyMatrices(matrix1, matrix2, rows1, columns1, rows2, columns2);
  printMatrix(product, rows1, columns2);
  printf("\n");
  
  // Transpose Matrix 1
  printf("Transpose of Matrix 1:\n");
  int** transpose = transposeMatrix(matrix1, rows1, columns1);
  printMatrix(transpose, columns1, rows1);
  printf("\n");
  
  return 0;
}