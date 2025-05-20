//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Allocate memory for a 10x10 grid of integers
    int **grid = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        grid[i] = (int *)malloc(10 * sizeof(int));
    }

    // Initialize the grid with random numbers
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = rand() % 10;
        }
    }

    // Print the grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Shock the grid
    grid[5][5] = 100;

    // Print the shocked grid
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < 10; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}