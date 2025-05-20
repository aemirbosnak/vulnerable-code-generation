//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void game_of_life(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            // Check the neighbors
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            // Apply the rules
            if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) board[i] = (int *)malloc(size * sizeof(int));

    // Initialize the board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set some initial cells to 1
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;

    // Run the game for 5 generations
    for (int gen = 0; gen < 5; gen++)
    {
        game_of_life(board, size);
    }

    // Print the final board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}