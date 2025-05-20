//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void game_of_life(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            // Check the four neighbors
            if (r > 0) neighbors++;
            if (r < size - 1) neighbors++;
            if (c > 0) neighbors++;
            if (c < size - 1) neighbors++;

            // Apply the rules
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3)) board[r][c] = 0;
        }
    }
}

int main()
{
    int size = 10;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++) board[r] = (int *)malloc(size * sizeof(int));

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++) board[r][c] = 0;
    }

    // Set some initial cells to 1
    board[2][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;

    // Run the game for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        game_of_life(board, size);
    }

    // Print the final board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++) printf("%d ", board[r][c]);
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < size; r++) free(board[r]);
    free(board);

    return 0;
}