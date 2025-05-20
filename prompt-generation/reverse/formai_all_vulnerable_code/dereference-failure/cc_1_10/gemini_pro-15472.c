//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

// Generate a random matrix
int** generate_matrix(int n, int m) {
  int** matrix = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    matrix[i] = malloc(m * sizeof(int));
    for (int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 10;
    }
  }
  return matrix;
}

// Print a matrix
void print_matrix(int** matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Multiply two matrices
int** multiply_matrices(int** a, int n, int m, int** b, int p, int q) {
  if (m != p) {
    printf("Error: matrices cannot be multiplied\n");
    return NULL;
  }
  int** c = malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++) {
    c[i] = malloc(q * sizeof(int));
    for (int j = 0; j < q; j++) {
      c[i][j] = 0;
      for (int k = 0; k < m; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

// Free the memory allocated for a matrix
void free_matrix(int** matrix, int n) {
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  srand(time(NULL));

  int** a = generate_matrix(N, M);
  int** b = generate_matrix(M, N);
  int** c = multiply_matrices(a, N, M, b, N, M);

  printf("Matrix A:\n");
  print_matrix(a, N, M);

  printf("Matrix B:\n");
  print_matrix(b, M, N);

  printf("Matrix C (A * B):\n");
  print_matrix(c, N, M);

  free_matrix(a, N);
  free_matrix(b, M);
  free_matrix(c, N);

  return 0;
}