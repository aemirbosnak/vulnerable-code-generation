//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **board)
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
        return;
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (board[i][j] == 0)
            {
                for (k = 1; k <= MAX; k++)
                {
                    if (isValid(board, i, j, k) && board[i][j] == 0)
                    {
                        board[i][j] = k;
                        solveSudoku(board);
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    return;
}

int isValid(int **board, int i, int j, int k)
{
    int rowValid = 1, columnValid = 1, boxValid = 1;

    // Row Validation
    for (int l = 0; l < MAX; l++)
    {
        if (board[i][l] == k)
        {
            rowValid = 0;
        }
    }

    // Column Validation
    for (int m = 0; m < MAX; m++)
    {
        if (board[m][j] == k)
        {
            columnValid = 0;
        }
    }

    // Box Validation
    int boxI = i / 3;
    int boxJ = j / 3;
    for (int n = boxI * 3; n < boxI * 3 + 3; n++)
    {
        for (int o = boxJ * 3; o < boxJ * 3 + 3; o++)
        {
            if (board[n][o] == k)
            {
                boxValid = 0;
            }
        }
    }

    return rowValid && columnValid && boxValid;
}

int main()
{
    int **board = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

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