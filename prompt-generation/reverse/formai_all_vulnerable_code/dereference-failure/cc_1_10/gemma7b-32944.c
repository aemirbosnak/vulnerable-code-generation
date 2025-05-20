//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct Sudoku_board {
    int board[MAX_SIZE][MAX_SIZE];
    int size;
} Sudoku_board;

Sudoku_board *sudoku_board_new(int size)
{
    Sudoku_board *board = malloc(sizeof(Sudoku_board));
    board->size = size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board->board[i][j] = 0;
        }
    }
    return board;
}

void sudoku_board_solve(Sudoku_board *board)
{
    if (board->size == 0)
    {
        return;
    }

    for (int i = 0; i < board->size; i++)
    {
        for (int j = 0; j < board->size; j++)
        {
            if (board->board[i][j] == 0)
            {
                for (int k = 0; k < board->size; k++)
                {
                    if (k != i && board->board[k][j] == 0)
                    {
                        board->board[i][j] = k + 1;
                        sudoku_board_solve(board);
                        board->board[i][j] = 0;
                    }
                }
            }
        }
    }

    return;
}

int main()
{
    Sudoku_board *board = sudoku_board_new(9);
    sudoku_board_solve(board);

    for (int i = 0; i < board->size; i++)
    {
        for (int j = 0; j < board->size; j++)
        {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }

    return 0;
}