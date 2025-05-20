//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPACE ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

int main()
{
    // Allocate memory for the game board
    char **board = (char **)malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
    }

    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_SPACE;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Player's turn
    char player = PLAYER_X;

    // Game loop
    while (!is_winner(board) && !is_board_full(board))
    {
        // Get the player's move
        int move = get_random_move(board);

        // Place the player's mark on the board
        board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the player won or if the board is full
    if (is_winner(board))
    {
        printf("The winner is: %c!\n", player);
    }
    else
    {
        printf("It's a draw!\n");
    }

    // Free the game board memory
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

// Check if the player won
int is_winner(char **board)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != EMPTY_SPACE)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != EMPTY_SPACE)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY_SPACE)
    {
        return 1;
    }

    // No winner
    return 0;
}

// Check if the board is full
int is_board_full(char **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_SPACE)
            {
                return 0;
            }
        }
    }

    // The board is full
    return 1;
}

// Get a random move
int get_random_move(char **board)
{
    // Calculate the number of available moves
    int num_moves = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_SPACE)
            {
                num_moves++;
            }
        }
    }

    // Get a random move
    return rand() % num_moves;
}