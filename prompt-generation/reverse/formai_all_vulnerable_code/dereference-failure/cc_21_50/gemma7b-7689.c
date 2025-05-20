//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int i, j, k, l;
    int seed, generation = 0;
    int alive_cells = 0;

    // Allocate memory for the board
    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set the seed for the random number generator
    seed = time(NULL);
    srand(seed);

    // Generate the initial population
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Count the alive cells
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            alive_cells++;
            if (board[i][j] == 1)
            {
                board[i][j] = 2;
            }
        }
    }

    // Evolve the population
    while (generation < 10)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                for (k = -1; k <= 1; k++)
                {
                    for (l = -1; l <= 1; l++)
                    {
                        if (board[i + k][j + l] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[i][j] == 2 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }

        generation++;
        alive_cells = 0;
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                if (board[i][j] == 1)
                {
                    alive_cells++;
                }
            }
        }

        printf("Generation %d: Alive cells %d\n", generation, alive_cells);
    }

    // Free the memory allocated for the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}