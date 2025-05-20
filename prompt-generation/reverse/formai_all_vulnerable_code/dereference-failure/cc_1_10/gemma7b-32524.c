//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int main()
{
    int **grid = NULL;
    int i, j, k, rand_num;

    // Allocate memory for the grid
    grid = (int **)malloc(ROWS * sizeof(int *));
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

    // Simulate percolations
    for (k = 0; k < 1000; k++)
    {
        rand_num = rand() % ROWS * COLS;
        grid[rand_num / COLS][rand_num % COLS] = 1;
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