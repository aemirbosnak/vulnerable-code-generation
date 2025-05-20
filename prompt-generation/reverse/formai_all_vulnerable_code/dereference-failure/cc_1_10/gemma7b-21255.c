//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void game_of_life(int **grid)
{
    int i, j, k, l;
    int alive = 0, dead = 0;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            alive = 0;
            dead = 0;

            // Check neighbors
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (grid[i + k][j + l] == 1)
                    {
                        alive++;
                    }
                }
            }

            // Apply rules
            if (grid[i][j] == 1 && alive < 2)
            {
                dead++;
            }
            else if (grid[i][j] == 0 && alive == 3)
            {
                alive++;
            }

            // Update grid
            if (dead)
            {
                grid[i][j] = 0;
            }
            else if (alive)
            {
                grid[i][j] = 1;
            }
        }
    }
}

int main()
{
    int **grid = NULL;
    int i, j;

    grid = (int **)malloc(MAX * MAX * sizeof(int));
    for (i = 0; i < MAX; i++)
    {
        grid[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize grid
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Set initial conditions
    grid[1][1] = grid[2][2] = grid[3][3] = 1;

    // Play game of life
    game_of_life(grid);

    // Print final grid
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}