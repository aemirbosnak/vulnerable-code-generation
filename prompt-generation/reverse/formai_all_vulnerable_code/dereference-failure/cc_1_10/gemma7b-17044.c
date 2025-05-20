//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the Game of Life rules
void game_of_life(int **board, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbours = 0;
            // Check the number of neighbours
            if (r > 0) neighbours++;
            if (r < rows - 1) neighbours++;
            if (c > 0) neighbours++;
            if (c < cols - 1) neighbours++;

            // Apply the rules
            if (board[r][c] == 1 && neighbours < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbours == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    // Create a game board
    int **board = NULL;
    int rows = 5;
    int cols = 5;
    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board
    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    // Play the game
    game_of_life(board, rows, cols);

    // Print the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}