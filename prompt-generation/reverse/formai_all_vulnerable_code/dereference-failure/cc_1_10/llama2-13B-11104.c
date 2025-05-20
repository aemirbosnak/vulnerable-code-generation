//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 20
#define GENERATIONS 100

typedef struct {
    int alive;
    int neighbors_alive;
} cell_t;

typedef struct {
    cell_t cells[BOARD_SIZE][BOARD_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->cells[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
            board->cells[i][j].neighbors_alive = 0;
        }
    }
}

void update_cell(board_t *board, int i, int j) {
    cell_t *cell = &board->cells[i][j];
    int alive_neighbors = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 || l == 0) {
                continue;
            }
            int x = i + k;
            int y = j + l;
            if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
                if (board->cells[x][y].alive) {
                    alive_neighbors++;
                }
            }
        }
    }
    cell->neighbors_alive = alive_neighbors;
    if (cell->alive && alive_neighbors < 2) {
        cell->alive = 0;
    } else if (!cell->alive && alive_neighbors >= 2) {
        cell->alive = 1;
    }
}

void draw_board(board_t *board) {
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
    board_t *board = calloc(1, sizeof(board_t));
    init_board(board);
    for (int i = 0; i < GENERATIONS; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                update_cell(board, k, j);
            }
        }
        draw_board(board);
        printf("\nGeneration %d\n", i + 1);
    }
    free(board);
    return 0;
}