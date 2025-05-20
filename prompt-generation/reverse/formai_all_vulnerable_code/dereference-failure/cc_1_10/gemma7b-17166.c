//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the C Terminal Game!\n");

    // Define the game board
    int board[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};

    // Initialize the player's move
    int move = 0;

    // Game loop
    while (move < 9)
    {
        // Get the player's move
        printf("Enter your move (1-9): ");
        int move_num = atoi(stdin);

        // Validate the move
        if (move_num < 1 || move_num > 9)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place the player's mark on the board
        board[move_num / 3][move_num % 3] = 1;

        // Check if the player has won
        if (check_win(board, move) == 1)
        {
            printf("You have won!");
            break;
        }

        // If there is no winner, move to the next turn
        move++;
    }

    // If the game ends in a draw
    if (move == 9)
    {
        printf("It's a draw!");
    }

    return 0;
}

int check_win(int **board, int move)
{
    // Check rows
    for (int r = 0; r < 3; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == move)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 3; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == move)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == move)
    {
        return 1;
    }

    // If there is no winner, return 0
    return 0;
}