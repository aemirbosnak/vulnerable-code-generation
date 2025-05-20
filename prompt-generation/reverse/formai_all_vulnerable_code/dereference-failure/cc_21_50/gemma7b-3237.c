//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int seed = time(NULL);
    srand(seed);

    // Game board dimensions
    int rows = 20;
    int cols = 20;

    // Initialize the game board
    int **board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Randomly assign some cells to be alive
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (rand() % 20 == 0)
            {
                board[r][c] = 1;
            }
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                // Check the cells to the left
                for (int l = c - 1; l >= 0; l--)
                {
                    if (board[r][l] == 1)
                    {
                        neighbors++;
                    }
                }
                // Check the cells above
                for (int u = r - 1; u >= 0; u--)
                {
                    if (board[u][c] == 1)
                    {
                        neighbors++;
                    }
                }
                // Check the cells to the right
                for (int r = c + 1; r < cols; r++)
                {
                    if (board[r][c] == 1)
                    {
                        neighbors++;
                    }
                }
                // Check the cells below
                for (int b = r + 1; b < rows; b++)
                {
                    if (board[b][c] == 1)
                    {
                        neighbors++;
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

        // Increment the generation number
        generation++;

        // Print the game board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (generation > 100)
        {
            break;
        }
    }

    // Free the game board memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}