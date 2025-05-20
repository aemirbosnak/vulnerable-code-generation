//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIM_SIZE 10

int main()
{
    int i, j, sim_size, num_percolation_sites = 0;
    int** grid = NULL;
    int** occupied_sites = NULL;

    sim_size = MAX_SIM_SIZE;
    grid = (int**)malloc(sim_size * sizeof(int*));
    for (i = 0; i < sim_size; i++)
    {
        grid[i] = (int*)malloc(sim_size * sizeof(int));
    }

    occupied_sites = (int**)malloc(sim_size * sizeof(int*));
    for (i = 0; i < sim_size; i++)
    {
        occupied_sites[i] = (int*)malloc(sim_size * sizeof(int));
    }

    // Percolation Simulation
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            if (rand() % 2 == 0)
            {
                occupied_sites[i][j] = 1;
                num_percolation_sites++;
            }
        }
    }

    printf("Number of percolating sites: %d\n", num_percolation_sites);

    // Free Memory
    for (i = 0; i < sim_size; i++)
    {
        free(grid[i]);
        free(occupied_sites[i]);
    }
    free(grid);
    free(occupied_sites);

    return 0;
}