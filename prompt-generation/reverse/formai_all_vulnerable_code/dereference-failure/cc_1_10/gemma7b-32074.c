//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void solve_sudoku(int **board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (board[k][j] != 0 && board[i][k] != 0 && board[k][j] == board[i][j])
                    {
                        board[i][j] = board[k][j];
                        solve_sudoku(board);
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
    int **board = (int **)malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++)
    {
        board[i] = (int *)malloc(9 * sizeof(int));
    }

    board[0][0] = 5;
    board[0][2] = 6;
    board[0][5] = 1;
    board[1][0] = 9;
    board[1][1] = 3;
    board[1][6] = 4;
    board[2][2] = 8;
    board[2][4] = 7;
    board[3][0] = 4;
    board[3][1] = 2;
    board[3][4] = 3;
    board[4][0] = 2;
    board[4][3] = 5;
    board[4][5] = 9;
    board[5][1] = 6;
    board[5][2] = 1;
    board[5][4] = 8;
    board[6][0] = 1;
    board[6][3] = 9;
    board[6][4] = 2;
    board[7][0] = 8;
    board[7][1] = 2;
    board[7][3] = 4;
    board[8][2] = 3;
    board[8][4] = 6;

    solve_sudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}