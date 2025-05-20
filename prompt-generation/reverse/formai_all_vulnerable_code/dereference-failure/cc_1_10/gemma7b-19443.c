//Gemma-7B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 1}
    };

    int player_1_turn = 1;
    int game_over = 0;

    while (!game_over)
    {
        // Get the player's move
        int move_x;
        int move_y;

        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Check if the move is valid
        if (board[move_x][move_y] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        board[move_x][move_y] = player_1_turn;

        // Check if the player has won
        if (check_win(board, player_1_turn))
        {
            game_over = 1;
            printf("Congratulations, player 1, you have won!\n");
        }

        // Switch turns
        player_1_turn = 2 - player_1_turn;
    }

    return 0;
}

int check_win(int **board, int player_1_turn)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        if (board[0][i] == player_1_turn && board[1][i] == player_1_turn && board[2][i] == player_1_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 6; j++)
    {
        if (board[j][0] == player_1_turn && board[j][1] == player_1_turn && board[j][2] == player_1_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player_1_turn && board[1][1] == player_1_turn && board[2][2] == player_1_turn)
    {
        return 1;
    }

    // Check anti-diagonals
    if (board[0][5] == player_1_turn && board[1][4] == player_1_turn && board[2][3] == player_1_turn)
    {
        return 1;
    }

    // If all checks fail, the game is not over
    return 0;
}