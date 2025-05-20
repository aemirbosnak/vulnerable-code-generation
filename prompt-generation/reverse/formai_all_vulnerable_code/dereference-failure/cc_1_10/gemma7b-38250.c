//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: safe
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
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(size * size * sizeof(int));
    s->size = size;
    return s;
}

void sudoku_solve(Sudoku *s)
{
    for (int r = 0; r < s->size; r++)
    {
        for (int c = 0; c < s->size; c++)
        {
            if (s->board[r][c] == 0)
            {
                for (int i = 0; i < s->size; i++)
                {
                    for (int j = 0; j < s->size; j++)
                    {
                        if (s->board[i][j] != 0 && i != r && j != c)
                        {
                            if (s->board[i][j] == s->board[r][c])
                            {
                                s->board[r][c] = 0;
                            }
                        }
                    }
                }
                s->board[r][c] = 1;
                sudoku_solve(s);
                s->board[r][c] = 0;
            }
        }
    }
    if (sudoku_is_solved(s))
    {
        printf("Sudoku solution:\n");
        for (int r = 0; r < s->size; r++)
        {
            for (int c = 0; c < s->size; c++)
            {
                printf("%d ", s->board[r][c]);
            }
            printf("\n");
        }
    }
}

int sudoku_is_solved(Sudoku *s)
{
    for (int r = 0; r < s->size; r++)
    {
        for (int c = 0; c < s->size; c++)
        {
            if (s->board[r][c] == 0)
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

    return 0;
}