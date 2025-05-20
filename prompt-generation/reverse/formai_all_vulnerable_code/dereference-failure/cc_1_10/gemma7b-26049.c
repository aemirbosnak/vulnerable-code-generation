//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 100

int main()
{
    int **grid = NULL;
    int size = MAX_SIZE;
    int x, y;

    // Allocate memory for the grid
    grid = malloc(size * size * sizeof(int));
    if (grid == NULL)
    {
        return 1;
    }

    // Initialize the grid
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Randomly fill the grid
    srand(time(NULL));
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            grid[x][y] = rand() % 2;
        }
    }

    // Print the grid
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            printf("%d ", grid[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    free(grid);

    return 0;
}