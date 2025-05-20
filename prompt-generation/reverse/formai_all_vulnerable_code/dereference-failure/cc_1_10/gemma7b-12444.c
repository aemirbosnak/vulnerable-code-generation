//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIM_SIZE 256

int main()
{
    int **grid = NULL;
    int num_sim_size = MAX_SIM_SIZE;
    int i, j, k, iteration = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(num_sim_size * sizeof(int *));
    for (i = 0; i < num_sim_size; i++)
    {
        grid[i] = (int *)malloc(num_sim_size * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < num_sim_size; i++)
    {
        for (j = 0; j < num_sim_size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate Percolation
    while (!grid[num_sim_size - 1][num_sim_size - 1])
    {
        iteration++;

        // Randomly choose a cell
        i = rand() % num_sim_size;
        j = rand() % num_sim_size;

        // If the cell is not already saturated and has a neighbor to the right
        if (grid[i][j] == 0 && grid[i][j + 1] == 1)
        {
            // Saturate the cell
            grid[i][j] = 1;
        }
    }

    // Print the results
    printf("Number of iterations: %d\n", iteration);

    // Free the memory
    for (i = 0; i < num_sim_size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}