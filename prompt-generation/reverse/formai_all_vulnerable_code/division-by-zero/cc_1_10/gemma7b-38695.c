//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n, m, i, j, k;
  scanf("Enter the dimensions of the grid: ", "%d %d", &n, &m);

  // Allocate memory for the grid
  int **grid = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    grid[i] = (int *)malloc(m * sizeof(int));
  }

  // Initialize the grid
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      grid[i][j] = 0;
    }
  }

  // Percolation simulation
  for (k = 0; k < 100; k++)
  {
    // Randomly select a cell
    i = rand() % n;
    j = rand() % m;

    // If the cell is not already saturated and the sum of its neighbors is greater than the threshold, saturate the cell
    if (grid[i][j] == 0 && (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] >= 3))
    {
      grid[i][j] = 1;
    }
  }

  // Print the saturated cells
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }

  // Free memory
  for (i = 0; i < n; i++)
  {
    free(grid[i]);
  }
  free(grid);

  return 0;
}