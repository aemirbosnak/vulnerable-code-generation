//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define EMPTY 0
#define FILLED 1

int main()
{
    // Allocate memory for the grid
    int **grid = (int**)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = EMPTY;
        }
    }

    // Simulate percolation
    int num_filled = 0;
    while (num_filled < 20)
    {
        // Randomly choose a cell
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        // If the cell is empty and it has not already been filled
        if (grid[x][y] == EMPTY)
        {
            // Fill the cell
            grid[x][y] = FILLED;

            // Increment the number of filled cells
            num_filled++;
        }
    }

    // Print the grid
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < WIDTH; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}