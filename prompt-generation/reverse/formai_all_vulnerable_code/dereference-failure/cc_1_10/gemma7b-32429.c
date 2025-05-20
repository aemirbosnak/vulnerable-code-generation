//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void play_game_of_life(int **board, int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            int neighbors = 0;
            // Check the number of neighbors for the current cell
            if (row > 0) neighbors++;
            if (row < size - 1) neighbors++;
            if (col > 0) neighbors++;
            if (col < size - 1) neighbors++;

            // Apply the Game of Life rules
            if (board[row][col] == 1 && neighbors < 2) board[row][col] = 0;
            else if (board[row][col] == 0 && neighbors == 3) board[row][col] = 1;
        }
    }
}

int main()
{
    int size = 10;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) board[i] = (int *)malloc(size * sizeof(int));

    // Initial board setup
    board[1][1] = board[2][2] = board[3][3] = 1;

    // Play the game for 5 generations
    for (int gen = 0; gen < 5; gen++)
    {
        play_game_of_life(board, size);
    }

    // Print the final board
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < size; i++) free(board[i]);
    free(board);

    return 0;
}