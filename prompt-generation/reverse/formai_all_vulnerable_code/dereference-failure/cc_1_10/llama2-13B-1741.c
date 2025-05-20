//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100

typedef struct {
    int alive;
    int neighbors_alive[CELL_SIZE];
} cell_t;

typedef struct {
    cell_t cells[BOARD_SIZE][BOARD_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->cells[i][j].alive = rand() % 2;
            board->cells[i][j].neighbors_alive[0] = (i == 0 || i == BOARD_SIZE - 1) ? 1 : 0;
            board->cells[i][j].neighbors_alive[1] = (j == 0 || j == BOARD_SIZE - 1) ? 1 : 0;
            board->cells[i][j].neighbors_alive[2] = (i > 0 && j > 0) ? board->cells[i - 1][j - 1].alive : 0;
            board->cells[i][j].neighbors_alive[3] = (i < BOARD_SIZE - 1 && j < BOARD_SIZE - 1) ? board->cells[i + 1][j + 1].alive : 0;
        }
    }
}

void update_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int alive_neighbors = 0;

            if (board->cells[i][j].neighbors_alive[0]) {
                alive_neighbors++;
            }
            if (board->cells[i][j].neighbors_alive[1]) {
                alive_neighbors++;
            }
            if (board->cells[i][j].neighbors_alive[2]) {
                alive_neighbors++;
            }
            if (board->cells[i][j].neighbors_alive[3]) {
                alive_neighbors++;
            }

            if (alive_neighbors < 2 || alive_neighbors > 3) {
                board->cells[i][j].alive = 0;
            } else {
                board->cells[i][j].alive = 1;
            }
        }
    }
}

void print_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
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

    for (int i = 0; i < 100; i++) {
        update_board(board);
        print_board(board);
    }

    return 0;
}