//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    // Initialize the game board
    int board[BOARD_SIZE][BOARD_SIZE] = { { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 } };

    // Seed the random number generator
    srand(time(NULL));

    // Determine the player who goes first
    int player = rand() % 2 + 1;

    // Game loop
    while (!boardFull(board) && !won(board, player))
    {
        // Get the player's move
        int move = getPlayerMove(board, player);

        // Place the player's mark on the board
        board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the game has ended
    if (won(board, player))
    {
        printf("Player %d won!\n", player);
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}

int boardFull(int **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}

int won(int **board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] == board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == board[j][1] == board[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] == board[2][2] == player)
    {
        return 1;
    }
    else if (board[0][2] == board[1][1] == board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

int getPlayerMove(int **board, int player)
{
    // Get a random move
    int move = rand() % 9;

    // If the move is valid, return it
    if (board[move / BOARD_SIZE][move % BOARD_SIZE] == 0)
    {
        return move;
    }

    // Otherwise, try again
    return getPlayerMove(board, player);
}