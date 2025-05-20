//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_ITERATIONS 1000

int main()
{
    // Allocate memory for the grid
    int **grid = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        grid[i] = (int *)malloc(10 * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate the percolations
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
    {
        // Generate a random number between 0 and 9
        int x = rand() % 10;
        int y = rand() % 10;

        // If the cell is not already saturated and the sum of its neighbors is greater than the threshold
        if (grid[x][y] == 0 && (grid[x-1][y] + grid[x+1][y] + grid[x][y-1] + grid[x][y+1]) > 5)
        {
            // Saturate the cell
            grid[x][y] = 1;
        }
    }

    // Print the grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < 10; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}