//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int game_status;
} Board;

Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));
    board->current_player = 1;
    board->game_status = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }

    return board;
}

void play_game(Board *board) {
    int move_x, move_y;

    printf("Enter your move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    if (board->board[move_x][move_y] != 0) {
        printf("Invalid move.\n");
        return;
    }

    board->board[move_x][move_y] = board->current_player;

    board->current_player = (board->current_player == 1) ? 2 : 1;
}

void check_game_status(Board *board) {
    // Check if the current player has won
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] == board->current_player) {
            board->game_status = 1;
            return;
        }
    }

    // Check if the current player has drawn
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return;
            }
        }
    }

    // Game is a draw
    board->game_status = 2;
}

int main() {
    Board *board = init_board();

    while (!board->game_status) {
        play_game(board);
        check_game_status(board);
    }

    printf("Game over!\n");

    free(board->board);
    free(board);

    return 0;
}