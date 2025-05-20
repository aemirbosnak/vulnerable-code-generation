//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main() {
  int **a = NULL;
  int **b = NULL;
  int **c = NULL;

  a = (int **)malloc(MAX * sizeof(int *));
  b = (int **)malloc(MAX * sizeof(int *));
  c = (int **)malloc(MAX * sizeof(int *));

  for (int i = 0; i < MAX; i++) {
    a[i] = (int *)malloc(MAX * sizeof(int));
    b[i] = (int *)malloc(MAX * sizeof(int));
    c[i] = (int *)malloc(MAX * sizeof(int));
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      a[i][j] = rand() % 10;
      b[i][j] = rand() % 10;
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      free(a[i][j]);
      free(b[i][j]);
      free(c[i][j]);
    }
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }

  free(a);
  free(b);
  free(c);

  return 0;
}