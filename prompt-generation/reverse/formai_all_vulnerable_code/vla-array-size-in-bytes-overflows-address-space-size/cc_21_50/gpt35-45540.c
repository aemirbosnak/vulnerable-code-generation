//FormAI DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>

int main() {
  
  int n, m;
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  printf("Enter the number of columns: ");
  scanf("%d", &m);

  int matrixA[n][m], matrixB[n][m], result[n][m];
  
  printf("Enter values for matrix A:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("Enter value for A[%d][%d]: ", i, j);
      scanf("%d", &matrixA[i][j]);
    }
  }

  printf("Enter values for matrix B:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("Enter value for B[%d][%d]: ", i, j);
      scanf("%d", &matrixB[i][j]);
    }
  }

  printf("Matrix A:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d\t", matrixA[i][j]);
    }
    printf("\n");
  }

  printf("Matrix B:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d\t", matrixB[i][j]);
    }
    printf("\n");
  }

  // Addition
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      result[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }

  printf("Addition:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  // Subtraction
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      result[i][j] = matrixA[i][j] - matrixB[i][j];
    }
  }

  printf("Subtraction:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  // Multiplication
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      result[i][j] = 0;
      for(int k=0; k<n; k++) {
        result[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  printf("Multiplication:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}