//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void game_of_life(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            // Check the four neighbors
            if (r - 1 >= 0) neighbors++;
            if (r + 1 < size) neighbors++;
            if (c - 1 >= 0) neighbors++;
            if (c + 1 < size) neighbors++;

            // Apply the Game of Life rules
            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int r = 0; r < size; r++)
    {
        board[r] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;

    // Play the game for a few generations
    int generation = 0;
    while (generation < 10)
    {
        game_of_life(board, size);
        generation++;
    }

    // Print the final board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < size; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}