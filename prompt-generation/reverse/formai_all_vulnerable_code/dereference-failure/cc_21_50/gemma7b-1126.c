//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of living cells
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            cells[i][j] = rand() % 2;
        }
    }

    // Print the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                int num_alive_neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (cells[i + r][j + c] == 1)
                        {
                            num_alive_neighbors++;
                        }
                    }
                }

                if (cells[i][j] == 1 && num_alive_neighbors < 2)
                {
                    cells[i][j] = 0;
                }
                else if (cells[i][j] == 0 && num_alive_neighbors == 3)
                {
                    cells[i][j] = 1;
                }
            }
        }

        // Print the game board after each iteration
        for (int i = 0; i < MAX_CELLS; i++)
        {
            for (int j = 0; j < MAX_CELLS; j++)
            {
                printf("%d ", cells[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}