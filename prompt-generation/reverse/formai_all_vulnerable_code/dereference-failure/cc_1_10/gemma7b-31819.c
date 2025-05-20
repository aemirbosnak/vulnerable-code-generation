//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define DIM 5

void percol_sim()
{
  int **arr = (int **)malloc(DIM * sizeof(int *));
  for (int i = 0; i < DIM; i++)
  {
    arr[i] = (int *)malloc(DIM * sizeof(int));
  }

  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      arr[i][j] = rand() % 2;
    }
  }

  int connected_components = 0;
  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      if (arr[i][j] == 1)
      {
        connected_components++;
        arr[i][j] = -1;
        // Recursively connect adjacent cells
        if (i > 0 && arr[i - 1][j] == 1)
          arr[i - 1][j] = -1;
        if (j > 0 && arr[i][j - 1] == 1)
          arr[i][j - 1] = -1;
        if (i < DIM - 1 && arr[i + 1][j] == 1)
          arr[i + 1][j] = -1;
        if (j < DIM - 1 && arr[i][j + 1] == 1)
          arr[i][j + 1] = -1;
      }
    }
  }

  printf("Number of connected components: %d\n", connected_components);

  free(arr);
}

int main()
{
  percol_sim();
  return 0;
}