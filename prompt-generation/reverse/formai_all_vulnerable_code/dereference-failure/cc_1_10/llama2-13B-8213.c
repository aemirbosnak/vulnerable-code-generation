//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct board {
    cell_t** cells;
} board_t;

void init_board(board_t* board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        board->cells[i] = calloc(CELL_SIZE, sizeof(cell_t));

        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i][j].alive = rand() % 2;
        }
    }
}

void update_board(board_t* board) {
    int i, j, next_alive = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i][j].alive) {
                if (j < CELL_SIZE - 1 && board->cells[i][j + 1].alive) {
                    // Check if the cell is alive and has a living neighbor to the right
                    next_alive |= 1 << (j + 1);
                }
                if (i < BOARD_SIZE - 1 && board->cells[i + 1][j].alive) {
                    // Check if the cell is alive and has a living neighbor above
                    next_alive |= 1 << (i + 1);
                }
            }
        }

        // Update the cell's alive status based on its neighbors
        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i][j].alive = next_alive & (1 << j);
        }

        next_alive = 0;
    }
}

void draw_board(board_t* board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i][j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    board_t* board = calloc(1, sizeof(board_t));
    init_board(board);

    for (int i = 0; i < 100; i++) {
        update_board(board);
        draw_board(board);
        printf("Generation %d\n", i + 1);
    }

    return 0;
}