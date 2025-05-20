//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CELL_SIZE 10
#define BOARD_WIDTH (CELL_SIZE * 10)
#define BOARD_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
} cell_t;

typedef struct board {
    cell_t **board;
} board_t;

void initialize_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        board->board[i] = (cell_t *) malloc(BOARD_HEIGHT * sizeof(cell_t));

        for (j = 0; j < BOARD_HEIGHT; j++) {
            board->board[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void print_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->board[i][j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void apply_rules(board_t *board) {
    int i, j, k;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            for (k = 0; k < CELL_SIZE; k++) {
                if (board->board[i][j].alive) {
                    if (k < CELL_SIZE - 1) {
                        if (board->board[i][j + k].alive &&
                            board->board[i][j + k + 1].alive) {
                            board->board[i][j].alive = 1 - board->board[i][j].alive;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    board_t *board = (board_t *) malloc(sizeof(board_t));

    initialize_board(board);

    for (int generation = 0; generation < 10; generation++) {
        apply_rules(board);
        print_board(board);
    }

    free(board);

    return 0;
}