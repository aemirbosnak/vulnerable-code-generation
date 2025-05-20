//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int alive_neighbors = 0;
            // Check the neighbors of the current cell
            if (i > 0) alive_neighbors++;
            if (i < n - 1) alive_neighbors++;
            if (j > 0) alive_neighbors++;
            if (j < m - 1) alive_neighbors++;

            // Apply the Game of Life rules
            if (board[i][j] == 1 && alive_neighbors < 2) board[i][j] = 0;
            if (board[i][j] == 0 && alive_neighbors == 3) board[i][j] = 1;
        }
    }
}

int main()
{
    int n = 5;
    int m = 5;
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) board[i] = (int *)malloc(m * sizeof(int));

    // Initialize the board
    board[1][1] = board[2][2] = board[3][3] = 1;

    // Play the game for multiple generations
    for (int gen = 0; gen < 10; gen++)
    {
        game_of_life(board, n, m);

        // Print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}