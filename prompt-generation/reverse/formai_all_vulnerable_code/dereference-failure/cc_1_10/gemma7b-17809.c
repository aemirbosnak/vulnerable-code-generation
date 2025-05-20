//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void drawBoard(int **board)
{
    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 20; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void nextGeneration(int **board)
{
    int **newBoard = malloc(20 * sizeof(int *));
    for (int r = 0; r < 20; r++)
    {
        newBoard[r] = malloc(20 * sizeof(int));
    }

    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 20; c++)
        {
            int neighbors = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    if (board[r + dr][c + dc] == 1)
                    {
                        neighbors++;
                    }
                }
            }

            newBoard[r][c] = (board[r][c] == 1 && neighbors >= 2) || neighbors == 3;
        }
    }

    free(board);
    board = newBoard;
}

int main()
{
    int **board = malloc(20 * sizeof(int *));
    for (int r = 0; r < 20; r++)
    {
        board[r] = malloc(20 * sizeof(int));
    }

    // Seed the board with random life
    for (int r = 0; r < 20; r++)
    {
        for (int c = 0; c < 20; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Draw the initial board
    drawBoard(board);

    // Simulate game of life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        nextGeneration(board);
        drawBoard(board);
    }

    // Free the memory
    free(board);

    return 0;
}