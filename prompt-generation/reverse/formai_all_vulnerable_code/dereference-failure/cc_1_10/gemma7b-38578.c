//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int size = 0;

    // Allocate memory for the grid
    grid = malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Simulate percolation
    int x = rand() % MAX_SIZE;
    int y = rand() % MAX_SIZE;
    grid[x][y] = 1;

    // Print the grid
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}