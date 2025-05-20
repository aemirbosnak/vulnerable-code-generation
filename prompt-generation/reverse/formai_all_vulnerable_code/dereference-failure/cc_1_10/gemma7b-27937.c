//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
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

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initial board setup
    board[1][2] = 1;
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generation);

        // Calculate next generation
        int **next_board = (int **)malloc(size * sizeof(int *));
        for (int r = 0; r < size; r++)
        {
            next_board[r] = (int *)malloc(size * sizeof(int));
        }

        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < size - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < size - 1) neighbors++;

                next_board[r][c] = board[r][c] * (neighbors == 2);
            }
        }

        // Free the previous board
        for (int r = 0; r < size; r++)
        {
            free(board[r]);
        }
        free(board);

        // Copy the next generation board to the current board
        board = next_board;

        // Increment the generation number
        generation++;

        // Check if the game is over
        if (board[0][0] == 1)
        {
            draw_board(board, size);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}