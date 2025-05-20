//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void print_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] + 48);
        }
        printf("\n");
    }
}

void update_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            if (r - 1) neighbors++;
            if (r + 1) neighbors++;
            if (c - 1) neighbors++;
            if (c + 1) neighbors++;

            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 2;
            if (board[r][c] == 2 && neighbors < 2) board[r][c] = 0;
        }
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) board[i] = (int *)malloc(size * sizeof(int));

    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    print_board(board, size);

    update_board(board, size);

    print_board(board, size);

    free(board);

    return 0;
}