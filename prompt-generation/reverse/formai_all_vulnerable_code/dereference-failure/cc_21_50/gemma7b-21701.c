//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int i, j, k, l;

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

    // Create a random pattern
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Simulate Game of Life
    for (k = 0; k < 5; k++)
    {
        for (l = 0; l < MAX_SIZE; l++)
        {
            for (i = 0; i < MAX_SIZE; i++)
            {
                for (j = 0; j < MAX_SIZE; j++)
                {
                    int neighbors = 0;
                    if (board[i - 1][j] == 1) neighbors++;
                    if (board[i + 1][j] == 1) neighbors++;
                    if (board[i][j - 1] == 1) neighbors++;
                    if (board[i][j + 1] == 1) neighbors++;

                    if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                    if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
                }
            }
        }
    }

    // Print the updated board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}