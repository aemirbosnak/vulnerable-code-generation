//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **board, int idx)
{
    if (idx == MAX * MAX - 1)
    {
        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
            {
                printf("%d ", board[r][c]);
            }
        }
        printf("\n");
        return;
    }

    for (int n = 1; n <= MAX; n++)
    {
        if (board[idx/MAX][idx%MAX] == n && isValid(board, idx, n))
        {
            board[idx/MAX][idx%MAX] = n;
            solveSudoku(board, idx + 1);
            board[idx/MAX][idx%MAX] = 0;
        }
    }
}

int isValid(int **board, int idx, int n)
{
    for (int r = 0; r < MAX; r++)
    {
        if (board[r][idx%MAX] == n)
            return 0;
    }

    for (int c = 0; c < MAX; c++)
    {
        if (board[idx/MAX][c] == n)
            return 0;
    }

    return 1;
}

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    solveSudoku(board, 0);

    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            free(board[r][c]);
        }
        free(board[r]);
    }

    free(board);

    return 0;
}