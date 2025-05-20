//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrix_multiplication(int **a, int **b, int **c, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      c[i][j] = 0;
      for (int k = 0; k < n; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main()
{
  int n = 1024;
  int **a = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    a[i] = (int *)malloc(n * sizeof(int));
  }

  int **b = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    b[i] = (int *)malloc(n * sizeof(int));
  }

  int **c = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    c[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      a[i][j] = rand() % 10;
      b[i][j] = rand() % 10;
    }
  }

  clock_t start, end;
  start = clock();
  matrix_multiplication(a, b, c, n);
  end = clock();

  printf("Time taken for matrix multiplication: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  free(a);
  free(b);
  free(c);

  return 0;
}