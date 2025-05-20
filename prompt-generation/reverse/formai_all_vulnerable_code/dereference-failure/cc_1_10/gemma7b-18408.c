//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>

void gameOfLife(int **board, int size, int iter)
{
    int i, j, count, alive = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            count = 0;
            if (i > 0)
                count++;
            if (i < size - 1)
                count++;
            if (j > 0)
                count++;
            if (j < size - 1)
                count++;

            if (board[i][j] == 1 && count >= 2)
                alive++;
            else if (board[i][j] == 0 && count == 3)
                alive++;
        }
    }

    if (iter == 0)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else
        gameOfLife(board, size, iter - 1);
}

int main()
{
    int size = 5;
    int iter = 3;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        board[i] = (int *)malloc(size * sizeof(int));

    board[1][1] = board[2][2] = board[2][3] = 1;

    gameOfLife(board, size, iter);

    return 0;
}