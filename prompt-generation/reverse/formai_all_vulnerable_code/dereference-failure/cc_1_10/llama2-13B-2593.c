//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

typedef struct board {
    cell_t cells[BOARD_SIZE][CELL_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i][j].alive = (i % 2 == 0) ? 1 : 0;
            board->cells[i][j].neighbors_alive = 0;
        }
    }
}

void update_cell(board_t *board, int i, int j) {
    cell_t *cell = &board->cells[i][j];

    if (cell->alive) {
        int alive_neighbors = 0;

        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if (k == 0 || l == 0 || i + k < 0 || i + k >= BOARD_SIZE ||
                        j + l < 0 || j + l >= CELL_SIZE) {
                    continue;
                }

                if (board->cells[i + k][j + l].alive) {
                    alive_neighbors++;
                }
            }
        }

        cell->neighbors_alive = alive_neighbors;
    }
}

void draw_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    board_t *board = calloc(1, sizeof(board_t));
    init_board(board);

    for (int i = 0; i < 100; i++) {
        update_cell(board, rand() % BOARD_SIZE, rand() % CELL_SIZE);
        draw_board(board);
        sleep(1);
    }

    return 0;
}