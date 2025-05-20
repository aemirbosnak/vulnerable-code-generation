//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_board(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c]);
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

    // Initial board setup
    board[0][0] = board[0][1] = board[1][0] = board[1][1] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board);

        // Calculate next generation
        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int neighbors = 0;
                if (r - 1 >= 0) neighbors++;
                if (r + 1 < MAX_SIZE) neighbors++;
                if (c - 1 >= 0) neighbors++;
                if (c + 1 < MAX_SIZE) neighbors++;

                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        generation++;

        // Check if game is over
        if (board[MAX_SIZE - 1][MAX_SIZE - 1] == 1)
        {
            draw_board(board);
            printf("Game over after %d generations!", generation);
            break;
        }
    }

    return 0;
}