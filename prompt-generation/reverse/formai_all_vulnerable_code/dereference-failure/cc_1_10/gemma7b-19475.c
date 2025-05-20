//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int winner;
} Board;

Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
    }
    board->current_player = 1;
    board->winner = 0;
    return board;
}

void place_mark(Board *board, int row, int col) {
    if (board->board[row][col] != 0) {
        return;
    }
    board->board[row][col] = board->current_player;
    board->current_player *= -1;
}

int check_winner(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i] * 2;
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0] * 2;
        }
    }

    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0] * 2;
    }

    return 0;
}

int main() {
    Board *board = init_board();
    place_mark(board, 1, 1);
    place_mark(board, 0, 0);
    place_mark(board, 2, 2);
    place_mark(board, 1, 0);
    place_mark(board, 0, 1);
    place_mark(board, 2, 0);

    int winner = check_winner(board);

    if (winner == 0) {
        printf("It's a draw!");
    } else {
        printf("The winner is player %d!", winner);
    }

    return 0;
}