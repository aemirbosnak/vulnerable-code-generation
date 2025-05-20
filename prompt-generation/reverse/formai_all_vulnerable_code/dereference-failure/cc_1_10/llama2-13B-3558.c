//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_WIDTH (CELL_SIZE * 10)
#define BOARD_HEIGHT (CELL_SIZE * 20)

typedef struct {
    int alive;
    int born;
} cell_t;

typedef struct {
    cell_t cells[BOARD_WIDTH][BOARD_HEIGHT];
} board_t;

void init_board(board_t *board);
void update_board(board_t *board);
void draw_board(board_t *board);

int main() {
    srand(time(NULL));

    board_t *board = calloc(1, sizeof(board_t));
    init_board(board);

    for (int i = 0; i < 100; i++) {
        update_board(board);
        draw_board(board);
    }

    return 0;
}

void init_board(board_t *board) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            cell_t *cell = &board->cells[i][j];
            cell->alive = (i % 2 == 0 && j % 2 == 0) ? 1 : 0;
            cell->born = 0;
        }
    }
}

void update_board(board_t *board) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            cell_t *cell = &board->cells[i][j];
            if (cell->alive && (i == BOARD_WIDTH / 2 - 1 || i == BOARD_WIDTH / 2 + 1
                    || j == BOARD_HEIGHT / 2 - 1 || j == BOARD_HEIGHT / 2 + 1)) {
                cell->born = 1;
            }
            if (cell->born && (rand() % 2 == 0)) {
                cell->alive = 1 - cell->alive;
            }
        }
    }
}

void draw_board(board_t *board) {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            cell_t *cell = &board->cells[i][j];
            if (cell->alive) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}