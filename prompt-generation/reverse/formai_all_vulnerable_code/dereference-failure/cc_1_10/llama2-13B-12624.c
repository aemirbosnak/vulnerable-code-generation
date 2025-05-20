//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_WIDTH (CELL_SIZE * 10)
#define BOARD_HEIGHT (CELL_SIZE * 20)

typedef struct {
    int alive;
    int next_alive;
} cell_t;

typedef struct {
    cell_t cells[BOARD_WIDTH][BOARD_HEIGHT];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            board->cells[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
            board->cells[i][j].next_alive = board->cells[i][j].alive;
        }
    }
}

void update_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->cells[i][j].next_alive != board->cells[i][j].alive) {
                board->cells[i][j].next_alive = (board->cells[i][j].next_alive + board->cells[i][j].alive) % 2;
            }
        }
    }
}

void draw_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->cells[i][j].alive) {
                printf("O");
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
        draw_board(board);
        printf("Generation %d\n", i);
    }

    free(board);

    return 0;
}