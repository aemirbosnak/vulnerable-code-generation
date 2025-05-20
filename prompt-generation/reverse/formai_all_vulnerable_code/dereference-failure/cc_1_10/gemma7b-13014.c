//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

int main()
{
    int **grid = NULL;
    int x, y;
    srand(time(NULL));

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

    // Percolation simulation
    for (int iter = 0; iter < 1000; iter++)
    {
        // Randomly choose a cell
        x = rand() % WIDTH;
        y = rand() % HEIGHT;

        // If the cell is not already saturated and it has a neighbor to the right
        if (grid[y][x] == 0 && grid[y][x + 1] == 1)
        {
            // Saturate the cell
            grid[y][x] = 1;
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

    // Free the memory
    for (y = 0; y < HEIGHT; y++)
    {
        free(grid[y]);
    }
    free(grid);

    return 0;
}