//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_WIDTH (CELL_SIZE * 10)
#define BOARD_HEIGHT (CELL_SIZE * 20)

typedef struct {
    int alive;
    int neighbors_alive[CELL_SIZE];
} cell_t;

typedef struct {
    cell_t cells[BOARD_WIDTH][BOARD_HEIGHT];
} board_t;

void initialize_board(board_t *board);
void update_board(board_t *board);
void print_board(board_t *board);

int main() {
    srand(time(NULL));

    board_t *board = calloc(1, sizeof(board_t));
    initialize_board(board);

    for (int i = 0; i < 1000; i++) {
        update_board(board);
        print_board(board);
    }

    free(board);
    return 0;
}

void initialize_board(board_t *board) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            cell_t *cell = &board->cells[i][j];
            cell->alive = (rand() % 2) == 0;
            cell->neighbors_alive[0] = (rand() % 2) == 0;
            cell->neighbors_alive[1] = (rand() % 2) == 0;
            cell->neighbors_alive[2] = (rand() % 2) == 0;
            cell->neighbors_alive[3] = (rand() % 2) == 0;
        }
    }
}

void update_board(board_t *board) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            cell_t *cell = &board->cells[i][j];
            int neighbors_alive = 0;

            if (i - 1 >= 0 && board->cells[i - 1][j].alive) {
                neighbors_alive++;
            }

            if (i + 1 < BOARD_WIDTH && board->cells[i + 1][j].alive) {
                neighbors_alive++;
            }

            if (j - 1 >= 0 && board->cells[i][j - 1].alive) {
                neighbors_alive++;
            }

            if (j + 1 < BOARD_HEIGHT && board->cells[i][j + 1].alive) {
                neighbors_alive++;
            }

            if (cell->alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                cell->alive = 1;
            } else if (!cell->alive && neighbors_alive == 3) {
                cell->alive = 1;
            } else {
                cell->alive = 0;
            }
        }
    }
}

void print_board(board_t *board) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            cell_t *cell = &board->cells[i][j];
            if (cell->alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}