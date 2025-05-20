//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 10
#define FILL_PERCENTAGE 20

int main()
{
    int **grid = NULL;
    int i, j, k, seed, filled_cells = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Fill the grid randomly
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = rand() % 100 < FILL_PERCENTAGE ? 1 : 0;
            if (grid[i][j] == 1)
            {
                filled_cells++;
            }
        }
    }

    // Print the grid
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Print the number of filled cells
    printf("Number of filled cells: %d\n", filled_cells);

    // Free the memory
    for (i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}