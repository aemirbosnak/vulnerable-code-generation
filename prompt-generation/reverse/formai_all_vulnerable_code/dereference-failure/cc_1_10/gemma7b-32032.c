//Gemma-7B DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(int **board, int player)
{
    int row, col, move_made = 0;

    // Get the player's move
    printf("Enter row and column (e.g. 2 3): ");
    scanf("%d %d", &row, &col);

    // Validate the move
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
    {
        printf("Invalid move. Please try again.\n");
        return;
    }

    // Make the move
    board[row][col] = player;

    // Check if the player has won
    if (check_win(board, player) == 1)
    {
        printf("Congratulations! You have won!\n");
    }
    else
    {
        move_made = 1;
    }

    return;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int r = 0; r < 3; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 3; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // If no win, return 0
    return 0;
}

int main()
{
    int **board = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
    {
        board[i] = malloc(sizeof(int) * 3);
    }

    int player = 1;
    int game_over = 0;

    // Initialize the board
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game until someone wins or there is a draw
    while (!game_over)
    {
        play_game(board, player);

        // Switch players
        player *= -1;
    }

    // Free the memory
    for (int i = 0; i < 3; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}