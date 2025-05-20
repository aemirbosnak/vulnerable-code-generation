//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void drawBoard(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c] == 0 ? '.' : board[r][c] == 1 ? '*' : ' ');
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

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game
    int generation = 0;
    while (1)
    {
        drawBoard(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **nextBoard = (int **)malloc(MAX_SIZE * sizeof(int *));
        for (int r = 0; r < MAX_SIZE; r++)
        {
            nextBoard[r] = (int *)malloc(MAX_SIZE * sizeof(int));
        }

        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int numNeighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            numNeighbors++;
                        }
                    }
                }

                nextBoard[r][c] = numNeighbors >= 2 && numNeighbors <= 3 ? 1 : 0;
            }
        }

        // Free the old board and copy the new one
        for (int r = 0; r < MAX_SIZE; r++)
        {
            free(board[r]);
        }
        free(board);

        board = nextBoard;
        generation++;

        // Check if the game is over
        if (board[0][0] == 0)
        {
            drawBoard(board);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}