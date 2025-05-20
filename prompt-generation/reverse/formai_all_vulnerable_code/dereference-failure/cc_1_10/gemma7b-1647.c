//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define N 9

void solve_sudoku(int **board)
{
    int i, j, k, empty_cell = -1, row_sum[N], column_sum[N], box_sum[N];

    for (i = 0; i < N; i++)
    {
        row_sum[i] = 0;
        column_sum[i] = 0;
        box_sum[i] = 0;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                empty_cell = i * N + j;
            }
            row_sum[i] += board[i][j];
            column_sum[j] += board[i][j];
            box_sum[i / 3 * N + j / 3 * N] += board[i][j];
        }
    }

    if (empty_cell == -1)
    {
        return;
    }

    for (k = 1; k <= 9; k++)
    {
        if (row_sum[k] == N && column_sum[k] == N && box_sum[k] == N)
        {
            board[empty_cell / N][empty_cell % N] = k;
            return;
        }
    }

    return;
}

int main()
{
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(N * sizeof(int));
    }

    solve_sudoku(board);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}