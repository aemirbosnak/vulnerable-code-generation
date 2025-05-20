//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void GameOfLife(int **board, int n)
{
    int i, j, k, l, live = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            live = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (board[i + k][j + l] == 1)
                    {
                        live++;
                    }
                }
            }
            if (board[i][j] == 1 && live < 2)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] == 0 && live == 3)
            {
                board[i][j] = 1;
            }
        }
    }
}

int main()
{
    int n = MAX;
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;

    GameOfLife(board, n);

    // Print the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}