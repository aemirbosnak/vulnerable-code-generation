//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int sudoku_solve(int **board)
{
    int i, j, k, empty = 0;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (board[i][j] == 0)
            {
                empty++;
            }
        }
    }

    if (empty == 0)
    {
        return 1;
    }

    for (k = 0; k < MAX; k++)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (board[i][j] == k)
                {
                    board[i][j] = 0;
                    if (sudoku_solve(board) == 1)
                    {
                        return 1;
                    }
                    board[i][j] = k;
                }
            }
        }
    }

    return 0;
}

int main()
{
    int **board = (int **)malloc(MAX * MAX * sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    sudoku_solve(board);

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