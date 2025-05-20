//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int next_alive;
} cell_t;

cell_t *grid;

void init_grid(void) {
    grid = calloc(GRID_SIZE, sizeof(cell_t));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i].alive = (i % 2) == 0;
        grid[i].next_alive = grid[i].alive;
    }
}

void update_grid(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i].next_alive != grid[i].alive) {
            if (grid[i].next_alive) {
                // alive cell becomes two alive cells
                grid[i].alive = 1;
                grid[i + 1].alive = 1;
                grid[i - 1].alive = 1;
            } else {
                // dead cell becomes one alive cell
                grid[i].alive = 1;
            }
        }
    }
}

void draw_grid(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i].alive) {
            printf("O");
        } else {
            printf(".");
        }
    }
    printf("\n");
}

int main(void) {
    init_grid();
    for (int i = 0; i < 100; i++) {
        update_grid();
        draw_grid();
    }
    return 0;
}