//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void GameOfLife(int **board, int size)
{
    int i, j, k, l, count;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            count = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (board[i + k][j + l] == 1)
                    {
                        count++;
                    }
                }
            }
            if (board[i][j] == 1 && count < 2)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] == 0 && count == 3)
            {
                board[i][j] = 1;
            }
        }
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    board[1][1] = board[2][2] = board[3][3] = 1;

    GameOfLife(board, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}