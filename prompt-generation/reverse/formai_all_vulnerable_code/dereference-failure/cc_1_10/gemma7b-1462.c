//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void solveSudoku(int **board, int i, int j)
{
    if (i == 9 && j == 9)
    {
        printf("Sudoku solution:\n");
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (int n = 1; n <= 9; n++)
    {
        if (board[i][j] == 0 && isSafe(board, i, j, n))
        {
            board[i][j] = n;
            solveSudoku(board, i + 1, j);
            board[i][j] = 0;
        }
    }
}

int isSafe(int **board, int i, int j, int n)
{
    for (int r = 0; r < 9; r++)
    {
        if (board[r][j] == n)
            return 0;
    }

    for (int c = 0; c < 9; c++)
    {
        if (board[i][c] == n)
            return 0;
    }

    int boxI = i / 3;
    int boxJ = j / 3;

    for (int r = boxI * 3; r < boxI * 3 + 3; r++)
    {
        for (int c = boxJ * 3; c < boxJ * 3 + 3; c++)
        {
            if (board[r][c] == n)
                return 0;
        }
    }

    return 1;
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
    board[0][3] = 1;
    board[1][0] = 9;
    board[1][2] = 3;
    board[2][0] = 8;
    board[2][2] = 4;
    board[3][0] = 2;
    board[3][1] = 7;
    board[4][0] = 1;
    board[4][2] = 3;
    board[5][0] = 6;
    board[5][2] = 9;
    board[6][0] = 3;
    board[6][2] = 2;
    board[7][0] = 4;
    board[7][2] = 8;
    board[8][0] = 2;
    board[8][2] = 5;

    solveSudoku(board, 0, 0);

    return 0;
}