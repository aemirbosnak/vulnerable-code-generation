//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    srand(time(NULL));
    int size = MAX_SIZE;
    int **grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    int iterations = 0;
    while (!percolation(grid, size, size, iterations))
    {
        iterations++;
    }

    printf("Number of iterations: %d\n", iterations);

    free(grid);

    return 0;
}

int percolation(int **grid, int size, int size2, int iterations)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (grid[i][j] == 1)
            {
                // Paranoid check to see if the cell has already been checked
                if (grid[i][j] == 2)
                {
                    return 0;
                }

                // Mark the cell as checked
                grid[i][j] = 2;

                // Check if the cell is connected to any other cells
                if (check_connections(grid, size, size2, i, j))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int check_connections(int **grid, int size, int size2, int i, int j)
{
    // Check if the cell is connected horizontally
    if (grid[i][j - 1] == 1)
    {
        return 0;
    }

    // Check if the cell is connected vertically
    if (grid[i - 1][j] == 1)
    {
        return 0;
    }

    // Check if the cell is connected diagonally
    if (grid[i - 1][j - 1] == 1)
    {
        return 0;
    }

    return 1;
}