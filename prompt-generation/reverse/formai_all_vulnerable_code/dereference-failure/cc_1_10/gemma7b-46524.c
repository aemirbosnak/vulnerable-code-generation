//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

void watermark(int **a, int n, int k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      a[i][j] = (int)round(a[i][j] + sin(i) * sin(j));
    }
  }
}

int main() {
  int n, k;
  scanf("Enter the number of rows: ", &n);
  scanf("Enter the number of columns: ", &k);

  int **a = (int **)malloc(n * sizeof(int *)), **b = (int **)malloc(n * sizeof(int *)), **c = (int **)malloc(n * sizeof(int *)), **d = (int **)malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(k * sizeof(int));
    b[i] = (int *)malloc(k * sizeof(int));
    c[i] = (int *)malloc(k * sizeof(int));
    d[i] = (int *)malloc(k * sizeof(int));
  }

  // Generate the watermark
   watermark(a, n, k);

  // Copy the watermark to the other matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      b[i][j] = a[i][j];
      c[i][j] = a[i][j];
      d[i][j] = a[i][j];
    }
  }

  // Print the matrices
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      printf("%d ", a[i][j]);
      printf("%d ", b[i][j]);
      printf("%d ", c[i][j]);
      printf("%d ", d[i][j]);
      printf("\n");
    }
  }

  free(a);
  free(b);
  free(c);
  free(d);

  return 0;
}