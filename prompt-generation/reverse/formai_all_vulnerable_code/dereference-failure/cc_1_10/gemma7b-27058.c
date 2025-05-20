//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BOARD_SIZE 9

typedef struct Cell
{
    int value;
    struct Cell** neighbours;
} Cell;

Cell** createBoard()
{
    Cell** board = (Cell**)malloc(sizeof(Cell*) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (Cell*)malloc(sizeof(Cell) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j].value = 0;
            board[i][j].neighbours = NULL;
        }
    }

    return board;
}

void solveSudoku(Cell** board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j].value == 0)
            {
                for (int k = 0; k < BOARD_SIZE; k++)
                {
                    if (board[k][j].value != 0 && board[i][k].value != 0)
                    {
                        board[i][j].neighbours[k] = 1;
                    }
                }

                if (board[i][j].neighbours[0] == 0)
                {
                    board[i][j].value = 1;
                    solveSudoku(board);
                    board[i][j].value = 0;
                }

                for (int l = 2; l <= BOARD_SIZE; l++)
                {
                    if (board[i][j].neighbours[l] == 0)
                    {
                        board[i][j].value = l;
                        solveSudoku(board);
                        board[i][j].value = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    Cell** board = createBoard();
    board[0][0].value = 5;
    board[0][1].value = 3;
    board[0][2].value = 4;
    board[1][0].value = 6;
    board[1][2].value = 2;
    board[2][0].value = 1;
    board[2][1].value = 4;
    board[2][2].value = 3;

    solveSudoku(board);

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j].value);
        }

        printf("\n");
    }

    return 0;
}