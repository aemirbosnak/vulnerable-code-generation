//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9

typedef struct Sudoku
{
    int **board;
    int size;
    int **solution;
    int solved;
} Sudoku;

Sudoku *sudoku_init(int size)
{
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++)
    {
        s->board[i] = malloc(sizeof(int) * size);
    }
    s->size = size;
    s->solution = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++)
    {
        s->solution[i] = malloc(sizeof(int) * size);
    }
    s->solved = 0;
    return s;
}

void sudoku_solve(Sudoku *s)
{
    if (s->solved)
    {
        return;
    }

    for (int r = 0; r < s->size; r++)
    {
        for (int c = 0; c < s->size; c++)
        {
            if (s->board[r][c] == 0)
            {
                for (int n = 1; n <= s->size; n++)
                {
                    if (sudoku_valid(s, r, c, n) && s->solution[r][c] == 0)
                    {
                        s->solution[r][c] = n;
                        sudoku_solve(s);
                        s->solution[r][c] = 0;
                    }
                }
            }
        }
    }

    s->solved = 1;
}

int sudoku_valid(Sudoku *s, int r, int c, int n)
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->solution[r][i] == n)
        {
            return 0;
        }
    }

    for (int i = 0; i < s->size; i++)
    {
        if (s->solution[i][c] == n)
        {
            return 0;
        }
    }

    int box_x = (r / 3) * 3;
    int box_y = (c / 3) * 3;
    for (int i = box_x; i < box_x + 3; i++)
    {
        for (int j = box_y; j < box_y + 3; j++)
        {
            if (s->solution[i][j] == n)
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    Sudoku *s = sudoku_init(9);
    sudoku_solve(s);

    for (int r = 0; r < s->size; r++)
    {
        for (int c = 0; c < s->size; c++)
        {
            printf("%d ", s->solution[r][c]);
        }
        printf("\n");
    }

    return 0;
}