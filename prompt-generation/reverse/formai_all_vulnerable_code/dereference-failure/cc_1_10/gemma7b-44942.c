//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define the Tic Tac Toe board
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // Initialize the player's move
    int player_move = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the game is over
    while (1)
    {
        // Get the computer's move
        int computer_move = rand() % 9;

        // If the move is valid, make it
        if (board[computer_move / 3][computer_move % 3] == ' ')
        {
            board[computer_move / 3][computer_move % 3] = 'O';
            player_move++;
        }

        // Check if the player has won
        if (check_win(board, player_move) == 1)
        {
            printf("You have won!\n");
            break;
        }

        // Check if the board is full
        if (player_move == 9)
        {
            printf("It's a draw.\n");
            break;
        }
    }

    return 0;
}

int check_win(char **board, int player_move)
{
    // Check if the player has won in a row
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player_move)
        {
            return 1;
        }
    }

    // Check if the player has won in a column
    for (int j = 0; j < 3; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player_move)
        {
            return 1;
        }
    }

    // Check if the player has won in a diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player_move)
    {
        return 1;
    }

    // If the player has not won and the board is full, it's a draw
    return 0;
}