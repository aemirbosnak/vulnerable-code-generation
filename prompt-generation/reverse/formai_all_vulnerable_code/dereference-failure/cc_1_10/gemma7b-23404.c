//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 10

void drawBoard(int **board)
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(BOARD_SIZE * sizeof(int*));
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        board[r] = (int*)malloc(BOARD_SIZE * sizeof(int));
    }

    int numSimulations = 1000;
    for (int sim = 0; sim < numSimulations; sim++)
    {
        // Randomly choose a cell to percolate
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        // If the cell is not already percolated and it's a border cell, percolate
        if (!board[row][col] && (row == 0 || col == 0 || row == BOARD_SIZE - 1 || col == BOARD_SIZE - 1))
        {
            board[row][col] = 1;

            // Percolate the adjacent cells
            if (row > 0) board[row - 1][col] = 1;
            if (row < BOARD_SIZE - 1) board[row + 1][col] = 1;
            if (col > 0) board[row][col - 1] = 1;
            if (col < BOARD_SIZE - 1) board[row][col + 1] = 1;
        }
    }

    drawBoard(board);

    free(board);

    return 0;
}