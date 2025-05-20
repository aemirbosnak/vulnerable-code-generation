//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the Game of Life rules
int game_of_life(int **grid, int rows, int cols)
{
    int i, j, neighbors, alive_neighbors = 0;

    // Iterate over the grid
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            // Count the number of alive neighbors
            neighbors = 0;
            if (i > 0) neighbors++;  // Up
            if (i < rows - 1) neighbors++;  // Down
            if (j > 0) neighbors++;  // Left
            if (j < cols - 1) neighbors++;  // Right

            // Check if the cell is alive and if it has enough neighbors
            if (grid[i][j] && (neighbors < 2 || neighbors > 3))
            {
                grid[i][j] = 0;  // Kill the cell
            }
            else if (!grid[i][j] && neighbors == 3)
            {
                grid[i][j] = 1;  // Bring the cell back to life
            }
        }
    }

    return 0;
}

int main()
{
    int rows = 5;
    int cols = 5;
    int **grid = NULL;

    // Allocate memory for the grid
    grid = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the grid
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][1] = 1;
    grid[2][2] = 1;

    // Play the game of life
    game_of_life(grid, rows, cols);

    // Print the grid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < rows; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}