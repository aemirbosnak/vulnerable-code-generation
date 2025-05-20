//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
} Board;

Board *init_board() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(BOARD_SIZE * sizeof(int));
    }
    board->turn = 0;
    return board;
}

void place_mark(Board *board, int x, int y) {
    board->board[x][y] = board->turn;
}

int check_win(Board *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 0;
}

int main() {
    Board *board = init_board();

    // Play the game
    place_mark(board, 1, 1);
    place_mark(board, 2, 2);
    place_mark(board, 0, 0);
    place_mark(board, 1, 0);

    int winner = check_win(board);

    // Print the winner or draw
    if (winner != 0) {
        printf("The winner is player %d.\n", winner);
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}