//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2
#define EMPTY_SPACE 0

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

    int player = PLAYER_X;
    int game_status = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (!game_status)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[move_x][move_y] == EMPTY_SPACE)
        {
            // Make the move
            board[move_x][move_y] = player;

            // Check if the player has won
            game_status = check_win(board, player);

            // If the player has not won, switch to the next player
            if (!game_status)
            {
                player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
            }
        }
    }

    // Print the winner or draw
    if (game_status == PLAYER_X)
    {
        printf("Player X has won!");
    }
    else if (game_status == PLAYER_O)
    {
        printf("Player O has won!");
    }
    else
    {
        printf("It's a draw!");
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player)
        {
            return player;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player)
        {
            return player;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return player;
    }

    // If all rows, columns, and diagonals have been checked and there has not been a winner, the game is a draw
    return 0;
}