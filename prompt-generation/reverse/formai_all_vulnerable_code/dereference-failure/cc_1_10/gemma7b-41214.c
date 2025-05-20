//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

int main()
{
    int **grid = NULL;
    int x, y, seed, i, j;

    // Allocate memory for the grid
    grid = (int **)malloc(WIDTH * sizeof(int *));
    for(i = 0; i < WIDTH; i++)
    {
        grid[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the seed
    seed = time(NULL);
    srand(seed);

    // Percolation simulation
    for(i = 0; i < WIDTH; i++)
    {
        for(j = 0; j < HEIGHT; j++)
        {
            grid[i][j] = rand() % 2;
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