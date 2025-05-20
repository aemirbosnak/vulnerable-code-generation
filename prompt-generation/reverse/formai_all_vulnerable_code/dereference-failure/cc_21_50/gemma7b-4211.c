//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **grid = NULL;
    int i, j, k, l, r, c;

    // Allocate memory for the grid
    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Create a random pattern
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            r = rand() % 2;
            if (r == 0)
            {
                grid[i][j] = 1;
            }
        }
    }

    // Display the grid
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Simulate the Game of Life
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                l = 0;
                for (r = -1; r <= 1; r++)
                {
                    for (c = -1; c <= 1; c++)
                    {
                        if (grid[i + r][j + c] == 1)
                        {
                            l++;
                        }
                    }
                }

                if (grid[i][j] == 1 && l < 2)
                {
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 0 && l == 3)
                {
                    grid[i][j] = 1;
                }
            }
        }

        // Display the grid
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}