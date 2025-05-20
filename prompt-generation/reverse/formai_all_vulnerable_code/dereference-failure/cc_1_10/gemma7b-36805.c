//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void sudoku_solver(int **board)
{
    int i, j, k;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                for (k = 0; k < SIZE; k++)
                {
                    if (board[i][k] == board[k][j] && board[k][k] == 0)
                    {
                        board[i][j] = k + 1;
                        sudoku_solver(board);
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    if (sudoku_valid(board))
    {
        printf("Solved sudoku:\n");
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
}

int sudoku_valid(int **board)
{
    int i, j, k, count = 0;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 0)
            {
                count++;
                for (k = 0; k < SIZE; k++)
                {
                    if (board[i][k] == board[i][j] && board[k][j] != 0)
                    {
                        return 0;
                    }
                }
            }
        }
    }

    if (count != 9)
    {
        return 0;
    }

    return 1;
}

int main()
{
    int **board = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++)
    {
        board[i] = (int *)malloc(SIZE * sizeof(int));
    }

    board[0][0] = 5;
    board[0][1] = 3;
    board[0][2] = 0;
    board[1][0] = 6;
    board[1][1] = 0;
    board[1][2] = 0;
    board[2][0] = 0;
    board[2][1] = 0;
    board[2][2] = 0;

    sudoku_solver(board);

    return 0;
}