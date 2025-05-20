//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **grid = NULL;
    int x, y;
    int seed;

    // Allocate memory for the grid
    grid = (int **)malloc(HEIGHT * sizeof(int *));
    for (y = 0; y < HEIGHT; y++)
    {
        grid[y] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            grid[y][x] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolation
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            if (grid[y][x] == 0)
            {
                grid[y][x] = rand() % 2;
            }
        }
    }

    // Print the grid
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            printf("%d ", grid[y][x]);
        }
        printf("\n");
    }

    // Free memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(grid[y]);
    }
    free(grid);

    return 0;
}