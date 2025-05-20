//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void draw_board(char **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    char **board = (char **)malloc(size * sizeof(char *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (char *)malloc(size * sizeof(char));
    }

    // Initial board setup
    board[1][1] = 'O';
    board[2][2] = 'O';
    board[3][2] = 'O';

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generation);

        // Calculate next generation
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int neighbours = 0;
                if (r > 0) neighbours++;
                if (r < size - 1) neighbours++;
                if (c > 0) neighbours++;
                if (c < size - 1) neighbours++;

                if (board[r][c] == 'O' && neighbours == 3) board[r][c] = 'O';
                else if (board[r][c] == '.' && neighbours == 3) board[r][c] = 'O';
            }
        }

        generation++;
        if (board[2][2] == 'O') break; // Game over
    }

    draw_board(board, size);
    printf("Game Over!\n");

    free(board);
    return 0;
}