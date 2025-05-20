//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void percolate(int **grid, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (grid[i][j] == 1)
            {
                // Check if the cell is already percolated
                if (grid[i][j] == 2)
                {
                    continue;
                }

                // Percolate the cell
                grid[i][j] = 2;

                // Check the four neighbors of the cell
                if (i > 0)
                {
                    if (grid[i - 1][j] == 1)
                    {
                        percolate(grid, size);
                    }
                }

                if (j > 0)
                {
                    if (grid[i][j - 1] == 1)
                    {
                        percolate(grid, size);
                    }
                }

                if (i < size - 1)
                {
                    if (grid[i + 1][j] == 1)
                    {
                        percolate(grid, size);
                    }
                }

                if (j < size - 1)
                {
                    if (grid[i][j + 1] == 1)
                    {
                        percolate(grid, size);
                    }
                }
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Generate a random grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    percolate(grid, size);

    // Print the percolated grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}