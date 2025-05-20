//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void sudoku_solver(int **board)
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
                    if (board[i][k] == board[k][j] && board[k][k] == 0)
                    {
                        board[i][j] = k + 1;
                        sudoku_solver(board);
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
    int **board = (int **)malloc(MAX * MAX * sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    board[0][0] = 5;
    board[0][2] = 3;
    board[1][0] = 6;
    board[1][1] = 9;
    board[2][0] = 1;
    board[2][2] = 4;
    board[3][1] = 2;
    board[4][0] = 8;
    board[4][2] = 7;
    board[5][1] = 3;
    board[5][2] = 2;
    board[6][0] = 4;
    board[6][2] = 8;
    board[7][1] = 6;
    board[8][0] = 2;
    board[8][2] = 9;
    board[9][0] = 7;
    board[9][1] = 8;

    sudoku_solver(board);

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