//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <math.h>

void recurse(int n, float **arr, float **coeff) {
  if (n == 0) {
    return;
  }

  recurse(n - 1, arr, coeff);

  float **temp_arr = (float **)malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    temp_arr[i] = (float *)malloc(n * sizeof(float));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp_arr[i][j] = arr[i][j] * coeff[i][j];
    }
  }

  free(temp_arr);
}

int main() {
  int n = 5;
  float **arr = (float **)malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    arr[i] = (float *)malloc(n * sizeof(float));
  }

  float **coeff = (float **)malloc(n * sizeof(float *));
  for (int i = 0; i < n; i++) {
    coeff[i] = (float *)malloc(n * sizeof(float));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = rand() % 10;
      coeff[i][j] = rand() % 3;
    }
  }

  recurse(n, arr, coeff);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%f ", arr[i][j]);
    }
  }

  printf("\n");

  free(arr);
  free(coeff);

  return 0;
}