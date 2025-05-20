//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1024

int main()
{
  int size = MAX_SIZE;
  int **grid = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < size; i++)
  {
    grid[i] = (int *)malloc(size * sizeof(int));
  }

  // Initialize the grid
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      grid[i][j] = 0;
    }
  }

  // Percolation simulation
  int num_steps = 0;
  while (!percolation(grid, size, size, &num_steps))
  {
    // Do something, such as print a progress message
  }

  // Print the results
  printf("Number of steps: %d\n", num_steps);

  // Free the memory
  for (int i = 0; i < size; i++)
  {
    free(grid[i]);
  }
  free(grid);

  return 0;
}

int percolation(int **grid, int w, int h, int *num_steps)
{
  // Check if the grid is saturated
  if (is_saturated(grid, w, h))
  {
    return 1;
  }

  // Randomly select a cell
  int x = rand() % w;
  int y = rand() % h;

  // If the cell is not already saturated and the cell above it is saturated
  if (grid[x][y] == 0 && grid[x][y-1] == 1)
  {
    // Saturate the cell
    grid[x][y] = 1;

    // Increment the number of steps
    *num_steps++;

    // Recursively saturate the connected cells
    percolation(grid, w, h, num_steps);
  }

  return 0;
}

int is_saturated(int **grid, int w, int h)
{
  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < h; j++)
    {
      if (grid[i][j] == 0)
      {
        return 0;
      }
    }
  }

  return 1;
}