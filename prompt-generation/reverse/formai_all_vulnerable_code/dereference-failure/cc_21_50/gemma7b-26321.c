//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **grid = NULL;
    int x, y, i, j, k, l, alive = 0, dead = 0;

    grid = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(x = 0; x < MAX_SIZE; x++)
    {
        grid[x] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the grid
    for(x = 0; x < MAX_SIZE; x++)
    {
        for(y = 0; y < MAX_SIZE; y++)
        {
            grid[x][y] = 0;
        }
    }

    // Set some cells to alive
    grid[2][2] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
    grid[4][2] = 1;
    grid[5][2] = 1;

    // Game loop
    while(1)
    {
        // Calculate the number of alive neighbors for each cell
        for(x = 0; x < MAX_SIZE; x++)
        {
            for(y = 0; y < MAX_SIZE; y++)
            {
                alive = 0;
                for(i = -1; i <= 1; i++)
                {
                    for(j = -1; j <= 1; j++)
                    {
                        if(grid[x + i][y + j] && x + i >= 0 && y + j >= 0)
                        {
                            alive++;
                        }
                    }
                }

                // Apply the rules of survival
                if(grid[x][y] && alive < 2)
                {
                    dead++;
                    grid[x][y] = 0;
                }
                else if(grid[x][y] && alive > 3)
                {
                    dead++;
                    grid[x][y] = 0;
                }
                else if(!grid[x][y] && alive == 3)
                {
                    alive++;
                    grid[x][y] = 1;
                }
            }
        }

        // Print the grid
        for(x = 0; x < MAX_SIZE; x++)
        {
            for(y = 0; y < MAX_SIZE; y++)
            {
                printf("%d ", grid[x][y]);
            }
            printf("\n");
        }

        // Check if the game is over
        if(dead == MAX_SIZE * MAX_SIZE)
        {
            break;
        }
    }

    // Free the memory
    for(x = 0; x < MAX_SIZE; x++)
    {
        free(grid[x]);
    }
    free(grid);

    return 0;
}