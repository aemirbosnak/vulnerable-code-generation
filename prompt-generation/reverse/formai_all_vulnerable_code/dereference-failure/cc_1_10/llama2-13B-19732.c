//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct cell {
    int alive;
    int next_alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int size;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;

    grid->grid = (cell_t**) malloc(GRID_SIZE * sizeof(cell_t*));
    for (i = 0; i < GRID_SIZE; i++) {
        grid->grid[i] = (cell_t*) malloc(CELL_HEIGHT * sizeof(cell_t));
        for (j = 0; j < CELL_HEIGHT; j++) {
            grid->grid[i][j].alive = (i % 2 == 0 && j % 2 == 0) ||
                                     (i % 2 == 1 && j % 2 == 1);
            grid->grid[i][j].next_alive = grid->grid[i][j].alive;
        }
    }
    grid->size = GRID_SIZE;
}

void update_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            if (grid->grid[i][j].next_alive != grid->grid[i][j].alive) {
                if (grid->grid[i][j].next_alive) {
                    grid->grid[i][j].alive = 1;
                } else {
                    grid->grid[i][j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_HEIGHT; j++) {
            if (grid->grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    grid_t grid;

    init_grid(&grid);

    for (int i = 0; i < 100; i++) {
        update_grid(&grid);
        draw_grid(&grid);
    }

    return 0;
}