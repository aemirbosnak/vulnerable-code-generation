//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

int main()
{
    int board[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    time_t t = time(NULL);

    // Shocking Sudoku Solver Algorithm
    shocking_sudoku_solver(board);

    t = time(NULL) - t;

    printf("Time taken: %ld seconds\n", t);

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

int shocking_sudoku_solver(int **board)
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
                    if (board[k][j] == 0 && k != i)
                    {
                        board[i][j] = k + 1;
                        if (shocking_sudoku_solver(board) == 0)
                        {
                            return 0;
                        }
                        board[i][j] = 0;
                    }
                }
                return -1;
            }
        }
    }
    return 0;
}