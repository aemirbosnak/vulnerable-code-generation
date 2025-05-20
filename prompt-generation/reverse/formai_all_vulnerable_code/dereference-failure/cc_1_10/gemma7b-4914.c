//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **grid, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;
            // Check the neighbors of the current cell
            if (r > 0) neighbors++; // Upward neighbor
            if (r < rows - 1) neighbors++; // Downward neighbor
            if (c > 0) neighbors++; // Leftward neighbor
            if (c < cols - 1) neighbors++; // Rightward neighbor

            // Apply the Game of Life rules
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
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initial grid setup
    grid[1][1] = grid[2][2] = grid[2][3] = 1;

    // Game of Life simulation
    game_of_life(grid, rows, cols);

    // Print the updated grid
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free memory
    for (int r = 0; r < rows; r++)
    {
        free(grid[r]);
    }
    free(grid);

    return 0;
}