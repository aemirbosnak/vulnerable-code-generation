//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int neighbors = 0;
            // Check the number of neighbors
            if (i > 0) neighbors++;
            if (i < n - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < n - 1) neighbors++;

            // Apply the Game of Life rules
            if (grid[i][j] == 1 && neighbors < 2) grid[i][j] = 0;
            if (grid[i][j] == 0 && neighbors == 3) grid[i][j] = 1;
        }
    }
}

int main()
{
    int n = 5;
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the grid
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;

    // Play the Game of Life
    game_of_life(grid, n);

    // Print the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}