//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y;

    grid = malloc(WIDTH * sizeof(int *));
    for (x = 0; x < WIDTH; x++)
    {
        grid[x] = malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Simulate Percolation
    int num_percolations = 0;
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (grid[x][y] == 0)
            {
                int r = rand() % 2;
                if (r == 0)
                {
                    grid[x][y] = 1;
                    num_percolations++;
                }
            }
        }
    }

    // Print the results
    printf("Number of percolations: %d\n", num_percolations);

    // Free the memory
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}