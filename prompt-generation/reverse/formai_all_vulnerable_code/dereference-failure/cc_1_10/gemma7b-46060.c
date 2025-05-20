//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 5;
  int b = 3;
  int c = 2;
  int d = 4;

  int **matrixA = (int **)malloc(a * sizeof(int *));
  for (int i = 0; i < a; i++) {
    matrixA[i] = (int *)malloc(b * sizeof(int));
  }

  int **matrixB = (int **)malloc(c * sizeof(int *));
  for (int i = 0; i < c; i++) {
    matrixB[i] = (int *)malloc(d * sizeof(int));
  }

  // Matrix A elements
  matrixA[0][0] = 10;
  matrixA[0][1] = 20;
  matrixA[1][0] = 30;
  matrixA[1][1] = 40;

  // Matrix B elements
  matrixB[0][0] = 50;
  matrixB[0][1] = 60;
  matrixB[1][0] = 70;
  matrixB[1][1] = 80;

  // Multiplication of Matrix A and Matrix B
  int **matrixC = (int **)malloc((a + c) * sizeof(int *));
  for (int i = 0; i < a + c; i++) {
    matrixC[i] = (int *)malloc(b * sizeof(int));
  }

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < c; j++) {
      matrixC[i][j] = 0;
      for (int k = 0; k < b; k++) {
        matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  // Print Matrix C elements
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", matrixC[i][j]);
    }
    printf("\n");
  }

  free(matrixA);
  free(matrixB);
  free(matrixC);

  return 0;
}