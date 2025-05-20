//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < rows) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < cols) neighbors++;

            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int **board = NULL;
    int rows = 5;
    int cols = 5;

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    game_of_life(board, rows, cols);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}