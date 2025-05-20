//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BOARD_SIZE 3

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0}};

    int player_turn = 1;
    int game_status = 0;

    // Game loop
    while (game_status == 0) {
        // Get the player's move
        int move_row, move_col;
        printf("Enter row: ");
        scanf("%d", &move_row);
        printf("Enter column: ");
        scanf("%d", &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= BOARD_SIZE || move_col < 0 || move_col >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the move is valid
        if (board[move_row][move_col] != 0) {
            printf("Move not valid.\n");
            continue;
        }

        // Make the move
        board[move_row][move_col] = player_turn;

        // Check if the player has won
        game_status = check_win(board, player_turn);

        // Switch turns
        player_turn *= -1;
    }

    // Game over
    printf("Game over!\n");

    return 0;
}

int check_win(int **board, int player_turn) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (board[row][0] == player_turn && board[row][1] == player_turn && board[row][2] == player_turn) {
            return 1;
        }
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (board[0][col] == player_turn && board[1][col] == player_turn && board[2][col] == player_turn) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player_turn && board[1][1] == player_turn && board[2][2] == player_turn) {
        return 1;
    }

    // No winner
    return 0;
}