//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void drawBoard(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c] == 0 ? '.' : board[r][c] == 1 ? 'O' : '_');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    int game_of_life(int **board);

    game_of_life(board);

    drawBoard(board);

    free(board);

    return 0;
}

int game_of_life(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            int neighbors = 0;
            if (r > 0) neighbors++;
            if (r < MAX_SIZE - 1) neighbors++;
            if (c > 0) neighbors++;
            if (c < MAX_SIZE - 1) neighbors++;

            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }

    return 0;
}