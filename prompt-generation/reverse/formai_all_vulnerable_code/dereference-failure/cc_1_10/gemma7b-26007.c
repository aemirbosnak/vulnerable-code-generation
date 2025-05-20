//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Initialize the game board
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Player's turn
    int turn = 0;

    // Game loop
    while (!check_win(board, turn) && board[0] != 'O')
    {
        // Get the player's move
        int move = get_move(board);

        // Place the player's mark on the board
        board[move] = 'X';

        // Switch turns
        turn = (turn + 1) % 2;
    }

    // Check if the player won or if the game ended in a draw
    if (check_win(board, turn) == 1)
    {
        printf("You won!");
    }
    else
    {
        printf("It's a draw!");
    }
}

// Function to check if the player has won
int check_win(char *board, int turn)
{
    // Check rows
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == board[i + 1] && board[i] == board[i + 2] && board[i] == board[turn])
        {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] == board[turn])
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0] == board[4] && board[0] == board[8] && board[0] == board[turn])
    {
        return 1;
    }
    else if (board[2] == board[4] && board[2] == board[6] && board[2] == board[turn])
    {
        return 1;
    }

    // If there are no winners, return 0
    return 0;
}

// Function to get the player's move
int get_move(char *board)
{
    int move;

    // Loop until the move is valid
    while (1)
    {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Check if the move is valid
        if (move < 1 || move > 9 || board[move] != ' ')
        {
            printf("Invalid move. Please try again.\n");
        }
        else
        {
            break;
        }
    }

    return move;
}