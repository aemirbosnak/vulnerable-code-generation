//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3
#define EMPTY_SPOT 0
#define PLAYER_X 1
#define PLAYER_O 2

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = { { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT },
                                 { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT },
                                 { EMPTY_SPOT, EMPTY_SPOT, EMPTY_SPOT } };

    int player = PLAYER_X;
    int game_over = 0;

    // Game loop
    while (!game_over) {
        // Get the player's move
        int move_x, move_y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate the move
        if (move_x < 0 || move_x >= BOARD_SIZE || move_y < 0 || move_y >= BOARD_SIZE) {
            printf("Invalid move.\n");
            continue;
        }

        // Check if the spot is empty
        if (board[move_x][move_y] != EMPTY_SPOT) {
            printf("That spot is already taken.\n");
            continue;
        }

        // Make the move
        board[move_x][move_y] = player;

        // Check if the player has won
        if (check_win(board, player)) {
            game_over = 1;
            printf("You have won!\n");
        }

        // If the board is full and there has not been a winner, it's a draw
        else if (board_is_full(board)) {
            game_over = 1;
            printf("It's a draw.\n");
        }

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}

int check_win(int **board, int player) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0] == player && board[r][1] == player && board[r][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c] == player && board[1][c] == player && board[2][c] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }

    // If none of the above conditions are met, return 0
    return 0;
}

int board_is_full(int **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c] == EMPTY_SPOT) {
                return 0;
            }
        }
    }

    // If all spots are filled, return 1
    return 1;
}