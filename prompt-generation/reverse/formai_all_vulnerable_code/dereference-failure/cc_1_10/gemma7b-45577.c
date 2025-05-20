//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **grid, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;
            // Check the four neighbors
            if (r - 1 >= 0) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (r + 1 < rows) neighbors++;
            if (c + 1 < cols) neighbors++;

            // Apply the Game of Life rules
            if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            if (grid[r][c] == 1 && (neighbors < 2 || neighbors > 3)) grid[r][c] = 0;
        }
    }
}

int main()
{
    // Create a grid
    int **grid = NULL;
    int rows = 5;
    int cols = 5;
    grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;

    // Play the Game of Life
    GameOfLife(grid, rows, cols);

    // Print the grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    return 0;
}