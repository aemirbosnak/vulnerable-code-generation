//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

void initializeGrid(int **grid, int size)
{
    grid = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        grid[i] = 0;
    }
}

void updateGrid(int **grid, int size)
{
    int **newGrid = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        newGrid[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            if (grid[i][j] == 1 && neighbors >= 2)
            {
                newGrid[i][j] = 1;
            }
            else if (grid[i][j] == 0 && neighbors == 3)
            {
                newGrid[i][j] = 1;
            }
        }
    }

    free(grid);
    grid = newGrid;
}

int main()
{
    int **grid = NULL;
    initializeGrid(grid, GRID_SIZE);

    // Seed the random number generator
    srand(time(NULL));

    // Randomly set some cells to 1 (alive)
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (rand() % 2 == 0)
            {
                grid[i][j] = 1;
            }
        }
    }

    // Simulate game of life for 10 generations
    for (int generation = 0; generation < 10; generation++)
    {
        updateGrid(grid, GRID_SIZE);
    }

    // Print the final grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}