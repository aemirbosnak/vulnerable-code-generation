//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku
{
    int **board;
    int **solve;
    int size;
} Sudoku;

Sudoku* sudoku_create(int size)
{
    Sudoku* s = malloc(sizeof(Sudoku));
    s->board = malloc(size * size * sizeof(int));
    s->solve = malloc(size * size * sizeof(int));
    s->size = size;

    return s;
}

void sudoku_init(Sudoku* s)
{
    for (int i = 0; i < s->size * s->size; i++)
    {
        s->board[i] = 0;
        s->solve[i] = 0;
    }
}

void sudoku_solve(Sudoku* s)
{
    for (int i = 0; i < s->size * s->size; i++)
    {
        if (s->board[i] == 0)
        {
            for (int r = 0; r < s->size; r++)
            {
                for (int c = 0; c < s->size; c++)
                {
                    if (s->board[r * s->size + c] == 0 && s->solve[r * s->size + c] == 0)
                    {
                        s->board[i] = s->solve[r * s->size + c] = 1;
                        sudoku_solve(s);
                        s->board[i] = s->solve[r * s->size + c] = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    Sudoku* s = sudoku_create(9);
    sudoku_init(s);

    s->board[0] = 5;
    s->board[3] = 3;
    s->board[6] = 4;
    s->board[8] = 2;

    sudoku_solve(s);

    for (int i = 0; i < 81; i++)
    {
        printf("%d ", s->board[i]);
    }

    printf("\n");

    return 0;
}