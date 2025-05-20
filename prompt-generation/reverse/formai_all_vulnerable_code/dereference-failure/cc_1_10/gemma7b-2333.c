//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **grid = NULL;
    int x, y;

    // Allocate memory for the grid
    grid = (int **)malloc(WIDTH * sizeof(int *) + HEIGHT * sizeof(int));
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

    // Simulate percolation
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            if (grid[x][y] == 0)
            {
                // Randomly assign a value to the cell
                grid[x][y] = rand() % 2;
            }
        }
    }

    // Print the grid
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < WIDTH; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}