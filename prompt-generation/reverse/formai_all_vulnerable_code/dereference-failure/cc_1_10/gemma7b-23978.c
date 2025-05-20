//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10

int main()
{
  int **grid = NULL;
  int i, j, k;
  int num_percolation = 0;

  grid = (int**)malloc(DIM * sizeof(int*));
  for (i = 0; i < DIM; i++)
  {
    grid[i] = (int*)malloc(DIM * sizeof(int));
    for (j = 0; j < DIM; j++)
    {
      grid[i][j] = 0;
    }
  }

  srand(time(NULL));

  // Percolation
  for (k = 0; k < 1000; k++)
  {
    i = rand() % DIM;
    j = rand() % DIM;
    if (grid[i][j] == 0)
    {
      grid[i][j] = 1;
      num_percolation++;
    }
  }

  // Print the grid
  for (i = 0; i < DIM; i++)
  {
    for (j = 0; j < DIM; j++)
    {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  printf("Number of percolations: %d\n", num_percolation);

  return 0;
}