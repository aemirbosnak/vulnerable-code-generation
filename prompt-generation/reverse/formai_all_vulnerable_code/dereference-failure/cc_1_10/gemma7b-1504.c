//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **grid = NULL;
    int i, j, x, y;

    // Allocate memory for the grid
    grid = malloc(WIDTH * sizeof(int *));
    for(i = 0; i < WIDTH; i++)
    {
        grid[i] = malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    for(x = 0; x < WIDTH; x++)
    {
        for(y = 0; y < HEIGHT; y++)
        {
            if(grid[x][y] == 0)
            {
                // Randomly assign a value of 1 to the cell
                grid[x][y] = rand() % 2;
            }
        }
    }

    // Print the grid
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}