//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **grid = NULL;
    int i, j, k;
    int seed = time(NULL);
    srand(seed);

    // Allocate memory for the grid
    grid = (int**)malloc(ROWS * sizeof(int*));
    for(i = 0; i < ROWS; i++)
    {
        grid[i] = (int*)malloc(COLS * sizeof(int));
    }

    // Initialize the grid
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Percolation
    k = 0;
    while(k++ < 100)
    {
        i = rand() % ROWS;
        j = rand() % COLS;
        if(grid[i][j] == 0)
        {
            grid[i][j] = 1;
        }
    }

    // Print the grid
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < ROWS; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}