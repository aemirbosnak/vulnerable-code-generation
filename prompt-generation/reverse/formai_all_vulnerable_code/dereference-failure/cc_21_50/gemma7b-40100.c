//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int i, j, k;

    // Allocate memory for the grid
    grid = (int**)malloc(MAX_SIZE * sizeof(int*));
    for (i = 0; i < MAX_SIZE; i++)
    {
        grid[i] = (int*)malloc(MAX_SIZE * sizeof(int));
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
            if (rand() % 2 == 0)
            {
                grid[i][j] = 1;
            }
        }
    }

    // Print the grid
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Game of Life logic
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                if (i > 0) neighbors++;
                if (i < MAX_SIZE - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < MAX_SIZE - 1) neighbors++;

                if (grid[i][j] == 1 && neighbors < 2)
                {
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 0 && neighbors == 3)
                {
                    grid[i][j] = 1;
                }
            }
        }

        // Print the updated grid
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