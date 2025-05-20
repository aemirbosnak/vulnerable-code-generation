//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int next_move;
} Board;

Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->next_move = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    return board;
}

int make_move(Board *board, int x, int y) {
    if (board->board[x][y] != 0) {
        return -1;
    }
    board->board[x][y] = board->next_move++;
    return 0;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i] * 2;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0] * 2;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0] * 2;
    }

    // If all moves are made and there is no winner, it's a draw
    return 0;
}

int main() {
    Board *board = init_board();
    int player_1_win = 0;
    int player_2_win = 0;

    // Play the game until one player wins or it's a draw
    while (!player_1_win && !player_2_win) {
        // Get the player's move
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;

        // Make the move
        if (make_move(board, x, y) == 0) {
            // Check if the player has won
            if (check_win(board) == board->board[x][y] * 2) {
                player_1_win = 1;
            }
        } else {
            // Move not valid, try again
            continue;
        }
    }

    // Print the winner or draw
    if (player_1_win) {
        printf("Player 1 won!");
    } else if (player_2_win) {
        printf("Player 2 won!");
    } else {
        printf("It's a draw!");
    }

    return 0;
}