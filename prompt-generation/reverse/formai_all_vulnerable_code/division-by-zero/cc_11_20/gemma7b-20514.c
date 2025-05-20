//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int **board = NULL;
    int rows = 0;
    int cols = 0;

    // Allocate memory for the game board
    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place the initial organisms randomly
    for (int i = 0; i < 10; i++)
    {
        board[rand() % rows][rand() % cols] = 1;
    }

    // Simulate the game of life
    for (int t = 0; t < 100; t++)
    {
        // Calculate the number of neighbors for each organism
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
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

                // Apply the rules of life
                if (board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the game
        system("pause");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < rows; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}