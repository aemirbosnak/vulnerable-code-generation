//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 256

void percolatesim(int **grid, int size)
{
  int i, j, k, rand_num;
  time_t t;

  t = time(NULL);
  srand(t);

  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      grid[i][j] = rand() % 2;
    }
  }

  for (k = 0; k < size; k++)
  {
    for (i = 0; i < size; i++)
    {
      for (j = 0; j < size; j++)
      {
        if (grid[i][j] == 1)
        {
          rand_num = rand() % 4;
          switch (rand_num)
          {
            case 0:
              grid[i][j] = 0;
              break;
            case 1:
              grid[i][j] = 1;
              break;
            case 2:
              if (i > 0) grid[i - 1][j] = 1;
              break;
            case 3:
              if (j > 0) grid[i][j - 1] = 1;
              break;
          }
        }
      }
    }
  }

  return;
}

int main()
{
  int size = MAX_SIZE;
  int **grid = NULL;

  grid = (int **)malloc(size * size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    grid[i] = (int *)malloc(size * sizeof(int));
  }

  percolatesim(grid, size);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  free(grid);

  return 0;
}