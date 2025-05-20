//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to create a matrix
int** createMatrix(int rows, int cols) {
  int** matrix = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int*)malloc(cols * sizeof(int));
  }
  return matrix;
}

// Function to free the memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to add two matrices
int** addMatrices(int** A, int** B, int rows, int cols) {
  int** C = createMatrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}

// Function to subtract two matrices
int** subtractMatrices(int** A, int** B, int rows, int cols) {
  int** C = createMatrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  return C;
}

// Function to multiply two matrices
int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int rowsB, int colsB) {
  if (colsA != rowsB) {
    printf("Matrices cannot be multiplied\n");
    return NULL;
  }
  int** C = createMatrix(rowsA, colsB);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      C[i][j] = 0;
      for (int k = 0; k < colsA; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

int main() {
  int rowsA, colsA, rowsB, colsB;
  printf("Enter the number of rows and columns for matrix A: ");
  scanf("%d %d", &rowsA, &colsA);
  int** A = createMatrix(rowsA, colsA);
  printf("Enter the elements of matrix A:\n");
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter the number of rows and columns for matrix B: ");
  scanf("%d %d", &rowsB, &colsB);
  int** B = createMatrix(rowsB, colsB);
  printf("Enter the elements of matrix B:\n");
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  int choice;
  do {
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Exit\n");
    scanf("%d", &choice);

    int** C;
    switch (choice) {
    case 1:
      C = addMatrices(A, B, rowsA, colsA);
      printf("The sum of the two matrices is:\n");
      printMatrix(C, rowsA, colsA);
      freeMatrix(C, rowsA);
      break;
    case 2:
      C = subtractMatrices(A, B, rowsA, colsA);
      printf("The difference of the two matrices is:\n");
      printMatrix(C, rowsA, colsA);
      freeMatrix(C, rowsA);
      break;
    case 3:
      C = multiplyMatrices(A, B, rowsA, colsA, rowsB, colsB);
      if (C != NULL) {
        printf("The product of the two matrices is:\n");
        printMatrix(C, rowsA, colsB);
        freeMatrix(C, rowsA);
      }
      break;
    case 4:
      printf("Exiting program...\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  } while (choice != 4);

  freeMatrix(A, rowsA);
  freeMatrix(B, rowsB);
  return 0;
}