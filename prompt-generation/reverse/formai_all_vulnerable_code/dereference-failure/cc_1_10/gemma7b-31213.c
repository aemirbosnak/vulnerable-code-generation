//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};

    int player_turn = 1;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the game is over
    while (!game_over)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[move_x][move_y] == 0)
        {
            // Make the move
            board[move_x][move_y] = player_turn;

            // Check if the player has won
            if (check_win(board, player_turn))
            {
                game_over = 1;
            }
            else
            {
                // Switch turns
                player_turn *= -1;
            }
        }
    }

    // Print the winner
    if (game_over)
    {
        printf("The winner is: ");
        if (player_turn == 1)
        {
            printf("Player 1\n");
        }
        else
        {
            printf("Player 2\n");
        }
    }
    else
    {
        printf("It's a draw\n");
    }

    return 0;
}

int check_win(int **board, int player_turn)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == player_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player_turn)
    {
        return 1;
    }

    // No winner
    return 0;
}