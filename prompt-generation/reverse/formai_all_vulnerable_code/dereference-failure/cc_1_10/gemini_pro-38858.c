//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 1000000

int main(int argc, char **argv) {
  int i, j, k;
  double x, y, z;

  // Allocate memory for arrays
  double *a = (double *)malloc(N * sizeof(double));
  double *b = (double *)malloc(N * sizeof(double));
  double *c = (double *)malloc(N * sizeof(double));

  // Initialize arrays
  for (i = 0; i < N; i++) {
    a[i] = i;
    b[i] = 2 * i;
    c[i] = 0.0;
  }

  // Start timer
  clock_t start = clock();

  // Perform operations
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        c[i] += a[j] * b[k];
      }
    }
  }

  // Stop timer
  clock_t end = clock();

  // Calculate elapsed time
  double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

  // Print results
  printf("Elapsed time: %f seconds\n", elapsed);
  printf("c[0]: %f\n", c[0]);
  printf("c[N-1]: %f\n", c[N - 1]);

  // Free memory
  free(a);
  free(b);
  free(c);

  return 0;
}