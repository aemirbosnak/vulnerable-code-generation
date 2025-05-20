//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE (CELL_SIZE * CELL_SIZE)
#define GENERATIONS 100

typedef struct cell {
    int alive;
    int born;
} cell_t;

typedef struct board {
    cell_t cells[BOARD_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i * CELL_SIZE + j].alive = (i + j) % 2;
            board->cells[i * CELL_SIZE + j].born = 0;
        }
    }
}

void update_board(board_t *board) {
    int i, j;

    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i * CELL_SIZE + j].alive) {
                if (board->cells[i * CELL_SIZE + j].born + 1 >= CELL_SIZE) {
                    board->cells[i * CELL_SIZE + j].alive = 0;
                } else {
                    board->cells[i * CELL_SIZE + j].born++;
                }
            }
        }
    }
}

void print_board(board_t *board) {
    int i, j;

    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i * CELL_SIZE + j].alive) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    board_t *board = malloc(sizeof(board_t));
    init_board(board);

    for (int i = 0; i < GENERATIONS; i++) {
        update_board(board);
        print_board(board);
        printf("Generation %d\n", i + 1);
    }

    return 0;
}