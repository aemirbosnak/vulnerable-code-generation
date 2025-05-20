//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sudoku(int **board, int idx)
{
    int i, j, k, flag = 0;

    if (idx == 81)
    {
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (k = 1; k <= 9; k++)
                {
                    if ((board[i][j] == k) || (board[k][j] == k) || (board[i][k] == k))
                    {
                        flag = 1;
                    }
                }

                if (flag == 0)
                {
                    board[i][j] = idx + 1;
                    sudoku(board, idx + 1);
                    board[i][j] = 0;
                }
            }
        }
    }

    return;
}

int main()
{
    int **board = (int **)malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++)
    {
        board[i] = (int *)malloc(9 * sizeof(int));
    }

    sudoku(board, 0);

    return 0;
}