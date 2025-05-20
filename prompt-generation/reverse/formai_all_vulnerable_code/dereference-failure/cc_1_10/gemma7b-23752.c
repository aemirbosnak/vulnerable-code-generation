//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the Game of Life rules
#define ALIVE 1
#define DEAD 0
#define BREEDS 2

void playGame(int **board, int size)
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
            if (board[r][c] == ALIVE)
            {
                if (neighbors < 2) board[r][c] = DEAD;
                else if (neighbors > 3) board[r][c] = DEAD;
            }
            else if (neighbors == 3) board[r][c] = ALIVE;
        }
    }
}

int main()
{
    // Create a 5x5 board
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++) board[r] = (int *)malloc(size * sizeof(int));

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++) board[r][c] = DEAD;
    }

    // Set some cells to ALIVE
    board[1][1] = ALIVE;
    board[2][2] = ALIVE;
    board[3][3] = ALIVE;

    // Play the game for 10 generations
    for (int gen = 0; gen < 10; gen++) playGame(board, size);

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