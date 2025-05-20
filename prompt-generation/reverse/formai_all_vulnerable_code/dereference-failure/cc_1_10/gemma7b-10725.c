//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    draw_board(board, size);

    // Check if the game is over
    if (board[0][0] || board[size - 1][size - 1])
    {
        printf("Game Over!\n");
    } else
    {
        printf("Continue playing...\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}