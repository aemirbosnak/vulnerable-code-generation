//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complex
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

    // Randomly set some cells to 1
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (rand() % 2 == 0)
            {
                board[i][j] = 1;
            }
        }
    }

    // Run the game for 10 generations
    for (int generation = 0; generation < 10; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                // Check the four directions
                if (board[i - 1][j] == 1)
                {
                    neighbors++;
                }
                if (board[i + 1][j] == 1)
                {
                    neighbors++;
                }
                if (board[i][j - 1] == 1)
                {
                    neighbors++;
                }
                if (board[i][j + 1] == 1)
                {
                    neighbors++;
                }

                // Apply the rules of life
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

        // Print the board
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}