//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

void draw_board(int **board)
{
    int i, j;
    for (i = 0; i < MAX_CELLS; i++)
    {
        for (j = 0; j < MAX_CELLS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = NULL;
    int i, j, r, s;

    board = malloc(MAX_CELLS * sizeof(int *));
    for (i = 0; i < MAX_CELLS; i++)
    {
        board[i] = malloc(MAX_CELLS * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < MAX_CELLS; i++)
    {
        for (j = 0; j < MAX_CELLS; j++)
        {
            board[i][j] = 0;
        }
    }

    // Simulate the game
    for (r = 0; r < 10; r++)
    {
        draw_board(board);

        // Calculate the next generation
        for (i = 0; i < MAX_CELLS; i++)
        {
            for (j = 0; j < MAX_CELLS; j++)
            {
                int neighbors = 0;
                if (board[i-1][j] == 1) neighbors++;
                if (board[i+1][j] == 1) neighbors++;
                if (board[i][j-1] == 1) neighbors++;
                if (board[i][j+1] == 1) neighbors++;

                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
                if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
            }
        }
    }

    draw_board(board);

    free(board);

    return 0;
}