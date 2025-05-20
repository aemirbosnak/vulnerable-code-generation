//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void game_of_life(int **grid, int size)
{
    int i, j, k, l, alive_neighbors, new_state;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            alive_neighbors = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;
                    if (i + k >= 0 && i + k < size && j + l >= 0 && j + l < size && grid[i + k][j + l] == 1)
                        alive_neighbors++;
                }
            }
            new_state = grid[i][j] * (alive_neighbors == 2 || alive_neighbors == 3);
            grid[i][j] = new_state;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    // Initial grid setup
    grid[1][1] = grid[2][2] = grid[3][2] = grid[4][1] = 1;

    // Game of Life iterations
    for (int t = 0; t < 10; t++)
    {
        game_of_life(grid, size);
    }

    // Print final grid
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}