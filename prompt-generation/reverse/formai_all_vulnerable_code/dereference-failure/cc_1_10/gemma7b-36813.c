//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
                    if (board[i][k] == 0 && board[k][j] == 0 && k != j)
                    {
                        board[i][j] = k + 1;
                        solveSudoku(board);
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    return;
}

int main()
{
    int **board = (int **)malloc(MAX * MAX * sizeof(int));

    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    time_t start, end;

    start = time(NULL);
    solveSudoku(board);
    end = time(NULL);

    printf("Time taken: %ld seconds\n", end - start);

    return 0;
}