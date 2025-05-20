//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100
#define GENERATIONS 100

typedef struct cell {
    int alive;
    int born;
} cell_t;

typedef struct board {
    cell_t cells[BOARD_SIZE][CELL_SIZE];
} board_t;

void init_board(board_t *board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            board->cells[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
            board->cells[i][j].born = 0;
        }
    }
}

void update_board(board_t *board) {
    int i, j, alive_neighbors = 0;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board->cells[i][j].alive) {
                alive_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) {
                            continue;
                        }
                        if (board->cells[i + k][j + l].alive) {
                            alive_neighbors++;
                        }
                    }
                }
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    board->cells[i][j].alive = 0;
                } else if (alive_neighbors == 3) {
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
                printf("O ");
            } else {
                printf(" . ");
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
        draw_board(board);
        printf("Generation %d\n", i + 1);
        sleep(1);
    }

    free(board);

    return 0;
}