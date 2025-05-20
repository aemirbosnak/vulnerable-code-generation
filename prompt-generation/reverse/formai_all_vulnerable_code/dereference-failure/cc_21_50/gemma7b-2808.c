//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int i, j, k, l;

    // Allocate memory for the game board
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

    // Create a random pattern
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                for (l = -1; l <= 1; l++)
                {
                    if (i + l >= 0 && i + l < MAX_SIZE && board[i + l][j] == 1)
                    {
                        neighbors++;
                    }
                }
                for (l = -1; l <= 1; l++)
                {
                    if (j + l >= 0 && j + l < MAX_SIZE && board[i][j + l] == 1)
                    {
                        neighbors++;
                    }
                }
                if (board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }

    // Print the final board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}