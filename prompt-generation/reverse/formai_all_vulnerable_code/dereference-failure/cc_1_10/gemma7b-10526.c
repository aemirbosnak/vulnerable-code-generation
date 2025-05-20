//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 20

int main()
{
    int sim_size = MAX_SIM_SIZE;
    int **grid = (int **)malloc(sim_size * sizeof(int *));
    for (int i = 0; i < sim_size; i++)
    {
        grid[i] = (int *)malloc(sim_size * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < sim_size; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate the Percolation process
    int num_steps = 0;
    while (!percolation_complete(grid, sim_size))
    {
        // Randomly choose a cell
        int row = rand() % sim_size;
        int col = rand() % sim_size;

        // If the cell is not already saturated and has a neighbor to the right
        if (grid[row][col] == 0 && grid[row][col + 1] == 1)
        {
            // Saturate the cell
            grid[row][col] = 1;

            // Increment the number of steps
            num_steps++;
        }
    }

    // Print the number of steps it took for the Percolation process to complete
    printf("Number of steps: %d\n", num_steps);

    // Free the memory allocated for the grid
    for (int i = 0; i < sim_size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int percolation_complete(int **grid, int sim_size)
{
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < sim_size; j++)
        {
            // If the cell is not saturated and has a neighbor to the right
            if (grid[i][j] == 0 && grid[i][j + 1] == 1)
            {
                return 0;
            }
        }
    }

    return 1;
}