//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
  
  int n, m;
  
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  printf("Enter the number of columns: ");
  scanf("%d", &m);

  int matrix[n][m];

  // populate the matrix with user input
  printf("Enter the elements of the matrix: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  // print the original matrix
  printf("\nOriginal Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // perform matrix operations
  printf("\nPerforming matrix operations...\n");

  // scalar multiplication
  int scalar;
  printf("\nEnter a scalar value to multiply with: ");
  scanf("%d", &scalar);
  printf("\nScalar Multiplication:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] *= scalar;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // matrix addition
  int matrix2[n][m];
  printf("\nEnter a new matrix to add with the original matrix: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%d", &matrix2[i][j]);
    }
  }
  printf("\nMatrix Addition:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] += matrix2[i][j];
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // matrix multiplication
  int p;
  printf("\nEnter the number of columns for the second matrix: ");
  scanf("%d", &p);

  int matrix3[m][p];
  printf("\nEnter a new matrix to multiply with the original matrix: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("Element [%d][%d]: ", i, j);
      scanf("%d", &matrix3[i][j]);
    }
  }

  int result[n][p];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      result[i][j] = 0;
      for (int k = 0; k < m; k++) {
        result[i][j] += matrix[i][k] * matrix3[k][j];
      }
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}