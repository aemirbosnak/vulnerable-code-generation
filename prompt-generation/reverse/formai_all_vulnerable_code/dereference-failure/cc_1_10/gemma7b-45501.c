//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define EMPTY 0
#define FULL 1

int main()
{
    int **grid = NULL;
    int i, j, k, r, seed;

    // Allocate memory for the grid
    grid = (int**)malloc(HEIGHT * sizeof(int*));
    for (i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int*)malloc(WIDTH * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            grid[i][j] = EMPTY;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Percolation
    for (k = 0; k < 100; k++)
    {
        r = rand() % WIDTH;
        r = rand() % HEIGHT;

        if (grid[r][r] == EMPTY)
        {
            grid[r][r] = FULL;
        }
    }

    // Print the grid
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}