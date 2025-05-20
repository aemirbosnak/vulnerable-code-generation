//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int x, y;

    // Allocate memory for the grid
    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (x = 0; x < MAX_SIZE; x++)
    {
        grid[x] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < MAX_SIZE; x++)
    {
        for (y = 0; y < MAX_SIZE; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Percolation simulation
    int num_iter = 0;
    while (!percolation(grid, MAX_SIZE, MAX_SIZE))
    {
        num_iter++;
    }

    // Print the results
    printf("Number of iterations: %d\n", num_iter);

    // Free the memory
    for (x = 0; x < MAX_SIZE; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}

int percolation(int **grid, int x_size, int y_size)
{
    int i, j, k, l;
    int num_wet = 0;

    // Iterate over the grid
    for (i = 0; i < x_size; i++)
    {
        for (j = 0; j < y_size; j++)
        {
            // If the cell is wet, increment the number of wet cells
            if (grid[i][j] == 1)
            {
                num_wet++;
            }
            // Iterate over the neighbors of the current cell
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    // If the neighbor cell is not wet and it is within the bounds of the grid, and the current cell is wet
                    if (grid[i + k][j + l] == 0 && k != 0 && l != 0 && i + k >= 0 && i + k < x_size && j + l >= 0 && j + l < y_size)
                    {
                        // Set the neighbor cell to wet
                        grid[i + k][j + l] = 1;
                    }
                }
            }
        }
    }

    // If the number of wet cells is equal to the number of cells in the grid, return 1
    return num_wet == x_size * y_size;
}