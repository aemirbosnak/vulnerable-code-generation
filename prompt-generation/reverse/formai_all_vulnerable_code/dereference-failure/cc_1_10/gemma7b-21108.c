//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int x, y, i, j, count = 0;

    grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Percolation Simulation
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            grid[x][y] = rand() % 2;
        }
    }

    // Count the number of connected components
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (grid[x][y] == 1)
            {
                count++;
                grid[x][y] = 0;
            }
        }
    }

    // Print the number of connected components
    printf("The number of connected components is: %d\n", count);

    // Free the memory
    for (i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}