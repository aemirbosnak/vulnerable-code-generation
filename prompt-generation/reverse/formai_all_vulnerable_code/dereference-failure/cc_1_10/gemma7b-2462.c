//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BOARD_SIZE 3

typedef struct Board {
    int **board;
    int size;
    int turn;
} Board;

Board *create_board(int size) {
    Board *board = malloc(sizeof(Board));
    board->size = size;
    board->board = malloc(size * size * sizeof(int));
    board->turn = 0;
    return board;
}

void display_board(Board *board) {
    for (int r = 0; r < board->size; r++) {
        for (int c = 0; c < board->size; c++) {
            printf("%d ", board->board[r][c]);
        }
        printf("\n");
    }
}

int is_board_full(Board *board) {
    for (int r = 0; r < board->size; r++) {
        for (int c = 0; c < board->size; c++) {
            if (board->board[r][c] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Board *board = create_board(MAX_BOARD_SIZE);
    display_board(board);

    // AI moves
    board->board[1][1] = 2;
    board->board[0][0] = 2;
    board->board[2][2] = 2;

    display_board(board);

    if (is_board_full(board) || board->board[board->size - 1][board->size - 1] == board->turn) {
        printf("Draw!");
    } else {
        printf("Player %d wins!", board->turn);
    }

    return 0;
}