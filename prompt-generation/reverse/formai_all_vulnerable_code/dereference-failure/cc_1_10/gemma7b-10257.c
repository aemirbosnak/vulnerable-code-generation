//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the grid of cells
    int **grid = NULL;
    int rows = 10;
    int cols = 10;
    grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid with random values
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = rand() % 2;
        }
    }

    // Simulate percolations
    int num_percolations = 0;
    while (num_percolations < 10)
    {
        // Choose a random cell
        int row = rand() % rows;
        int col = rand() % cols;

        // If the cell is not already percolated and it has a high value
        if (grid[row][col] == 1 && grid[row][col] != -1)
        {
            // Percolates the cell
            grid[row][col] = -1;

            // Increment the number of percolations
            num_percolations++;
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