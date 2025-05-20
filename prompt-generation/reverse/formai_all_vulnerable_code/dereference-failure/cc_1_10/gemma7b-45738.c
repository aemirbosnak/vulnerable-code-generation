//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void solveSudoku(int **board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 0; k < SIZE; k++)
                {
                    if (board[k][j] == 0 && board[i][k] == 0)
                    {
                        board[i][j] = k + 1;
                        solveSudoku(board);
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
    return;
}

int main()
{
    int **board = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++)
    {
        board[i] = (int *)malloc(SIZE * sizeof(int));
    }

    board[0][0] = 5;
    board[0][1] = 3;
    board[0][2] = 0;

    board[1][0] = 6;
    board[1][1] = 0;
    board[1][2] = 0;

    board[2][0] = 0;
    board[2][1] = 0;
    board[2][2] = 0;

    solveSudoku(board);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}