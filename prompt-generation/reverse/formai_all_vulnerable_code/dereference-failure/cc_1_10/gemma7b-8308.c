//Gemma-7B DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a custom board structure
    typedef struct Board
    {
        int **grid;
        int rows;
        int cols;
    } Board;

    // Create a new board
    Board *board = malloc(sizeof(Board));
    board->rows = 5;
    board->cols = 5;
    board->grid = malloc(board->rows * board->cols * sizeof(int));

    // Initialize the board
    for (int r = 0; r < board->rows; r++)
    {
        for (int c = 0; c < board->cols; c++)
        {
            board->grid[r][c] = 0;
        }
    }

    // Place the pieces on the board
    board->grid[2][2] = 1;
    board->grid[3][2] = 2;

    // Play the game
    int turn = 0;
    while (board->grid[board->rows - 1][board->cols - 1] != 3)
    {
        // Get the player's move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);

        // Validate the move
        if (row < 0 || row >= board->rows || col < 0 || col >= board->cols)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        board->grid[row][col] = turn + 1;

        // Check if the player has won
        if (board->grid[board->rows - 1][board->cols - 1] == turn + 1)
        {
            printf("Congratulations! You won!\n");
        }

        // Next turn
        turn++;
    }

    // Free the memory
    free(board->grid);
    free(board);

    return 0;
}