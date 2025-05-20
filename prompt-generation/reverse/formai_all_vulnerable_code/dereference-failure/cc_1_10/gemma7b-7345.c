//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void drawBoard(int **board)
{
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(DIM * sizeof(int *));
    for (int r = 0; r < DIM; r++)
    {
        board[r] = (int *)malloc(DIM * sizeof(int));
    }

    // Initial board setup
    board[10][10] = 1;
    board[10][11] = 1;
    board[11][10] = 1;
    board[11][11] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        drawBoard(board);
        printf("Generation: %d\n", generation);

        // Calculate next generation
        for (int r = 0; r < DIM; r++)
        {
            for (int c = 0; c < DIM; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != -1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = -1;
                }
                else if (board[r][c] == -1 && neighbors >= 2)
                {
                    board[r][c] = 1;
                }
            }
        }

        generation++;

        // Check if game is over
        if (generation == 10)
        {
            drawBoard(board);
            printf("Game Over!\n");
            break;
        }
    }

    // Free memory
    for (int r = 0; r < DIM; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}