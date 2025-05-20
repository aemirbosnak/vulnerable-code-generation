//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    int player = PLAYER_X;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play the game until one player wins or it's a draw
    while (!game_over)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[move_x][move_y] == 0)
        {
            // Make the move
            board[move_x][move_y] = player;

            // Check if the player has won
            if (check_win(board, player))
            {
                game_over = 1;
            }

            // If the player has not won, switch to the next player
            player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    // Print the game board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }

        printf("\n");
    }

    // Print the winner or draw message
    if (game_over)
    {
        printf("The winner is: %d\n", player);
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check the rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check the columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
        {
            return 1;
        }
    }

    // Check the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // If there has not been a win, return 0
    return 0;
}