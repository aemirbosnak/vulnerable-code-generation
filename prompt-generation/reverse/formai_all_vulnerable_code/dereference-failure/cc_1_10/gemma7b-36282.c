//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int current_player;
    int game_over;
} Board;

Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
    }
    board->current_player = 1;
    board->game_over = 0;
    return board;
}

void place_piece(Board *board, int x, int y) {
    if (board->board[x][y] == 0 && board->game_over == 0) {
        board->board[x][y] = board->current_player;
        board->current_player *= -1;
    }
}

int check_win(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i] * 2;
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[i][0] == board->board[i][1] && board->board[i][0] == board->board[i][2] && board->board[i][0] != 0) {
            return board->board[i][0] * 2;
        }
    }
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0] * 2;
    }
    return 0;
}

int main() {
    Board *board = init_board();
    place_piece(board, 1, 1);
    place_piece(board, 2, 0);
    place_piece(board, 0, 2);
    place_piece(board, 1, 0);
    place_piece(board, 2, 1);

    int winner = check_win(board);

    if (winner) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("It's a draw\n");
    }

    return 0;
}