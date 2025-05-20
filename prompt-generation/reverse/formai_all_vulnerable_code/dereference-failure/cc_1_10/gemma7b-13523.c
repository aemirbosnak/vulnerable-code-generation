//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void solveSudoku(int **board)
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
                    if (board[i][k] == board[k][j] && board[k][j] != 0)
                    {
                        board[i][j] = board[k][j];
                        solveSudoku(board);
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    if (board[0][0] == MAX)
    {
        printf("Sudoku solution:\n");
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
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
    board[0][1] = 3;
    board[0][2] = 0;
    board[1][0] = 6;
    board[1][1] = 0;
    board[1][2] = 0;
    board[2][0] = 9;
    board[2][1] = 0;
    board[2][2] = 0;

    solveSudoku(board);

    return 0;
}