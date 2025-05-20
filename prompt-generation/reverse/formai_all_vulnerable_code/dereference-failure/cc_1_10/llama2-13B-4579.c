//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            grid->cells[i * CELL_HEIGHT + j].alive = (i % 2 == 0) && (j % 2 == 0);
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            if (grid->cells[i * CELL_HEIGHT + j].alive) {
                if (((i + j) % 2 == 0) && (i % 2 == 0) && (j % 2 == 0)) {
                    // alive cell has 2 or 3 alive neighbors, leave it alive
                    grid->cells[i * CELL_HEIGHT + j].alive = 1;
                } else {
                    // alive cell has less than 2 alive neighbors, die
                    grid->cells[i * CELL_HEIGHT + j].alive = 0;
                }
            } else {
                // dead cell has 3 alive neighbors, come to life
                if (((i + j) % 2 == 0) && (i % 2 == 0) && (j % 2 == 0)) {
                    grid->cells[i * CELL_HEIGHT + j].alive = 1;
                }
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_WIDTH; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            if (grid->cells[i * CELL_HEIGHT + j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
    }

    free(grid);
    return 0;
}