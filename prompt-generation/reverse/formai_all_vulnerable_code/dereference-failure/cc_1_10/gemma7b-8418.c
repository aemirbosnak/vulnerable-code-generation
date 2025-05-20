//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 50
#define FILL_PERCENTAGE 20

int main()
{
    int **grid = NULL;
    int i, j, k, n, m;
    int filledCells = 0;

    // Allocate memory for the grid
    grid = (int**)malloc(GRID_SIZE * sizeof(int*));
    for (i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int*)malloc(GRID_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Fill a random number of cells
    n = GRID_SIZE * FILL_PERCENTAGE / 100;
    for (k = 0; k < n; k++)
    {
        i = rand() % GRID_SIZE;
        j = rand() % GRID_SIZE;
        grid[i][j] = 1;
        filledCells++;
    }

    // Print the filled cells
    printf("Number of filled cells: %d\n", filledCells);
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}