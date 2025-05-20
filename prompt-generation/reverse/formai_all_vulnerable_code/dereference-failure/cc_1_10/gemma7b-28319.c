//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20

#define MAX_WATER_LEVEL 5

int main()
{
    int **grid = NULL;
    int water_level = MAX_WATER_LEVEL;

    // Allocate memory for the grid
    grid = malloc(DIM * sizeof(int *));
    for (int i = 0; i < DIM; i++)
    {
        grid[i] = malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate water percolation
    srand(time(NULL));
    for (int i = 0; i < water_level; i++)
    {
        int x = rand() % DIM;
        int y = rand() % DIM;
        grid[x][y] = 1;
    }

    // Print the grid
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}