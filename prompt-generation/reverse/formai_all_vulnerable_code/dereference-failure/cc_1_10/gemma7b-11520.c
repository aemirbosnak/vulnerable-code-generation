//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolates(int **arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (arr[i][j] == 0)
      {
        int flag = 0;
        for (int k = 0; k < size; k++)
        {
          if (arr[k][j] == 1)
          {
            flag = 1;
            break;
          }
        }
        if (flag == 0)
        {
          arr[i][j] = 1;
        }
      }
    }
  }
}

int main()
{
  int size = MAX_SIZE;
  int **arr = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++)
  {
    arr[i] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the array
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      arr[i][j] = 0;
    }
  }

  // Percolates
  percolates(arr, size);

  // Print the array
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  free(arr);
  return 0;
}