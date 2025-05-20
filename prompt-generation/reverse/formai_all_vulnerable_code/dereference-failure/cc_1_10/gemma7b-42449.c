//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void percolate(int **arr, int n, int r)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == r)
      {
        arr[i][j] = 0;
        if (i > 0)
          arr[i - 1][j] = 1;
        if (j > 0)
          arr[i][j - 1] = 1;
        if (i < MAX - 1)
          arr[i + 1][j] = 1;
        if (j < MAX - 1)
          arr[i][j + 1] = 1;
      }
    }
  }
}

int main()
{
  int n, r;
  scanf("Enter the number of iterations: ", &n);
  scanf("Enter the number of rounds: ", &r);

  int **arr = (int **)malloc(MAX * MAX * sizeof(int));
  for (int i = 0; i < MAX; i++)
  {
    arr[i] = (int *)malloc(MAX * sizeof(int));
  }

  for (int i = 0; i < n; i++)
  {
    percolate(arr, MAX, r);
  }

  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}