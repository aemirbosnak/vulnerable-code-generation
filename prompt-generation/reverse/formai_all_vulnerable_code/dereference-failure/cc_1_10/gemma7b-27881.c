//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int size = MAX_SIZE;
    int **grid = NULL;
    int x, y;
    int seed = time(NULL);
    srand(seed);

    grid = (int **)malloc(size * sizeof(int *));
    for (x = 0; x < size; x++)
    {
        grid[x] = (int *)malloc(size * sizeof(int));
        for (y = 0; y < size; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Percolation simulation
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            if (rand() % 2 == 0)
            {
                grid[x][y] = 1;
            }
        }
    }

    // Print the grid
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free memory
    for (x = 0; x < size; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}