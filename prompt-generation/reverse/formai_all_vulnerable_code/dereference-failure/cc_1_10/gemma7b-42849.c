//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int **grid = NULL;
    int i, j, x, y;
    int percolates = 0;

    grid = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        grid[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    x = rand() % MAX;
    y = rand() % MAX;
    grid[x][y] = 1;

    // Check if the cell percolates
    percolates = checkPercolation(grid, x, y);

    // Print the result
    if (percolates)
    {
        printf("The cell percolates!\n");
    }
    else
    {
        printf("The cell does not percolates.\n");
    }

    // Free the memory
    for (i = 0; i < MAX; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

int checkPercolation(int **grid, int x, int y)
{
    int i, j;

    // Check if the cell is already wet
    if (grid[x][y] == 1)
    {
        return 1;
    }

    // Check if the cell is on the border
    if (x == 0 || x == MAX - 1 || y == 0 || y == MAX - 1)
    {
        return 1;
    }

    // Check if the neighboring cells are wet
    for (i = x - 1; i <= x + 1; i++)
    {
        for (j = y - 1; j <= y + 1; j++)
        {
            if (grid[i][j] == 1)
            {
                return 1;
            }
        }
    }

    // The cell does not percolates
    return 0;
}