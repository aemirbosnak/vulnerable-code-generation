//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **board, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbours = 0;
            // Check the neighbours to the current cell
            if (r - 1 >= 0) neighbours++;
            if (r + 1 < rows) neighbours++;
            if (c - 1 >= 0) neighbours++;
            if (c + 1 < cols) neighbours++;

            // Apply the Game of Life rules
            if (board[r][c] == 0 && neighbours == 3) board[r][c] = 1;
            if (board[r][c] == 1 && (neighbours == 2 || neighbours == 3)) board[r][c] = 1;
            else board[r][c] = 0;
        }
    }
}

int main()
{
    int rows = 5;
    int cols = 5;
    int **board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) board[i] = (int *)malloc(cols * sizeof(int));

    // Initialize the board
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

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
    for (int i = 0; i < rows; i++) free(board[i]);
    free(board);

    return 0;
}