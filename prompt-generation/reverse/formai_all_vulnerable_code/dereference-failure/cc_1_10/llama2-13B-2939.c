//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE (CELL_SIZE * CELL_SIZE)

typedef struct {
    int x;
    int y;
} coord_t;

typedef struct {
    coord_t position;
    int alive;
} cell_t;

cell_t** board;

void init_board(void) {
    board = calloc(CELL_SIZE, sizeof(cell_t*));
    for (int i = 0; i < CELL_SIZE; i++) {
        board[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            board[i][j].position.x = i * CELL_SIZE;
            board[i][j].position.y = j * CELL_SIZE;
            board[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void update_board(void) {
    for (int i = 0; i < CELL_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < CELL_SIZE && y >= 0 && y < CELL_SIZE) {
                        if (board[x][y].alive) {
                            alive_neighbors++;
                        }
                    }
                }
            }
            board[i][j].alive = (alive_neighbors >= 2) && (board[i][j].alive);
        }
    }
}

void draw_board(void) {
    for (int i = 0; i < CELL_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (board[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    init_board();
    for (int i = 0; i < 1000; i++) {
        update_board();
        draw_board();
    }
    return 0;
}