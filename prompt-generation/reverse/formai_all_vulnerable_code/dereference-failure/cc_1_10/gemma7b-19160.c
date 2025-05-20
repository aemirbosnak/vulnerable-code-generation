//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
    int x, y;
    int **grid = NULL;
    int num_percolation = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(WIDTH * sizeof(int *));
    for (x = 0; x < WIDTH; x++)
    {
        grid[x] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Simulate percolations
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (rand() % 2 == 0)
            {
                grid[x][y] = 1;
                num_percolation++;
            }
        }
    }

    // Print the results
    printf("Number of percolations: %d\n", num_percolation);

    // Free the memory
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}