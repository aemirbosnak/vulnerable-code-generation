//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void GameOfLife(int **grid, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            // Check neighbors to the left
            if (c - 1 >= 0)
            {
                neighbors++;
            }
            // Check neighbors above
            if (r - 1 >= 0)
            {
                neighbors++;
            }
            // Check neighbors to the right
            if (c + 1 < size)
            {
                neighbors++;
            }
            // Check neighbors below
            if (r + 1 < size)
            {
                neighbors++;
            }
            // Apply the Game of Life rules
            if (grid[r][c] == 1 && neighbors < 2)
            {
                grid[r][c] = 0;
            }
            else if (grid[r][c] == 0 && neighbors == 3)
            {
                grid[r][c] = 1;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        grid[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the grid
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;

    // Play the Game of Life
    GameOfLife(grid, size);

    // Print the grid
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < size; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}