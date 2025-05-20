//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void matrix_operations() {
  int **a = NULL;
  int **b = NULL;
  int **c = NULL;

  a = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    a[i] = (int *)malloc(5 * sizeof(int));
  }

  b = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    b[i] = (int *)malloc(5 * sizeof(int));
  }

  c = (int **)malloc(5 * sizeof(int *));
  for (int i = 0; i < 5; i++) {
    c[i] = (int *)malloc(5 * sizeof(int));
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      a[i][j] = i + j;
      b[i][j] = i - j;
      c[i][j] = a[i][j] + b[i][j];
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      free(a[i][j]);
    }
    free(a[i]);
  }

  free(a);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      free(b[i][j]);
    }
    free(b[i]);
  }

  free(b);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      free(c[i][j]);
    }
    free(c[i]);
  }

  free(c);
}

int main() {
  matrix_operations();

  return 0;
}