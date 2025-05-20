//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define MAX_PERCOLATION_ITERS 1000

int main()
{
    // Allocate memory for the grid
    int **grid = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    for (int i = 0; i < WIDTH * HEIGHT; i++)
    {
        grid[i] = 0;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Simulate percolation
    for (int iter = 0; iter < MAX_PERCOLATION_ITERS; iter++)
    {
        // Choose a random cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is not already saturated and there is a chance of percolation, saturate it
        if (grid[x * HEIGHT + y] == 0 && rand() % 2 == 0)
        {
            grid[x * HEIGHT + y] = 1;
        }
    }

    // Print the grid
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", grid[j * HEIGHT + i]);
        }
        printf("\n");
    }

    // Free the memory
    free(grid);

    return 0;
}