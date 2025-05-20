//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};

    int player1_wins = 0;
    int player2_wins = 0;
    int current_player = 1;

    // Game loop
    while (player1_wins == 0 && player2_wins == 0)
    {
        // Get the move
        int move_row = rand() % MAX_SIZE;
        int move_col = rand() % MAX_SIZE;

        // Check if the move is valid
        if (board[move_row][move_col] == 0)
        {
            // Place the piece
            board[move_row][move_col] = current_player;

            // Check if the player has won
            if (check_win(board, current_player))
            {
                current_player = 2;
                player1_wins++;
            }
            else
            {
                // Switch to the next player
                current_player = 2;
            }
        }
    }

    // Print the results
    printf("Player 1 wins: %d\n", player1_wins);
    printf("Player 2 wins: %d\n", player2_wins);

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (board[0][i] == board[1][i] == board[2][i] == board[3][i] == board[4][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < MAX_SIZE; j++)
    {
        if (board[j][0] == board[j][1] == board[j][2] == board[j][3] == board[j][4] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] == board[2][2] == board[3][3] == board[4][4] == player)
    {
        return 1;
    }

    // Check anti-diagonals
    if (board[0][4] == board[1][3] == board[2][2] == board[3][1] == board[4][0] == player)
    {
        return 1;
    }

    return 0;
}