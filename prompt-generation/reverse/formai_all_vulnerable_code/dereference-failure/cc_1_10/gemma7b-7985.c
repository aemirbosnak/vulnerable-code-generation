//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE 0
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create the game board
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                               {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE},
                               {EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE}};

    // Determine the player who starts
    int player_turn = rand() % 2 + 1;

    // Play the game
    while (!has_won(board, player_turn) && !is_board_full(board))
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Place the player's mark on the board
        board[move_x][move_y] = player_turn;

        // Switch turns
        player_turn = (player_turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the player has won or if the board is full
    if (has_won(board, player_turn) || is_board_full(board))
    {
        // Print the winner
        printf("Winner: Player %d\n", player_turn);
    }
    else
    {
        // Print a draw
        printf("Draw\n");
    }

    return 0;
}

int has_won(int **board, int player)
{
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == player)
    {
        return 1;
    }

    // No winner
    return 0;
}

int is_board_full(int **board)
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            if (board[r][c] == EMPTY_SPACE)
            {
                return 0;
            }
        }
    }

    // The board is full
    return 1;
}