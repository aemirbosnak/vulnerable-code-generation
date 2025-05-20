//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: invasive
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

    int player = 1;
    int move_count = 0;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the game is over
    while (!game_over)
    {
        // Get the player's move
        int move = rand() % 9;

        // If the move is valid, make it
        if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0)
        {
            board[move / BOARD_SIZE][move % BOARD_SIZE] = player;
            move_count++;
        }

        // Check if the player has won
        if (check_win(board, player) || move_count == 9)
        {
            game_over = 1;
        }

        // Switch to the next player
        player *= -1;
    }

    // Print the winner or draw
    if (game_over)
    {
        printf("Winner: %d\n", player);
    }
    else
    {
        printf("Draw!\n");
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
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

    // No winner, so return 0
    return 0;
}