//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku
{
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_create(int size)
{
    Sudoku *s = (Sudoku *)malloc(sizeof(Sudoku));
    s->board = (int **)malloc(size * size * sizeof(int));
    s->size = size;
    return s;
}

void sudoku_init(Sudoku *s)
{
    for (int i = 0; i < s->size; i++)
    {
        for (int j = 0; j < s->size; j++)
        {
            s->board[i][j] = 0;
        }
    }
}

void sudoku_solve(Sudoku *s)
{
    if (sudoku_is_solved(s))
    {
        return;
    }

    for (int i = 0; i < s->size; i++)
    {
        for (int j = 0; j < s->size; j++)
        {
            if (s->board[i][j] == 0)
            {
                for (int k = 1; k <= s->size; k++)
                {
                    if (sudoku_is_valid(s, i, j, k))
                    {
                        s->board[i][j] = k;
                        sudoku_solve(s);
                        s->board[i][j] = 0;
                    }
                }
            }
        }
    }
}

int sudoku_is_solved(Sudoku *s)
{
    for (int i = 0; i < s->size; i++)
    {
        for (int j = 0; j < s->size; j++)
        {
            if (s->board[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int sudoku_is_valid(Sudoku *s, int i, int j, int k)
{
    // Check row validity
    for (int l = 0; l < s->size; l++)
    {
        if (s->board[i][l] == k)
        {
            return 0;
        }
    }

    // Check column validity
    for (int m = 0; m < s->size; m++)
    {
        if (s->board[m][j] == k)
        {
            return 0;
        }
    }

    // Check block validity
    int block_i = i / 3;
    int block_j = j / 3;
    for (int n = block_i * 3; n < block_i * 3 + 3; n++)
    {
        for (int o = block_j * 3; o < block_j * 3 + 3; o++)
        {
            if (s->board[n][o] == k)
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    Sudoku *s = sudoku_create(MAX_SIZE);
    sudoku_init(s);

    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[2][0] = 0;
    s->board[2][1] = 0;
    s->board[2][2] = 0;

    sudoku_solve(s);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}