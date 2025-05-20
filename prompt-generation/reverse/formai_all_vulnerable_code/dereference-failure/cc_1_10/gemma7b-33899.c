//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the Percolation grid
    int **grid = NULL;
    int rows = 10;
    int cols = 10;
    grid = malloc(rows * sizeof(int *) + cols * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = malloc(cols * sizeof(int));
    }

    // Initialize the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    // Simulate Percolation
    int num_steps = 1000;
    for (int step = 0; step < num_steps; step++)
    {
        // Randomly select a cell
        int row = rand() % rows;
        int col = rand() % cols;

        // If the cell is not already saturated and has a neighbor to the right
        if (grid[row][col] == 0 && grid[row][col - 1] == 1)
        {
            // Saturate the cell
            grid[row][col] = 1;
        }
    }

    // Print the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}