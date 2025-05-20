//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT 0
#define PLAYER_X 1
#define PLAYER_O 2

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                                 {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT},
                                 {EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT}};

    int current_player = PLAYER_X;

    // Seed the random number generator
    srand(time(NULL));

    // Play until one of the players wins or it's a draw
    while (!board_is_won(board) && board_has_space(board))
    {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid, make the move
        if (board[move_x][move_y] == EMPTY_SPOT)
        {
            board[move_x][move_y] = current_player;
            current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    // Print the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Print the winner or draw message
    if (board_is_won(board))
    {
        printf("Winner: %c\n", current_player == PLAYER_X ? 'X' : 'O');
    }
    else
    {
        printf("Draw\n");
    }

    return 0;
}

int board_is_won(int **board)
{
    // Check if the player has won horizontally
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != EMPTY_SPOT)
        {
            return 1;
        }
    }

    // Check if the player has won vertically
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == board[j][1] && board[j][0] == board[j][2] && board[j][0] != EMPTY_SPOT)
        {
            return 1;
        }
    }

    // Check if the player has won diagonally
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != EMPTY_SPOT)
    {
        return 1;
    }

    // If there has not been a winner, return 0
    return 0;
}

int board_has_space(int **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_SPOT)
            {
                return 1;
            }
        }
    }

    // If there are no empty spots, return 0
    return 0;
}