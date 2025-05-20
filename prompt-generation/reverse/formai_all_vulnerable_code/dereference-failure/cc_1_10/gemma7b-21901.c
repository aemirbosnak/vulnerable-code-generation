//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{0, 0, 0},
                                 {0, 0, 0},
                                 {0, 0, 0}};

    int player = 1;
    int move_count = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Play until someone wins or it's a draw
    while (1) {
        // Get the player's move
        int move_x = rand() % BOARD_SIZE;
        int move_y = rand() % BOARD_SIZE;

        // If the move is valid and the space is empty, make the move
        if (board[move_x][move_y] == 0) {
            board[move_x][move_y] = player;
            move_count++;
            // Check if the player has won
            if (check_win(board, player) || move_count == BOARD_SIZE * BOARD_SIZE - 1) {
                // The player has won!
                printf("Winner: Player %d!\n", player);
                break;
            }

            // Next player's turn
            player = (player == 1) ? 2 : 1;
        }
    }

    return 0;
}

int check_win(int **board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // No winner, it's a draw
    return 0;
}