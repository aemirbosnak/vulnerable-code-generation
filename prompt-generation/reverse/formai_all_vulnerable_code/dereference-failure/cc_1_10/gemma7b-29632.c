//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbours = 0;
            // Check the number of neighbours for each cell
            if (i > 0) neighbours++;
            if (i < size - 1) neighbours++;
            if (j > 0) neighbours++;
            if (j < size - 1) neighbours++;

            // Apply the Game of Life rules
            if (board[i][j] == 1 && neighbours < 2) board[i][j] = 0;
            if (board[i][j] == 0 && neighbours == 3) board[i][j] = 1;
        }
    }

    // Recursively call the game of life for the next generation
    if (size > 1) game_of_life(board, size);
}

int main()
{
    int size = 5;
    int **board = (int**)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board
    board[1][1] = board[2][2] = board[2][3] = 1;

    // Play the game of life
    game_of_life(board, size);

    // Print the final board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}