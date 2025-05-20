//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Create the next generation
        int **next_board = (int **)malloc(MAX * sizeof(int *));
        for (int i = 0; i < MAX; i++)
        {
            next_board[i] = (int *)malloc(MAX * sizeof(int));
        }

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                // Check the number of neighbors
                if (board[i - 1][j] == 1)
                    neighbors++;
                if (board[i + 1][j] == 1)
                    neighbors++;
                if (board[i][j - 1] == 1)
                    neighbors++;
                if (board[i][j + 1] == 1)
                    neighbors++;

                // Apply the Game of Life rules
                if (board[i][j] == 1 && neighbors < 2)
                    next_board[i][j] = 0;
                else if (board[i][j] == 0 && neighbors == 3)
                    next_board[i][j] = 1;
                else
                    next_board[i][j] = board[i][j];
            }
        }

        // Free the previous generation
        for (int i = 0; i < MAX; i++)
        {
            free(board[i]);
        }
        free(board);

        // Increment the generation number
        generation++;

        // Check if the game is over
        if (generation >= 10)
            break;

        // Copy the next generation to the board
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                board[i][j] = next_board[i][j];
            }
        }

        // Free the next generation
        for (int i = 0; i < MAX; i++)
        {
            free(next_board[i]);
        }
        free(next_board);
    }

    return 0;
}