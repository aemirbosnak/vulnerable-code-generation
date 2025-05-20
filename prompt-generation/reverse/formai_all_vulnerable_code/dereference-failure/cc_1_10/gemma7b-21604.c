//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **grid, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;
            // Check the neighbors
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < rows) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < cols) neighbors++;

            // Apply the rules
            if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
            if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
        }
    }
}

int main()
{
    int rows = 5;
    int cols = 5;
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++) grid[r] = (int *)malloc(cols * sizeof(int));

    // Initialize the grid
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[3][3] = 1;

    // Play the game
    game_of_life(grid, rows, cols);

    // Print the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++) free(grid[r]);
    free(grid);

    return 0;
}