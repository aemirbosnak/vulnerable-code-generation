//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

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

    // Solver algorithm
    sudoku_solver(sudoku);

    // Print the solution
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
    // Iterate over the Sudoku grid
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            // If the cell is empty
            if (sudoku[i][j] == 0)
            {
                // Iterate over the possible numbers for the cell
                for (int n = 1; n <= MAX; n++)
                {
                    // If the number is not used in the row, column, or 3x3 box
                    if (sudoku_valid(sudoku, i, j, n))
                    {
                        // Set the number in the cell
                        sudoku[i][j] = n;

                        // Recursively solve the Sudoku
                        if (sudoku_solver(sudoku) == 0)
                        {
                            return 0;
                        }

                        // Reset the number in the cell
                        sudoku[i][j] = 0;
                    }
                }

                // If no solution is found, return -1
                return -1;
            }
        }
    }

    // The Sudoku is solved
    return 0;
}

int sudoku_valid(int **sudoku, int i, int j, int n)
{
    // Check if the number is used in the row
    for (int k = 0; k < MAX; k++)
    {
        if (sudoku[i][k] == n)
        {
            return 0;
        }
    }

    // Check if the number is used in the column
    for (int l = 0; l < MAX; l++)
    {
        if (sudoku[l][j] == n)
        {
            return 0;
        }
    }

    // Check if the number is used in the 3x3 box
    int box_i = i / 3;
    int box_j = j / 3;
    for (int m = box_i * 3; m < box_i * 3 + 3; m++)
    {
        for (int n = box_j * 3; n < box_j * 3 + 3; n++)
        {
            if (sudoku[m][n] == n)
            {
                return 0;
            }
        }
    }

    // The number is valid
    return 1;
}