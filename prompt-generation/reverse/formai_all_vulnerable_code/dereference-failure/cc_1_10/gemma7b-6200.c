//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 9
#define EMPTY_VAL 0

void initialize_sudoku(int **grid);
void solve_sudoku(int **grid);
void print_sudoku(int **grid);

int main()
{
    int **grid = NULL;
    int i, j, k;

    grid = (int **)malloc(GRID_SIZE * sizeof(int *));
    for (i = 0; i < GRID_SIZE; i++)
    {
        grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
        for (j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = EMPTY_VAL;
        }
    }

    initialize_sudoku(grid);
    solve_sudoku(grid);
    print_sudoku(grid);

    return 0;
}

void initialize_sudoku(int **grid)
{
    int i, j, k;

    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            if (i == 0 && j == 0)
            {
                grid[i][j] = 5;
            }
            else if (i == 2 && j == 5)
            {
                grid[i][j] = 3;
            }
            else if (i == 4 && j == 2)
            {
                grid[i][j] = 9;
            }
            else if (i == 6 && j == 6)
            {
                grid[i][j] = 1;
            }
            else if (i == 8 && j == 8)
            {
                grid[i][j] = 4;
            }
        }
    }
}

void solve_sudoku(int **grid)
{
    int i, j, k;

    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j] == EMPTY_VAL)
            {
                for (k = 0; k < GRID_SIZE; k++)
                {
                    if (grid[i][k] == EMPTY_VAL && grid[k][j] == EMPTY_VAL)
                    {
                        grid[i][j] = k + 1;
                        solve_sudoku(grid);
                        grid[i][j] = EMPTY_VAL;
                    }
                }
            }
        }
    }
}

void print_sudoku(int **grid)
{
    int i, j;

    for (i = 0; i < GRID_SIZE; i++)
    {
        for (j = 0; j < GRID_SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}