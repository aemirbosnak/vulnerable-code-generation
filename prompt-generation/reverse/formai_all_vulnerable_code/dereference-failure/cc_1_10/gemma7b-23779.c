//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE 0
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                                 {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

    int currentPlayer = PLAYER_X;
    int gameWon = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play until someone wins or it's a draw
    while (!gameWon)
    {
        // Get the player's move
        int moveX = rand() % BOARD_SIZE;
        int moveY = rand() % BOARD_SIZE;

        // If the move is valid, make it
        if (board[moveX][moveY] == EMPTY_SPACE)
        {
            board[moveX][moveY] = currentPlayer;

            // Check if the player has won
            gameWon = checkWin(currentPlayer, board);

            // If the player has not won, switch to the next player
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    // Print the winner or draw
    if (gameWon)
    {
        printf("Winner: %d\n", currentPlayer);
    }
    else
    {
        printf("Draw\n");
    }

    return 0;
}

int checkWin(int player, int **board)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // If all checks fail, it's a draw
    return 0;
}