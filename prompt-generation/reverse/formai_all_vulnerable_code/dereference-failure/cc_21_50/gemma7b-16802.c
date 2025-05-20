//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 10
#define MAX_GENERATIONS 100

int main()
{
    int **grid = NULL;
    int generation = 0;

    // Allocate memory for the grid
    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (int i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
    }

    // Initialize the grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create the initial population
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life for the specified number of generations
    while (generation < MAX_GENERATIONS)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                        {
                            continue;
                        }
                        if (grid[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (grid[i][j] == 1 && neighbors < 2)
                {
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 0 && neighbors == 3)
                {
                    grid[i][j] = 1;
                }
            }
        }

        // Increment the generation counter
        generation++;
    }

    // Print the final grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}