//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define CELL_SIZE 10
#define BOARD_WIDTH (CELL_SIZE * 10)
#define BOARD_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
} cell_t;

typedef struct board {
    cell_t cells[BOARD_WIDTH][BOARD_HEIGHT];
} board_t;

void init_board(board_t *board) {
    int i, j;
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            board->cells[i][j].alive = rand() % 2;
        }
    }
}

void update_board(board_t *board) {
    int i, j, next_alive = 0;
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->cells[i][j].alive) {
                next_alive++;
            }
        }
    }
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
            if (board->cells[i][j].alive && next_alive > 0) {
                next_alive--;
                board->cells[i][j].alive = 1 - board->cells[i][j].alive;
            }
        }
    }
}

void draw_board(board_t *board) {
    int i, j;
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++) {
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
    for (int i = 0; i < 10; i++) {
        update_board(board);
        draw_board(board);
        usleep(100000); // 100ms
    }
    free(board);
    return 0;
}