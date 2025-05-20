//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

void sudoku_solver(int **board)
{
    int i, j, k, flag = 0;

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
                        flag = 1;
                    }
                }

                if (flag == 0)
                {
                    board[i][j] = 2;
                    sudoku_solver(board);
                    board[i][j] = 0;
                }
            }
        }
    }

    if (flag == 0)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                if (board[i][j] == 2)
                {
                    board[i][j] = 3;
                }
            }
        }
    }
}

int main()
{
    int board[MAX][MAX] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                              {6, 0, 0, 1, 9, 5, 0, 0, 0},
                              {0, 9, 8, 0, 0, 0, 0, 0, 0},
                              {8, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0}};

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