//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void GameOfLife(int **board)
{
    int i, j, k, l;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
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

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the game board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;

    // Play the game for 5 generations
    for (int gen = 0; gen < 5; gen++)
    {
        GameOfLife(board);
    }

    // Print the final board
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}