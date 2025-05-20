//Gemma-7B DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 5

typedef struct Cell
{
    int row;
    int col;
    char state;
} Cell;

void initBoard(Cell **board)
{
    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            board[r][c].row = r;
            board[r][c].col = c;
            board[r][c].state = 'o';
        }
    }
}

void displayBoard(Cell **board)
{
    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            printf("%c ", board[r][c].state);
        }
        printf("\n");
    }
}

int main()
{
    Cell **board = (Cell **)malloc(NUM_ROWS * sizeof(Cell *));
    for (int r = 0; r < NUM_ROWS; r++)
    {
        board[r] = (Cell *)malloc(NUM_COLS * sizeof(Cell));
    }

    initBoard(board);
    displayBoard(board);

    free(board);

    return 0;
}