//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c, int n)
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
  int n = 3;
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

  a[0][0] = 1;
  a[0][1] = 2;
  a[0][2] = 3;
  a[1][0] = 4;
  a[1][1] = 5;
  a[1][2] = 6;
  a[2][0] = 7;
  a[2][1] = 8;
  a[2][2] = 9;

  b[0][0] = 2;
  b[0][1] = 3;
  b[0][2] = 4;
  b[1][0] = 5;
  b[1][1] = 6;
  b[1][2] = 7;
  b[2][0] = 8;
  b[2][1] = 9;
  b[2][2] = 10;

  matrix_operations(a, b, c, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  free(a);
  free(b);
  free(c);

  return 0;
}