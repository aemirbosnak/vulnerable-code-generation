//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    // Allocate memory for the grid
    int **grid = (int *)malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int *)malloc(sizeof(int) * WIDTH);
    }

    // Initialize the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Percolation
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // Randomly assign a value to each cell
            grid[i][j] = rand() % 2;
        }
    }

    // Print the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}