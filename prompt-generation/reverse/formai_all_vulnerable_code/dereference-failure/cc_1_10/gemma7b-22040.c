//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[3][3] = {{0, 0, 0},
                           {0, 0, 0},
                           {0, 0, 0}};

    int player = 1;
    int game_over = 0;
    int move_made = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (!game_over)
    {
        // Get the player's move
        int move = rand() % 9;

        // Check if the move is valid
        if (board[move / 3][move % 3] == 0)
        {
            // Make the move
            board[move / 3][move % 3] = player;

            // Check if the player has won
            if (check_win(board, player))
            {
                game_over = 1;
            }
            else
            {
                // Next player's turn
                player = (player == 1) ? 2 : 1;
            }
        }
    }

    // Game over message
    printf("Game over!");

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // No win
    return 0;
}