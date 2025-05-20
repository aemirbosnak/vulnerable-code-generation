//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int sudoku_solve(int **board, int idx, int n)
{
    if (idx == n * n)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (board[idx][i] == 0 && sudoku_solve(board, idx + 1, n) == 1)
        {
            board[idx][i] = 2;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n = 9;
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }

    board[0][0] = 5;
    board[0][1] = 3;
    board[0][2] = 0;
    board[0][3] = 0;
    board[0][4] = 0;
    board[0][5] = 2;
    board[0][6] = 0;
    board[0][7] = 0;
    board[0][8] = 0;

    board[1][0] = 6;
    board[1][1] = 0;
    board[1][2] = 0;
    board[1][3] = 0;
    board[1][4] = 1;
    board[1][5] = 0;
    board[1][6] = 0;
    board[1][7] = 0;
    board[1][8] = 0;

    board[2][0] = 0;
    board[2][1] = 0;
    board[2][2] = 0;
    board[2][3] = 0;
    board[2][4] = 0;
    board[2][5] = 0;
    board[2][6] = 0;
    board[2][7] = 0;
    board[2][8] = 0;

    if (sudoku_solve(board, 0, n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution found.");
    }

    return 0;
}