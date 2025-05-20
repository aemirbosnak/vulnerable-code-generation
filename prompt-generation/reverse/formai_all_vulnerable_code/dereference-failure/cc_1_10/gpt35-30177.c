//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void printSudoku(int **sudoku) // function to print the Sudoku grid
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int checkRow(int **sudoku, int val, int row) // function to check if a value is present in a row
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[row][i] == val)
            return 0;
    }
    return 1;
}

int checkCol(int **sudoku, int val, int col) // function to check if a value is present in a column
{
    for(int i=0;i<9;i++)
    {
        if(sudoku[i][col] == val)
            return 0;
    }
    return 1;
}

int checkBox(int **sudoku, int val, int row, int col) // function to check if a value is present in a 3x3 box
{
    int startRow = row - row%3;
    int startCol = col - col%3;

    for(int i=startRow;i<startRow+3;i++)
    {
        for(int j=startCol;j<startCol+3;j++)
        {
            if(sudoku[i][j] == val)
                return 0;
        }
    }
    return 1;
}

int solveSudoku(int **sudoku, int row, int col) // function to solve the Sudoku
{
    if(row == 9) // we have reached the end of the grid
        return 1;

    if(col == 9) // move to the next row
        return solveSudoku(sudoku, row+1, 0);

    if(sudoku[row][col] != 0) // this cell already has a value, move to the next column
        return solveSudoku(sudoku, row, col+1);

    for(int i=1;i<=9;i++)
    {
        if(checkRow(sudoku, i, row) && checkCol(sudoku, i, col) && checkBox(sudoku, i, row, col))
        {
            sudoku[row][col] = i; // place the number in the cell

            if(solveSudoku(sudoku, row, col+1))
                return 1;

            sudoku[row][col] = 0; // backtrack
        }
    }
    return 0; // no solution found
}

int main()
{
    int **sudoku = (int **)malloc(9 * sizeof(int *)); // dynamically allocate memory for the Sudoku grid
    for(int i=0;i<9;i++)
    {
        sudoku[i] = (int *)malloc(9 * sizeof(int));
    }

    printf("Enter the Sudoku grid (0 for empty cells):\n");

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d", &sudoku[i][j]);
        }
    }

    printf("Solving the Sudoku grid...\n");

    if(solveSudoku(sudoku, 0, 0))
    {
        printf("Sudoku solved successfully!\n");
        printSudoku(sudoku);
    }
    else
    {
        printf("No solution found for the given Sudoku grid.\n");
    }

    for(int i=0;i<9;i++) // free the dynamically allocated memory
    {
        free(sudoku[i]);
    }
    free(sudoku);

    return 0;
}