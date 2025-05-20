//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **grid, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
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
            if (c + 1 < cols)
            {
                neighbors++;
            }
            // Check neighbors below
            if (r + 1 < rows)
            {
                neighbors++;
            }

            // Apply the Game of Life rules
            if (grid[r][c] == 0 && neighbors == 3)
            {
                grid[r][c] = 1;
            }
            else if (grid[r][c] == 1 && (neighbors < 2 || neighbors > 3))
            {
                grid[r][c] = 0;
            }
        }
    }
}

int main()
{
    int rows = 5;
    int cols = 5;
    int **grid = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][3] = 1;

    // Play the Game of Life
    game_of_life(grid, rows, cols);

    // Print the final grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}