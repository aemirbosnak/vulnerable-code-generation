//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    int current_player = PLAYER_X;

    // Game loop
    while (!has_won(board, current_player) && !is_board_full(board))
    {
        // Get the player's move
        int move_x = get_move_x();
        int move_y = get_move_y();

        // Place the move
        board[move_x][move_y] = current_player;

        // Switch the player
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    // Check if the game has been won or if the board is full
    if (has_won(board, current_player))
    {
        printf("Congratulations, %d, you won!\n", current_player);
    }
    else if (is_board_full(board))
    {
        printf("It's a draw!\n");
    }
    else
    {
        printf("Error: invalid move.\n");
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
            if (board[r][c] == 0)
            {
                return 0;
            }
        }
    }

    // The board is full
    return 1;
}

int get_move_x()
{
    // Get the player's move
    int move_x = -1;

    // Repeat until the move is valid
    while (move_x < 0 || move_x >= BOARD_SIZE)
    {
        printf("Enter the move x: ");
        scanf("%d", &move_x);
    }

    return move_x;
}

int get_move_y()
{
    // Get the player's move
    int move_y = -1;

    // Repeat until the move is valid
    while (move_y < 0 || move_y >= BOARD_SIZE)
    {
        printf("Enter the move y: ");
        scanf("%d", &move_y);
    }

    return move_y;
}