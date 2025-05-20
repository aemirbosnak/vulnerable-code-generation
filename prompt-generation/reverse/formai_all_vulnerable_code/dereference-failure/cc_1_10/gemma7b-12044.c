//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    // Initialize the game board
    int board[BOARD_SIZE][BOARD_SIZE] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };

    // Seed the random number generator
    srand(time(NULL));

    // Determine the player who goes first
    int player_turn = rand() % 2 + 1;

    // Play the game
    while (!game_over(board))
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Place the player's mark on the board
        board[move_x][move_y] = player_turn;

        // Switch turns
        player_turn = (player_turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
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

    // Print the winner or draw
    if (board[0][0] == player_turn)
    {
        printf("Player %d won!", player_turn);
    }
    else if (board[BOARD_SIZE - 1][BOARD_SIZE - 1] == 0)
    {
        printf("It's a draw!");
    }
    else
    {
        printf("An error occurred.");
    }

    return 0;
}

int game_over(int **board)
{
    // Check if the player has won
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
        {
            return 1;
        }
    }

    // Check if the player has won vertically
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != 0)
        {
            return 1;
        }
    }

    // Check if the player has won diagonally
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
    {
        return 1;
    }

    // If there are no winners, the game is a draw
    return 0;
}