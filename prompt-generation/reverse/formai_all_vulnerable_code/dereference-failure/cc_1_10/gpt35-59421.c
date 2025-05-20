//FormAI DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>

void printMatrix(int rows, int cols, int arr[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

void matrixAddition(int rows, int cols, int arr1[rows][cols], int arr2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = arr1[i][j] + arr2[i][j];
    }
  }
}

void matrixSubtraction(int rows, int cols, int arr1[rows][cols], int arr2[rows][cols], int result[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = arr1[i][j] - arr2[i][j];
    }
  }
}

void matrixMultiplication(int rowsA, int colsA, int rowsB, int colsB, int arr1[rowsA][colsA], int arr2[rowsB][colsB], int result[rowsA][colsB]) {
  if (colsA != rowsB) {
    printf("Invalid matrix dimensions!");
    return;
  }
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      result[i][j] = 0;
      for (int k = 0; k < colsA; k++) {
        result[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
}

int main() {
  int matrixA[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int matrixB[3][2] = {{2, 4}, {6, 8}, {10, 12}};
  int matrixC[2][3] = {{1, 2, 3}, {4, 5, 6}};
  
  printf("Matrix A:\n");
  printMatrix(3, 2, matrixA);

  printf("\nMatrix B:\n");
  printMatrix(3, 2, matrixB);

  int matrixSum[3][2];
  matrixAddition(3, 2, matrixA, matrixB, matrixSum);
  printf("\nMatrix Sum:\n");
  printMatrix(3, 2, matrixSum);

  int matrixDiff[3][2];
  matrixSubtraction(3, 2, matrixA, matrixB, matrixDiff);
  printf("\nMatrix Difference:\n");
  printMatrix(3, 2, matrixDiff);

  int matrixProduct[3][2];
  matrixMultiplication(3, 2, 2, 3, matrixA, matrixC, matrixProduct);
  printf("\nMatrix Product:\n");
  printMatrix(3, 3, matrixProduct);

  return 0;
}