//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 1000

int main()
{
    int **grid;
    int i, j, k, size, sim_size;
    int seed, percolate_count, drop_count;

    // Allocate memory
    sim_size = MAX_SIM_SIZE;
    grid = (int **)malloc(sim_size * sizeof(int *));
    for(i = 0; i < sim_size; i++)
    {
        grid[i] = (int *)malloc(sim_size * sizeof(int));
    }

    // Initialize the grid
    size = sim_size / 2;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolate the water
    percolate_count = 0;
    for(k = 0; k < 1000; k++)
    {
        i = rand() % size;
        j = rand() % size;
        if(grid[i][j] == 0)
        {
            grid[i][j] = 1;
            percolate_count++;
        }
    }

    // Count the drops
    drop_count = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(grid[i][j] == 1)
            {
                drop_count++;
            }
        }
    }

    // Print the results
    printf("Number of percolations: %d\n", percolate_count);
    printf("Number of drops: %d\n", drop_count);

    // Free the memory
    for(i = 0; i < sim_size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}