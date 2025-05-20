//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **board)
{
    int i, j, k;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (board[i][j] == 0)
            {
                for (k = 0; k < MAX; k++)
                {
                    if (board[i][k] == board[k][j] && board[i][k] != 0)
                    {
                        board[i][j] = board[k][j];
                        break;
                    }
                }

                if (board[i][j] == 0)
                {
                    board[i][j] = 1;
                    solveSudoku(board);
                    board[i][j] = 0;
                }
            }
        }
    }

    return;
}

int main()
{
    int **board = (int **)malloc(MAX * MAX * sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    board[0][0] = 5;
    board[0][1] = 3;
    board[0][2] = 4;
    board[1][0] = 6;
    board[1][2] = 2;
    board[2][0] = 1;
    board[2][1] = 9;
    board[2][2] = 5;

    solveSudoku(board);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}