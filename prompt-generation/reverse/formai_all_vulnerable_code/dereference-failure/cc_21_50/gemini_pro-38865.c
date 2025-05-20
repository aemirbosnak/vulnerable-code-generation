//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // Hey there, fellow kernel hackers! I'm here to show you how to do some rad matrix operations in C.

  // First, let's declare our matrices. We'll need two matrices, A and B, each of size n x m.
  int n, m;
  printf("Enter the number of rows and columns in the matrices: ");
  scanf("%d %d", &n, &m);

  int **A = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    A[i] = (int *)malloc(m * sizeof(int));
  }

  int **B = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    B[i] = (int *)malloc(m * sizeof(int));
  }

  // Now, let's fill our matrices with some random numbers.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = rand() % 10;
      B[i][j] = rand() % 10;
    }
  }

  // Let's print out our matrices to make sure they look good.
  printf("Matrix A:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }

  printf("Matrix B:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }

  // Now, let's perform some matrix operations. First, let's add A and B.
  int **C = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    C[i] = (int *)malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }

  // Let's print out the result.
  printf("Matrix C (A + B):\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  // Now, let's multiply A and B.
  int **D = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    D[i] = (int *)malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      D[i][j] = 0;
      for (int k = 0; k < m; k++) {
        D[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  // Let's print out the result.
  printf("Matrix D (A * B):\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", D[i][j]);
    }
    printf("\n");
  }

  // Finally, let's free the memory we allocated.
  for (int i = 0; i < n; i++) {
    free(A[i]);
    free(B[i]);
    free(C[i]);
    free(D[i]);
  }
  free(A);
  free(B);
  free(C);
  free(D);

  return 0;
}