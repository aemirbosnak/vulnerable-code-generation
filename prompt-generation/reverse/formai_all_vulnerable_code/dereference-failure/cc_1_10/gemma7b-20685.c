//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 20
#define FILL 0.8
#define MAX_ITER 1000

// Percolation Simulation
int main()
{
    int **grid = NULL;
    int i, j, k, iter = 0;
    double rand_num;

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

    // Fill the grid randomly
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            rand_num = (double)rand() / RAND_MAX;
            if (rand_num < FILL)
            {
                grid[i][j] = 1;
            }
        }
    }

    // Iterate until the percolates or the maximum number of iterations is reached
    while (!percolates(grid) && iter < MAX_ITER)
    {
        iter++;
    }

    // Print the final grid
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

// Function to check if the grid percolates
int percolates(int **grid)
{
    int i, j, k, count = 0;

    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
            }
        }
    }

    if (count == DIM * DIM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}