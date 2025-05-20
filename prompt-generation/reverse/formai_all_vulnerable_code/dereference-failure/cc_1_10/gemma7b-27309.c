//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

void draw_board(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initial board setup
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board);

        // Calculate next generation
        int **next_board = (int **)malloc(MAX_SIZE * sizeof(int *));
        for (int i = 0; i < MAX_SIZE; i++)
        {
            next_board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int neighbours = 0;
                if (board[r-1][c] == 1) neighbours++;
                if (board[r+1][c] == 1) neighbours++;
                if (board[r][c-1] == 1) neighbours++;
                if (board[r][c+1] == 1) neighbours++;

                next_board[r][c] = (neighbours == 2 || neighbours == 3) ? 1 : 0;
            }
        }

        // Free the previous board and update the current board
        for (int i = 0; i < MAX_SIZE; i++)
        {
            free(board[i]);
        }
        free(board);

        board = next_board;
        generation++;

        // Check if the game has reached a certain generation or if a player has won
        if (generation == 10)
        {
            draw_board(board);
            printf("Game over after %d generations.\n", generation);
            break;
        }
    }

    return 0;
}