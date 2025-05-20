//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 0}};

    int player = 1;
    int game_status = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play the game until someone wins or it's a draw
    while (!game_status)
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid, make the move
        if (board[move_x][move_y] == 0)
        {
            board[move_x][move_y] = player;
            player = (player == 1) ? 2 : 1;
        }

        // Check if the player has won
        game_status = check_win(board, player);

        // If there is no winner, check if the board is full
        if (!game_status && board[0][0] == board[BOARD_SIZE - 1][BOARD_SIZE - 1])
        {
            game_status = 2;
        }
    }

    // Print the winner or draw message
    switch (game_status)
    {
        case 1:
            printf("Player %d won!", player);
            break;
        case 2:
            printf("It's a draw!");
            break;
    }

    return 0;
}

int check_win(int **board, int player)
{
    // Check the rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == player)
        {
            return 1;
        }
    }

    // Check the columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] == player)
        {
            return 1;
        }
    }

    // Check the diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // If there has not been a winner, return 0
    return 0;
}