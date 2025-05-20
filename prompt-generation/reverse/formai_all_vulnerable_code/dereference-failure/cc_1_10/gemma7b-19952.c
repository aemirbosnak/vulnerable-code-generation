//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    // Define grid size and initialize variables
    int size = 10;
    double **grid = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (double*)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0.0;
        }
    }

    // Set up boundary conditions
    for (int i = 0; i < size; i++)
    {
        grid[0][i] = 20.0;
        grid[size - 1][i] = 20.0;
        grid[i][0] = 20.0;
        grid[i][size - 1] = 20.0;
    }

    // Simulate heat transfer
    int niter = 1000;
    for (int iter = 0; iter < niter; iter++)
    {
        for (int i = 1; i < size - 1; i++)
        {
            for (int j = 1; j < size - 1; j++)
            {
                double avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
                grid[i][j] = avg;
            }
        }
    }

    // Print the final grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%f ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}