//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdlib.h>
#include <time.h>

int main()
{
    int n = 10, m = 10;
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    int iterations = 0;
    while (!percolation(grid, n, m))
    {
        iterations++;
    }

    // Print the result
    printf("Number of iterations: %d\n", iterations);

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int percolation(int **grid, int n, int m)
{
    // Check if the grid is saturated
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return 0;
            }
        }
    }

    // Randomly choose a cell
    int x = rand() % n;
    int y = rand() % m;

    // If the cell is not already saturated, saturate it and its neighbors
    if (grid[x][y] == 0)
    {
        grid[x][y] = 1;

        // Check the four neighbors
        if (x > 0)
        {
            grid[x - 1][y] = 1;
        }
        if (x < n - 1)
        {
            grid[x + 1][y] = 1;
        }
        if (y > 0)
        {
            grid[x][y - 1] = 1;
        }
        if (y < m - 1)
        {
            grid[x][y + 1] = 1;
        }
    }

    // Return 1 if the grid is saturated, otherwise 0
    return 1;
}