//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_of_life(int **board, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < rows) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < cols) neighbors++;

            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int rows = 10;
    int cols = 10;
    int **board = malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++) board[r] = malloc(cols * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Create a random board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Play the game for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        game_of_life(board, rows, cols);
    }

    // Print the final board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++) free(board[r]);
    free(board);

    return 0;
}