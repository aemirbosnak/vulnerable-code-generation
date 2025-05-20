//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

void displayMatrix(int **matrix, int rows, int cols) {
  printf("\nMatrix:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void fillMatrix(int **matrix, int rows, int cols) {
  printf("Enter matrix elements:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int** createMatrix(int rows, int cols) {
  int** matrix = (int**) malloc(rows * sizeof(int*));
  for(int i = 0; i < rows; i++) {
    matrix[i] = (int*) malloc(cols * sizeof(int));
  }
  return matrix;
}

void freeMatrix(int **matrix, int rows) {
  for(int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

void transposeMatrix(int** matrix, int rows, int cols) {
  int** temp = createMatrix(cols, rows);
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      temp[j][i] = matrix[i][j];
    }
  }
  freeMatrix(matrix, rows);
  displayMatrix(temp, cols, rows);
}

void addMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
  if(rows1 != rows2 || cols1 != cols2) {
    printf("Cannot add matrices of different sizes.\n");
    return;
  }
  int** sumMatrix = createMatrix(rows1, cols1);
  for(int i = 0; i < rows1; i++) {
    for(int j = 0; j < cols1; j++) {
      sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
  displayMatrix(sumMatrix, rows1, cols1);
}

void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
  if(cols1 != rows2) {
    printf("Cannot multiply matrices of incompatible sizes. Number of columns in matrix 1 must match number of rows in matrix 2.\n");
    return;
  }
  int** productMatrix = createMatrix(rows1, cols2);
  for(int i = 0; i < rows1; i++) {
    for(int j = 0; j < cols2; j++) {
      int sum = 0;
      for(int k = 0; k < cols1; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      productMatrix[i][j] = sum;
    }
  }
  displayMatrix(productMatrix, rows1, cols2);
}

int main() {
  int option, rows1, cols1, rows2, cols2;
  printf("Enter number of rows and columns for matrix 1:\n");
  scanf("%d %d", &rows1, &cols1);
  int** matrix1 = createMatrix(rows1, cols1);
  fillMatrix(matrix1, rows1, cols1);
  printf("\nEnter number of rows and columns for matrix 2:\n");
  scanf("%d %d", &rows2, &cols2);
  int** matrix2 = createMatrix(rows2, cols2);
  fillMatrix(matrix2, rows2, cols2);
  printf("\n1. Transpose matrix 1.\n2. Transpose matrix 2.\n3. Add matrices.\n4. Multiply matrices.\n");
  printf("Enter option:\n");
  scanf("%d", &option);
  switch(option) {
    case 1: transposeMatrix(matrix1, rows1, cols1);
            break;
    case 2: transposeMatrix(matrix2, rows2, cols2);
            break;
    case 3: addMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
            break;
    case 4: multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
            break;
    default: printf("Invalid option.\n");
  }
  freeMatrix(matrix1, rows1);
  freeMatrix(matrix2, rows2);
  return 0;
}