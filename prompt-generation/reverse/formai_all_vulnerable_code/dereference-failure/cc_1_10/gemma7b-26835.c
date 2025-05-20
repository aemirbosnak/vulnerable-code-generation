//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void percolat_sync(int **grid, int size)
{
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      if (grid[r][c] == 1)
      {
        int nr = r - 1;
        int nc = c - 1;
        if (nr >= 0 && grid[nr][c] == 0)
          grid[nr][c] = 1;
        nr = r + 1;
        if (nr < size && grid[nr][c] == 0)
          grid[nr][c] = 1;
        nc = c - 1;
        if (nc >= 0 && grid[r][nc] == 0)
          grid[r][nc] = 1;
        nc = c + 1;
        if (nc < size && grid[r][nc] == 0)
          grid[r][nc] = 1;
      }
    }
  }
}

int main()
{
  int size = MAX_SIZE;
  int **grid = (int **)malloc(size * sizeof(int *));
  for (int r = 0; r < size; r++)
  {
    grid[r] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the grid
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      grid[r][c] = 0;
    }
  }

  // Set some cells to 1
  grid[2][2] = 1;
  grid[3][3] = 1;
  grid[4][4] = 1;

  percolat_sync(grid, size);

  // Print the grid
  for (int r = 0; r < size; r++)
  {
    for (int c = 0; c < size; c++)
    {
      printf("%d ", grid[r][c]);
    }
    printf("\n");
  }

  // Free the memory
  for (int r = 0; r < size; r++)
  {
    free(grid[r]);
  }
  free(grid);

  return 0;
}