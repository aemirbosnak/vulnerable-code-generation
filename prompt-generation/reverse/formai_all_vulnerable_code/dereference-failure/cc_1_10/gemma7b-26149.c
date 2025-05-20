//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void matrix_operations(int **a, int **b, int **c)
{
  int i, j, k;
  int r = ROWS;
  int c2 = COLS;

  c = (int **)malloc(r * sizeof(int *) + c2 * sizeof(int));
  for (i = 0; i < r; i++)
    c[i] = (int *)malloc(c2 * sizeof(int));

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c2; j++)
    {
      c[i][j] = 0;
      for (k = 0; k < COLS; k++)
      {
        if (a[i][k] && b[k][j])
          c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  free(c);
}

int main()
{
  int **a = (int **)malloc(ROWS * sizeof(int *) + COLS * sizeof(int));
  for (int i = 0; i < ROWS; i++)
    a[i] = (int *)malloc(COLS * sizeof(int));

  int **b = (int **)malloc(ROWS * sizeof(int *) + COLS * sizeof(int));
  for (int i = 0; i < ROWS; i++)
    b[i] = (int *)malloc(COLS * sizeof(int));

  int **c = NULL;

  a[0][0] = 1;
  a[0][1] = 2;
  a[1][0] = 3;
  a[1][1] = 4;
  a[2][0] = 5;
  a[2][1] = 6;

  b[0][0] = 7;
  b[0][1] = 8;
  b[1][0] = 9;
  b[1][1] = 10;
  b[2][0] = 11;
  b[2][1] = 12;

  matrix_operations(a, b, c);

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
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