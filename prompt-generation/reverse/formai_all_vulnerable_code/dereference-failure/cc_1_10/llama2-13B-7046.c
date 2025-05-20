//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform matrix multiplication
void matrixMultiply(float *A, int m, int n, float *B, int p, int q) {
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      float sum = 0;
      for (k = 0; k < p; k++) {
        sum += A[i * n + j] * B[k * q + i];
      }
      A[i * n + j] = sum;
    }
  }
}

// Function to perform matrix addition
void matrixAdd(float *A, int m, int n, float *B, int p, int q) {
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      A[i * n + j] += B[i * q + j];
    }
  }
}

// Function to perform matrix transpose
void matrixTranspose(float *A, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      float temp = A[i * n + j];
      A[i * n + j] = A[j * n + i];
      A[j * n + i] = temp;
    }
  }
}

int main() {
  int m = 3; // size of A
  int n = 4; // size of B
  int p = 2; // size of C
  float *A, *B, *C;

  // Initialize matrices
  A = (float *)calloc(m * n, sizeof(float));
  B = (float *)calloc(p * n, sizeof(float));
  C = (float *)calloc(m * p, sizeof(float));

  // Set matrix values
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      A[i * n + j] = i * j;
    }
  }
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < n; j++) {
      B[i * n + j] = i * j + 1;
    }
  }

  // Perform matrix multiplication
  matrixMultiply(A, m, n, B, p, n);

  // Print result
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("%.2f ", C[i * p + j]);
    }
    printf("\n");
  }

  // Perform matrix addition
  matrixAdd(A, m, n, B, p, n);

  // Print result
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.2f ", C[i * n + j]);
    }
    printf("\n");
  }

  // Perform matrix transpose
  matrixTranspose(A, m, n);

  // Print result
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.2f ", A[i * n + j]);
    }
    printf("\n");
  }

  free(A);
  free(B);
  free(C);
  return 0;
}