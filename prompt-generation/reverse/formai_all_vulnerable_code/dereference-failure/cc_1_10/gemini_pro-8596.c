//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000L

int main() {
  struct timespec start, end;
  double elapsed;
  int i, j, k;
  int **a, **b, **c;

  // Allocate matrices
  a = malloc(sizeof(int *) * 1000);
  b = malloc(sizeof(int *) * 1000);
  c = malloc(sizeof(int *) * 1000);
  for (i = 0; i < 1000; i++) {
    a[i] = malloc(sizeof(int) * 1000);
    b[i] = malloc(sizeof(int) * 1000);
    c[i] = malloc(sizeof(int) * 1000);
  }

  // Initialize matrices
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      a[i][j] = rand();
      b[i][j] = rand();
      c[i][j] = 0;
    }
  }

  // Start timer
  clock_gettime(CLOCK_REALTIME, &start);

  // Perform matrix multiplication
  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      for (k = 0; k < 1000; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Stop timer
  clock_gettime(CLOCK_REALTIME, &end);

  // Calculate elapsed time
  elapsed = (end.tv_sec - start.tv_sec) +
            ((end.tv_nsec - start.tv_nsec) / BILLION);

  // Print elapsed time
  printf("Elapsed time: %f seconds\n", elapsed);

  // Free matrices
  for (i = 0; i < 1000; i++) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}