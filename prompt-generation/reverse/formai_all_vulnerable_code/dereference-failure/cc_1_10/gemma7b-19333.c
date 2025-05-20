//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

int main()
{
    int sudoku[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Solve the Sudoku
    sudoku_solver(sudoku);

    // Print the solved sudoku
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int sudoku_solver(int **sudoku)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (sudoku[i][j] == 0)
            {
                for (int k = 0; k < MAX; k++)
                {
                    if (sudoku[k][j] == 0 && k != i)
                    {
                        sudoku[i][j] = k + 1;
                        if (sudoku_solver(sudoku) == 0)
                        {
                            return 0;
                        }
                        sudoku[i][j] = 0;
                    }
                }
                return -1;
            }
        }
    }

    return 0;
}