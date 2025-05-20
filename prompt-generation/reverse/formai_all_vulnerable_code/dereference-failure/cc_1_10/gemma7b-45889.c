//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int n, m, k, i, j, t, seed;
    scanf("Enter the dimensions of the grid (n,m): ", &n, &m);
    scanf("Enter the number of iterations: ", &t);
    scanf("Enter the seed for the random number generator: ", &seed);

    srand(seed);

    // Allocate memory for the grid
    int **grid = (int *)malloc(n * sizeof(int *) + m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    for (k = 0; k < t; k++)
    {
        // Randomly choose a cell
        i = rand() % n;
        j = rand() % m;

        // If the cell is not already wet and the cell above it is wet, then make the cell wet
        if (grid[i][j] == 0 && grid[i-1][j] == 1)
        {
            grid[i][j] = 1;
        }
    }

    // Print the grid
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}