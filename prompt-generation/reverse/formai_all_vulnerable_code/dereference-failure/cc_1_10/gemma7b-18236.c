//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void percolate(int **arr, int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr[i][j] > 0)
      {
        int r = rand() % 4;
        switch (r)
        {
          case 0:
            arr[i][j] += 1;
            break;
          case 1:
            arr[i][j] -= 1;
            break;
          case 2:
            arr[i][j] *= 2;
            break;
          case 3:
            arr[i][j] /= 2;
            break;
        }
      }
    }
  }
}

int main()
{
  int n = 10;
  int m = 10;
  int **arr = (int **)malloc(n * sizeof(int *) + m * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(m * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      arr[i][j] = rand() % 2;
    }
  }

  percolate(arr, n, m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);

  return 0;
}