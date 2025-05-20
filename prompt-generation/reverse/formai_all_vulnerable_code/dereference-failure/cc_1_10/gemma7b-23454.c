//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void game_of_life(int **board, int x, int y)
{
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            int neighbors = 0;
            // Check the four neighbors
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < x) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < y) neighbors++;

            // Apply the Game of Life rules
            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int x = 5;
    int y = 5;
    int **board = (int **)malloc(x * sizeof(int *) + y * sizeof(int));
    for (int i = 0; i < x; i++) board[i] = (int *)malloc(y * sizeof(int));

    // Initialize the board
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            board[r][c] = 0;
        }
    }

    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    game_of_life(board, x, y);

    // Print the board
    for (int r = 0; r < x; r++)
    {
        for (int c = 0; c < y; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}