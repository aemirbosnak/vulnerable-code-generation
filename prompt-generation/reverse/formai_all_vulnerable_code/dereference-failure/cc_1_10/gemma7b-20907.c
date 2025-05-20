//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **board, int i, int j)
{
    if (i == MAX - 1 && j == MAX - 1)
    {
        printf("Solution:\n");
        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
        exit(0);
    }

    for (int n = 0; n < MAX; n++)
    {
        if (board[i][n] == 0 && valid(board, i, n) && available(board, n, j))
        {
            board[i][n] = 1;
            solveSudoku(board, i + 1, j);
            board[i][n] = 0;
        }
    }
}

int valid(int **board, int i, int n)
{
    for (int r = 0; r < MAX; r++)
    {
        if (board[r][n] == 1)
            return 0;
    }
    return 1;
}

int available(int **board, int n, int j)
{
    for (int c = 0; c < MAX; c++)
    {
        if (board[n][c] == 1)
            return 0;
    }
    return 1;
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
    board[0][2] = 6;
    board[1][0] = 8;
    board[1][2] = 3;
    board[2][0] = 4;
    board[2][2] = 7;
    board[3][1] = 9;
    board[3][2] = 2;
    board[4][0] = 1;
    board[4][1] = 2;

    solveSudoku(board, 0, 0);

    return 0;
}