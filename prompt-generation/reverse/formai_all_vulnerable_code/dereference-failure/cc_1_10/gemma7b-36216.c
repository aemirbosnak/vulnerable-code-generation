//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void percolat(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] > 0)
      {
        int r = rand() % 4;
        if (r == 0)
          arr[i][j] = 0;
      }
    }
  }
}

int main()
{
  int n = MAX;
  int **arr = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(n * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      arr[i][j] = rand() % 2;
    }
  }

  percolat(arr, n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}