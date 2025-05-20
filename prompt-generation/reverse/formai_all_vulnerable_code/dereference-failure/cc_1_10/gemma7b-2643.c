//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **cells;
    int size;
} Board;

void init_board(Board *board) {
    board->cells = malloc(board->size * sizeof(int *));
    for (int i = 0; i < board->size; i++) {
        board->cells[i] = malloc(board->size * sizeof(int));
    }

    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            board->cells[i][j] = 0;
        }
    }
}

void place_piece(Board *board, int x, int y, int player) {
    if (board->cells[x][y] != 0) {
        return;
    }

    board->cells[x][y] = player;
}

int check_win(Board *board, int player) {
    // Check rows
    for (int i = 0; i < board->size; i++) {
        if (board->cells[0][i] == player && board->cells[1][i] == player && board->cells[2][i] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < board->size; j++) {
        if (board->cells[j][0] == player && board->cells[j][1] == player && board->cells[j][2] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board->cells[0][0] == player && board->cells[1][1] == player && board->cells[2][2] == player) {
        return 1;
    }

    if (board->cells[0][2] == player && board->cells[1][1] == player && board->cells[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    Board board;
    init_board(&board);

    int player = 1;
    int game_over = 0;

    // Game loop
    while (!game_over) {
        // Get player's move
        int x = rand() % board.size;
        int y = rand() % board.size;

        // Place piece
        place_piece(&board, x, y, player);

        // Check if player won
        if (check_win(&board, player) == 1) {
            game_over = 1;
            printf("Player %d won!", player);
        }

        // Next player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}