//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_GENERATIONS 10

void play_game_of_life(int **grid, int rows, int cols)
{
    for (int g = 0; g < MAX_GENERATIONS; g++)
    {
        int **new_grid = malloc(rows * sizeof(int *) + rows);
        for (int r = 0; r < rows; r++)
        {
            new_grid[r] = malloc(cols * sizeof(int) + cols);
            for (int c = 0; c < cols; c++)
            {
                new_grid[r][c] = grid[r][c] & 1;
            }
        }

        free(grid);
        grid = new_grid;
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    free(grid);
}

int main()
{
    int rows = 5;
    int cols = 5;
    int **grid = malloc(rows * sizeof(int *) + rows);
    for (int r = 0; r < rows; r++)
    {
        grid[r] = malloc(cols * sizeof(int) + cols);
        for (int c = 0; c < cols; c++)
        {
            grid[r][c] = 0;
        }
    }

    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    play_game_of_life(grid, rows, cols);

    return 0;
}