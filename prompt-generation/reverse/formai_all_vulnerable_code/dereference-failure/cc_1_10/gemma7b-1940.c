//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **grid, int n)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            int neighbors = 0;
            // Check the number of neighbors
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < n) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < n) neighbors++;

            // Apply the Game of Life rules
            if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            if (grid[r][c] == 1 && (neighbors < 2 || neighbors > 3)) grid[r][c] = 0;
        }
    }
}

int main()
{
    int n = 5;
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) grid[i] = (int *)malloc(n * sizeof(int));

    // Initialize the grid
    grid[0][0] = 1;
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[3][3] = 1;

    // Play the game for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        game_of_life(grid, n);
    }

    // Print the final grid
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < n; i++) free(grid[i]);
    free(grid);

    return 0;
}