//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place the starting pieces
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate the game
    int generation = 0;
    while (board[2][2] != 1)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int num_neighbors = 0;
                if (board[i - 1][j] == 1) num_neighbors++;
                if (board[i + 1][j] == 1) num_neighbors++;
                if (board[i][j - 1] == 1) num_neighbors++;
                if (board[i][j + 1] == 1) num_neighbors++;

                // Apply the Game of Life rules
                if (board[i][j] == 0 && num_neighbors == 3) board[i][j] = 1;
                if (board[i][j] == 1 && (num_neighbors < 2 || num_neighbors > 3)) board[i][j] = 0;
            }
        }

        // Increment the generation counter
        generation++;

        // Print the game board
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Pause the game
        system("pause");
    }

    // Print the final game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}