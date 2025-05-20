//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100
#define GENERATIONS 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct board {
    cell_t cells[BOARD_SIZE][CELL_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i][j].alive = rand() % 2;
        }
    }
}

void update_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i][j].alive) {
                if (((i + j) % 2) == 0) {
                    board->cells[i][j].alive = 0;
                } else {
                    board->cells[i][j].alive = 1;
                }
            }
        }
    }
}

void draw_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i][j].alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    board_t *board = malloc(sizeof(board_t));
    init_board(board);

    for (int generation = 0; generation < GENERATIONS; generation++) {
        update_board(board);
        draw_board(board);
        printf("Generation %d\n", generation);
    }

    free(board);
    return 0;
}