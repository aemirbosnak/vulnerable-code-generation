//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void matrix_operations(int **a, int **b, int **c)
{
  int i, j, k;
  int r = ROWS;
  int c1 = COLS;
  int c2 = COLS;

  *c = (int *)malloc(r * c1 * c2 * sizeof(int));

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c1; j++)
    {
      c[i][j] = 0;
      for (k = 0; k < c2; k++)
      {
        if (a[i][k] && b[k][j])
          c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main()
{
  int **a = (int **)malloc(ROWS * COLS * sizeof(int));
  int **b = (int **)malloc(ROWS * COLS * sizeof(int));
  int **c = NULL;

  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      a[i][j] = rand() % 10;
      b[i][j] = rand() % 10;
    }
  }

  matrix_operations(a, b, &c);

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