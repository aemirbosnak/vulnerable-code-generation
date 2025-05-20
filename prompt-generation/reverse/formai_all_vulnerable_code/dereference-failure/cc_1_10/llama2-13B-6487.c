//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct board {
    cell_t **board;
    int size;
} board_t;

void init_board(board_t *board) {
    int i, j;

    board->board = calloc(BOARD_SIZE, sizeof(cell_t*));
    for (i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (j = 0; j < CELL_SIZE; j++) {
            board->board[i][j].alive = (rand() % 2) == 0;
        }
    }
    board->size = BOARD_SIZE * CELL_SIZE;
}

void print_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->board[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_board(board_t *board) {
    int i, j, alive_neighbors = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            int neighbors = 0;
            if (i - 1 >= 0 && board->board[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < BOARD_SIZE && board->board[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && board->board[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < CELL_SIZE && board->board[i][j + 1].alive) {
                neighbors++;
            }

            board->board[i][j].alive = (neighbors >= 2 && board->board[i][j].alive) ||
                                        (neighbors == 0 && rand() % 2 == 0);
            alive_neighbors += neighbors;
        }
    }
}

int main() {
    srand(time(NULL));

    board_t *board = calloc(1, sizeof(board_t));
    init_board(board);

    for (int i = 0; i < 100; i++) {
        update_board(board);
        print_board(board);
        printf("Generation %d\n", i);
    }

    return 0;
}