//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5 // number of matrices
#define N 3 // size of matrices

// function to multiply matrices
void mat_mult(float (*A)[N], float (*B)[N], float (*C)[N]) {
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

// function to add two matrices
void mat_add(float (*A)[N], float (*B)[N], float (*C)[N]) {
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        C[i][j] += A[i][k] + B[i][k];
      }
    }
  }
}

// function to transpose a matrix
void mat_transpose(float (*A)[N], float (*B)[N]) {
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        B[j][k] = A[i][k];
      }
    }
  }
}

int main() {
  float (*A)[N] = malloc(N * sizeof(float[N]));
  float (*B)[N] = malloc(N * sizeof(float[N]));
  float (*C)[N] = malloc(N * sizeof(float[N]));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = i + j;
      B[i][j] = i - j;
    }
  }

  mat_transpose(A, B);
  mat_mult(A, B, C);
  mat_add(A, C, C);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%.2f ", C[i][j]);
    }
    printf("\n");
  }

  free(A);
  free(B);
  free(C);

  return 0;
}