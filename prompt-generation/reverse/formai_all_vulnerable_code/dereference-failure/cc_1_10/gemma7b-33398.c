//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a module to handle the game board
void game_board(int **board, int size)
{
    // Allocate memory for the board
    board = malloc(size * size * sizeof(int));

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }
}

// Define a module to handle player moves
void player_move(int **board, int size, int player)
{
    // Get the player's move
    int row, column;
    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &column);

    // Validate the move
    if (row < 0 || row >= size || column < 0 || column >= size)
    {
        printf("Invalid move.\n");
        return;
    }

    // Mark the move
    board[row][column] = player;
}

// Define a module to check if a player has won
int has_won(int **board, int size, int player)
{
    // Check rows
    for (int r = 0; r < size; r++)
    {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < size; c++)
    {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // No winner
    return 0;
}

// Main game loop
int main()
{
    // Define the game size
    int size = 3;

    // Allocate memory for the game board
    int **board = NULL;

    // Initialize the game board
    game_board(board, size);

    // Play the game until a winner is found or there is a draw
    int player = 1;
    while (!has_won(board, size, player) && board[size - 1][size - 1] != 2)
    {
        // Get the player's move
        player_move(board, size, player);

        // Switch to the next player
        player = (player == 1) ? 2 : 1;
    }

    // Print the winner or draw message
    if (has_won(board, size, player))
    {
        printf("Congratulations! Player %d has won!\n", player);
    }
    else
    {
        printf("It's a draw!\n");
    }

    // Free the memory allocated for the game board
    free(board);

    return 0;
}