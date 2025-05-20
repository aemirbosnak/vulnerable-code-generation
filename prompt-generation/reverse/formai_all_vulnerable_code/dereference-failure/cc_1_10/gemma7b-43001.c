//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 9

typedef struct Sudoku
{
    int **board;
    int size;
} Sudoku;

Sudoku *sudoku_new(int size)
{
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++)
    {
        s->board[i] = malloc(sizeof(int) * size);
    }
    s->size = size;
    return s;
}

void sudoku_set(Sudoku *s, int x, int y, int value)
{
    s->board[x][y] = value;
}

int sudoku_get(Sudoku *s, int x, int y)
{
    return s->board[x][y];
}

void sudoku_solve(Sudoku *s)
{
    for (int x = 0; x < s->size; x++)
    {
        for (int y = 0; y < s->size; y++)
        {
            if (sudoku_get(s, x, y) == 0)
            {
                for (int i = 0; i < s->size; i++)
                {
                    for (int j = 0; j < s->size; j++)
                    {
                        if (sudoku_get(s, i, j) != 0 && i != x && j != y)
                        {
                            int k = sudoku_get(s, i, j);
                            if (k == sudoku_get(s, x, y))
                            {
                                sudoku_set(s, x, y, k);
                                sudoku_solve(s);
                                sudoku_set(s, x, y, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    if (sudoku_is_solved(s))
    {
        printf("Sudoku solution:\n");
        for (int x = 0; x < s->size; x++)
        {
            for (int y = 0; y < s->size; y++)
            {
                printf("%d ", sudoku_get(s, x, y));
            }
            printf("\n");
        }
    }
}

int sudoku_is_solved(Sudoku *s)
{
    for (int x = 0; x < s->size; x++)
    {
        for (int y = 0; y < s->size; y++)
        {
            if (sudoku_get(s, x, y) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    Sudoku *s = sudoku_new(9);
    sudoku_set(s, 0, 0, 5);
    sudoku_set(s, 0, 1, 3);
    sudoku_set(s, 0, 2, 4);
    sudoku_set(s, 1, 0, 6);
    sudoku_set(s, 1, 2, 2);
    sudoku_set(s, 2, 0, 1);
    sudoku_set(s, 2, 2, 3);
    sudoku_set(s, 3, 0, 4);
    sudoku_set(s, 3, 2, 5);
    sudoku_set(s, 4, 0, 2);
    sudoku_set(s, 4, 1, 6);
    sudoku_set(s, 4, 2, 3);
    sudoku_set(s, 5, 0, 3);
    sudoku_set(s, 5, 1, 4);
    sudoku_set(s, 5, 2, 2);
    sudoku_set(s, 6, 0, 1);
    sudoku_set(s, 6, 1, 4);
    sudoku_set(s, 6, 2, 6);
    sudoku_set(s, 7, 0, 2);
    sudoku_set(s, 7, 1, 8);
    sudoku_set(s, 7, 2, 6);
    sudoku_set(s, 8, 0, 6);
    sudoku_set(s, 8, 1, 4);
    sudoku_set(s, 8, 2, 8);
    sudoku_set(s, 9, 0, 3);
    sudoku_set(s, 9, 1, 2);
    sudoku_set(s, 9, 2, 4);

    sudoku_solve(s);

    return 0;
}