//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    // Create a 2D array to store the game board.
    int **board = malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = malloc(5 * sizeof(int));
    }

    // Initialize the game board with random values.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the game board.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Simulate the game of life.
    for (int t = 0; t < 20; t++)
    {
        // Calculate the number of neighbors for each cell.
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (board[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of life.
                if (board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Print the game board.
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board.
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);
}

int main()
{
    play_game();

    return 0;
}