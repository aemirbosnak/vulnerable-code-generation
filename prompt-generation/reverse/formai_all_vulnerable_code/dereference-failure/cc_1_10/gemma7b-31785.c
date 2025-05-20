//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

void display_board(int **board)
{
    for (int r = 0; r < MAX_CELLS; r++)
    {
        for (int c = 0; c < MAX_CELLS; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void update_board(int **board)
{
    for (int r = 0; r < MAX_CELLS; r++)
    {
        for (int c = 0; c < MAX_CELLS; c++)
        {
            int num_neighbors = 0;
            if (board[r - 1][c] == 1) num_neighbors++;
            if (board[r + 1][c] == 1) num_neighbors++;
            if (board[r][c - 1] == 1) num_neighbors++;
            if (board[r][c + 1] == 1) num_neighbors++;

            if (board[r][c] == 0 && num_neighbors == 3) board[r][c] = 1;
            else if (board[r][c] == 1 && (num_neighbors < 2 || num_neighbors > 3)) board[r][c] = 0;
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int r = 0; r < MAX_CELLS; r++) board[r] = (int *)malloc(MAX_CELLS * sizeof(int));

    // Initial board setup
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    int num_generations = 0;

    // Game loop
    while (num_generations < 10)
    {
        update_board(board);
        display_board(board);
        num_generations++;
    }

    return 0;
}