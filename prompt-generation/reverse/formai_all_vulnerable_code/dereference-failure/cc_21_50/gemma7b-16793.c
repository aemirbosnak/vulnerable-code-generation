//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5
#define ALIVE 1
#define DEAD 0

int main()
{
    int **grid = NULL;
    int i, j, k, l, r, c;
    int alive_cells = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = DEAD;
        }
    }

    // Create a few alive cells
    grid[2][2] = ALIVE;
    grid[3][2] = ALIVE;
    grid[3][3] = ALIVE;
    grid[2][3] = ALIVE;

    // Simulate the game of life
    for (k = 0; k < 10; k++)
    {
        // Count the number of alive cells for each cell
        for (i = 0; i < GRID_SIZE; i++)
        {
            for (j = 0; j < GRID_SIZE; j++)
            {
                alive_cells = 0;
                r = i - 1;
                c = j - 1;
                if (r >= 0 && grid[r][c] == ALIVE) alive_cells++;
                r = i + 1;
                c = j - 1;
                if (r < GRID_SIZE && grid[r][c] == ALIVE) alive_cells++;
                r = i - 1;
                c = j + 1;
                if (r >= 0 && grid[r][c] == ALIVE) alive_cells++;
                r = i + 1;
                c = j + 1;
                if (r < GRID_SIZE && grid[r][c] == ALIVE) alive_cells++;
                if (alive_cells < 2 || alive_cells > 3) grid[i][j] = DEAD;
            }
        }

        // Update the grid
        for (i = 0; i < GRID_SIZE; i++)
        {
            for (j = 0; j < GRID_SIZE; j++)
            {
                if (grid[i][j] == ALIVE)
                {
                    printf(". ");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Print the next generation
        printf("Generation %d:\n", k + 1);
    }

    // Free the memory
    for (i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}