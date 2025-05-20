//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void recurse(int n, int order, double **arr, double sr, double **coeffs) {
  if (n == 0) {
    return;
  }

  double **temp_arr = (double **)malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    temp_arr[i] = (double *)malloc(order * sizeof(double));
  }

  recurse(n - 1, order, temp_arr, sr, coeffs);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < order; j++) {
      coeffs[i][j] = 0.0;
    }
  }

  free(temp_arr);
}

int main() {
  int n = 5;
  int order = 3;
  double sr = 1.0;
  double **arr = (double **)malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    arr[i] = (double *)malloc(order * sizeof(double));
  }

  double **coeffs = (double **)malloc(n * sizeof(double *));
  for (int i = 0; i < n; i++) {
    coeffs[i] = (double *)malloc(order * sizeof(double));
  }

  recurse(n, order, arr, sr, coeffs);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < order; j++) {
      printf("%f ", coeffs[i][j]);
    }
    printf("\n");
  }

  free(arr);
  free(coeffs);

  return 0;
}