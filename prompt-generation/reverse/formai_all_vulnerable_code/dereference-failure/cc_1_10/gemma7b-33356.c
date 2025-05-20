//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void percolat(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == 1)
      {
        int k = 0;
        for (int r = i - 1; r >= 0 && arr[r][j] == 0; r--)
          arr[r][j] = 1;
        for (int c = j - 1; c >= 0 && arr[i][c] == 0; c--)
          arr[i][c] = 1;
      }
    }
  }
}

int main()
{
  int n = MAX;
  int **arr = (int **)malloc(n * sizeof(int *) + 1);
  for (int i = 0; i < n; i++)
    arr[i] = (int *)malloc(n * sizeof(int) + 1);

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