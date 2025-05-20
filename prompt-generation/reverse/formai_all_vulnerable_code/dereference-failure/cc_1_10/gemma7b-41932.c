//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 10
#define MAX_SIM 1000

int main()
{
    int **grid = NULL;
    int i, j, k, sim_num = 0;
    srand(time(NULL));

    grid = (int **)malloc(DIM * sizeof(int *));
    for (i = 0; i < DIM; i++)
    {
        grid[i] = (int *)malloc(DIM * sizeof(int));
        for (j = 0; j < DIM; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate MAX_SIM iterations
    for (sim_num = 0; sim_num < MAX_SIM; sim_num++)
    {
        // Randomly choose two cells
        i = rand() % DIM;
        j = rand() % DIM;

        // If both cells are empty, fill the lower one
        if (grid[i][j] == 0 && grid[i][j - 1] == 1)
        {
            grid[i][j] = 1;
        }
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

    // Free memory
    for (i = 0; i < DIM; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}