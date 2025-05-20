//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 50

int main()
{
    int **grid = NULL;
    int i, j, k, seed, occupied = 0;

    // Allocate memory
    grid = (int **)malloc(DIM * sizeof(int *));
    for(i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
    }

    // Initialize grid
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed random number generator
    seed = time(NULL);
    srand(seed);

    // Occupy random cells
    for(k = 0; k < occupied; k++)
    {
        i = rand() % DIM;
        j = rand() % DIM;
        grid[i][j] = 1;
    }

    // Print grid
    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for(i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}