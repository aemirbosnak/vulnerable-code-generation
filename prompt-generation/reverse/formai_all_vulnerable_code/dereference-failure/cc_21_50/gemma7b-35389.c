//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20

#define MAX_ITERATIONS 1000

#define FILL_PERCENTAGE 0.5

int main()
{
    int i, j, iteration = 0, **grid = NULL, is_wet = 0;
    time_t t;

    // Allocate memory for the grid
    grid = (int**)malloc(DIM * sizeof(int*));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int*)malloc(DIM * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate filling the grid
    srand(time(NULL));
    for (i = 0; i < DIM * DIM * FILL_PERCENTAGE; i++)
    {
        int x = rand() % DIM;
        int y = rand() % DIM;
        grid[x][y] = 1;
    }

    // Percolation algorithm
    while (iteration < MAX_ITERATIONS)
    {
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 1)
                {
                    // Check if the cell is wet on the left
                    if (j > 0 && grid[i][j - 1] == 1)
                    {
                        grid[i][j] = 2;
                    }

                    // Check if the cell is wet on the right
                    if (j < DIM - 1 && grid[i][j + 1] == 1)
                    {
                        grid[i][j] = 2;
                    }

                    // Check if the cell is wet above
                    if (i > 0 && grid[i - 1][j] == 1)
                    {
                        grid[i][j] = 2;
                    }

                    // Check if the cell is wet below
                    if (i < DIM - 1 && grid[i + 1][j] == 1)
                    {
                        grid[i][j] = 2;
                    }
                }
            }
        }

        // Check if the grid is wet
        for (i = 0; i < DIM; i++)
        {
            for (j = 0; j < DIM; j++)
            {
                if (grid[i][j] == 2)
                {
                    is_wet = 1;
                }
            }
        }

        // Increment the iteration if the grid is not wet
        if (!is_wet)
        {
            iteration++;
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

    // Free memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}