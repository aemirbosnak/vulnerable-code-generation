//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

void draw_grid(int **grid);
void populate_grid(int **grid);
int simulate_game_of_life(int **grid);

int main()
{
  int **grid = NULL;
  int i, j, k;

  // Allocate memory for the grid
  grid = (int **)malloc(GRID_SIZE * sizeof(int *));
  for (i = 0; i < GRID_SIZE; i++)
    grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));

  // Populate the grid
  populate_grid(grid);

  // Simulate the game of life
  simulate_game_of_life(grid);

  // Draw the grid
  draw_grid(grid);

  // Free memory
  for (i = 0; i < GRID_SIZE; i++)
    free(grid[i]);
  free(grid);

  return 0;
}

void draw_grid(int **grid)
{
  int i, j;

  for (i = 0; i < GRID_SIZE; i++)
  {
    for (j = 0; j < GRID_SIZE; j++)
    {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

void populate_grid(int **grid)
{
  int i, j;
  srand(time(NULL));

  for (i = 0; i < GRID_SIZE; i++)
  {
    for (j = 0; j < GRID_SIZE; j++)
    {
      grid[i][j] = rand() % 2;
    }
  }
}

int simulate_game_of_life(int **grid)
{
  int i, j, k, neighbors;

  for (i = 0; i < GRID_SIZE; i++)
  {
    for (j = 0; j < GRID_SIZE; j++)
    {
      neighbors = 0;
      for (k = -1; k <= 1; k++)
      {
        if (i + k >= 0 && i + k < GRID_SIZE)
        {
          if (grid[i + k][j] == 1)
            neighbors++;
        }
      }
      for (k = -1; k <= 1; k++)
      {
        if (j + k >= 0 && j + k < GRID_SIZE)
        {
          if (grid[i][j + k] == 1)
            neighbors++;
        }
      }

      if (grid[i][j] == 1 && neighbors < 2)
        grid[i][j] = 0;
      else if (grid[i][j] == 0 && neighbors == 3)
        grid[i][j] = 1;
    }
  }

  return 0;
}