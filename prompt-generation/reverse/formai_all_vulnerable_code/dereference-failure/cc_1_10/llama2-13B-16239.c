//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE (CELL_SIZE * CELL_SIZE)

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

typedef struct board {
    cell_t cells[BOARD_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i * CELL_SIZE + j].alive = (i * j) % 2;
            board->cells[i * CELL_SIZE + j].neighbors_alive = 0;
        }
    }
}

void update_board(board_t *board) {
    int i, j, alive_neighbors;

    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            alive_neighbors = 0;

            if (i - 1 >= 0 && board->cells[i - 1 * CELL_SIZE + j].alive) {
                alive_neighbors++;
            }
            if (i + 1 < BOARD_SIZE && board->cells[i + 1 * CELL_SIZE + j].alive) {
                alive_neighbors++;
            }
            if (j - 1 >= 0 && board->cells[i * CELL_SIZE + j - 1].alive) {
                alive_neighbors++;
            }
            if (j + 1 < BOARD_SIZE && board->cells[i * CELL_SIZE + j + 1].alive) {
                alive_neighbors++;
            }

            board->cells[i * CELL_SIZE + j].neighbors_alive = alive_neighbors;

            if (board->cells[i * CELL_SIZE + j].alive && alive_neighbors < 2) {
                board->cells[i * CELL_SIZE + j].alive = 0;
            } else if (!board->cells[i * CELL_SIZE + j].alive && alive_neighbors >= 2) {
                board->cells[i * CELL_SIZE + j].alive = 1;
            }
        }
    }
}

void print_board(board_t *board) {
    int i, j;

    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i * CELL_SIZE + j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    board_t *board = calloc(1, sizeof(board_t));
    init_board(board);

    for (int i = 0; i < 100; i++) {
        update_board(board);
        print_board(board);
    }

    return 0;
}