//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board)
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int r = 0; r < 5; r++)
    {
        board[r] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board);

        // Calculate the next generation
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                int neighbors = 0;
                if (board[r - 1][c] == 1) neighbors++;
                if (board[r + 1][c] == 1) neighbors++;
                if (board[r][c - 1] == 1) neighbors++;
                if (board[r][c + 1] == 1) neighbors++;

                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation == 10) break;
    }

    draw_board(board);

    free(board);

    return 0;
}