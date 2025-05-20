//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_WIDTH (CELL_SIZE * 10)
#define BOARD_HEIGHT (CELL_SIZE * 20)

typedef struct cell {
    int alive;
    int birth_probability;
} cell_t;

typedef struct board {
    cell_t** cells;
} board_t;

void init_board(board_t* board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        board->cells[i] = calloc(BOARD_HEIGHT, sizeof(cell_t));

        for (j = 0; j < BOARD_HEIGHT; j++) {
            board->cells[i][j].alive = (rand() % 2) ? 1 : 0;
            board->cells[i][j].birth_probability = (rand() % 10) + 1;
        }
    }
}

void update_board(board_t* board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->cells[i][j].alive) {
                if (rand() % 100 < board->cells[i][j].birth_probability) {
                    board->cells[i][j].alive = 1;
                } else {
                    board->cells[i][j].alive = 0;
                }
            }
        }
    }
}

void print_board(board_t* board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->cells[i][j].alive) {
                printf("O");
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
        print_board(board);
    }

    return 0;
}