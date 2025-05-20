//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

typedef struct Sudoku
{
    int **board;
    int size;
    int **solution;
} Sudoku;

Sudoku *sudoku_new(int size)
{
    Sudoku *s = malloc(sizeof(Sudoku));
    s->board = malloc(sizeof(int *) * size);
    s->solution = malloc(sizeof(int *) * size);
    s->size = size;
    for (int i = 0; i < size; i++)
    {
        s->board[i] = malloc(sizeof(int) * size);
        s->solution[i] = malloc(sizeof(int) * size);
    }
    return s;
}

void sudoku_solve(Sudoku *s)
{
    for (int i = 0; i < s->size; i++)
    {
        for (int j = 0; j < s->size; j++)
        {
            if (s->board[i][j] == 0)
            {
                for (int k = 0; k < s->size; k++)
                {
                    if (s->board[k][j] != 0 && s->solution[i][k] != 0)
                    {
                        if (s->board[k][j] == s->solution[i][k])
                        {
                            s->board[i][j] = s->solution[i][k];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    Sudoku *s = sudoku_new(9);

    s->board[0][0] = 5;
    s->board[0][1] = 3;
    s->board[0][2] = 0;
    s->board[0][3] = 0;
    s->board[0][4] = 0;
    s->board[0][5] = 0;
    s->board[0][6] = 0;
    s->board[0][7] = 0;
    s->board[0][8] = 0;

    s->board[1][0] = 6;
    s->board[1][1] = 0;
    s->board[1][2] = 0;
    s->board[1][3] = 0;
    s->board[1][4] = 0;
    s->board[1][5] = 0;
    s->board[1][6] = 0;
    s->board[1][7] = 0;
    s->board[1][8] = 0;

    s->board[2][0] = 0;
    s->board[2][1] = 0;
    s->board[2][2] = 0;
    s->board[2][3] = 0;
    s->board[2][4] = 0;
    s->board[2][5] = 0;
    s->board[2][6] = 0;
    s->board[2][7] = 0;
    s->board[2][8] = 0;

    sudoku_solve(s);

    for (int i = 0; i < s->size; i++)
    {
        for (int j = 0; j < s->size; j++)
        {
            printf("%d ", s->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}