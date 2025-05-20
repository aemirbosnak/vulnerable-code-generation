//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n = 10;
  int i, j, k, l;
  double x, y, z, w;

  // Allocate memory for a 2D array
  double **a = (double**)malloc(n * sizeof(double*));
  for (i = 0; i < n; i++) {
    a[i] = (double*)malloc(n * sizeof(double));
  }

  // Initialize the 2D array
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i][j] = 0.0;
    }
  }

  // Calculate the factorial of each element in the array
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      x = a[i][j];
      w = 1.0;
      for (k = 1; k <= x; k++) {
        w *= k;
      }
      a[i][j] = w;
    }
  }

  // Print the results
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f ", a[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  return 0;
}