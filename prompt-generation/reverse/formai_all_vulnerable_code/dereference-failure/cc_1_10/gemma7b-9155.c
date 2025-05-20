//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void drawBoard(int **board)
{
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int r = 0; r < MAX; r++)
    {
        board[r] = (int *)malloc(MAX * sizeof(int));
    }

    int seed = time(NULL);
    srand(seed);

    // Randomly initialize the board
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        drawBoard(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **nextBoard = (int **)malloc(MAX * sizeof(int *));
        for (int r = 0; r < MAX; r++)
        {
            nextBoard[r] = (int *)malloc(MAX * sizeof(int));
        }

        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
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

                nextBoard[r][c] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
        }

        free(board);
        board = nextBoard;
        generation++;

        // Check if the game is over
        if (generation == 10)
        {
            drawBoard(board);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}