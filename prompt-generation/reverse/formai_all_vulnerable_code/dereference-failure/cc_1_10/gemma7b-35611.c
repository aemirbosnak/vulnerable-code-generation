//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 0}};

    int player_turn = 1;
    int game_over = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Game loop
    while (!game_over) {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // Check if the move is valid
        if (board[move_x][move_y] == 0) {
            // Place the player's mark on the board
            board[move_x][move_y] = player_turn;

            // Check if the player has won
            if (check_win(board, player_turn)) {
                game_over = 1;
            }

            // If the player has not won, switch turns
            player_turn = -player_turn;
        } else {
            // Invalid move, try again
            continue;
        }
    }

    // Game over, display the board
    printf("The board is:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Print the winner or draw
    if (game_over) {
        printf("The winner is: ");
        printf("Player %d", player_turn);
    } else {
        printf("It's a draw!");
    }

    return 0;
}

int check_win(int **board, int player_turn) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player_turn && board[1][i] == player_turn && board[2][i] == player_turn) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player_turn && board[j][1] == player_turn && board[j][2] == player_turn) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player_turn && board[1][1] == player_turn && board[2][2] == player_turn) {
        return 1;
    }

    // If all checks fail, the game is not over
    return 0;
}