//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **grid = NULL;
    int i, j, x, y;
    int seed, rand_num;
    char msg[200];

    // Allocate memory for the grid
    grid = (int *)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++)
    {
        grid[i] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set the seed
    seed = time(NULL);
    srand(seed);

    // Percolation
    for (x = 0; x < ROWS; x++)
    {
        for (y = 0; y < COLS; y++)
        {
            rand_num = rand() % 2;
            if (rand_num == 0)
            {
                grid[x][y] = 1;
            }
        }
    }

    // Print the grid
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < ROWS; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}