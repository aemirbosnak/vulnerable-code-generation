//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t* g) {
    g->grid = calloc(WINDOW_HEIGHT, sizeof(cell_t*));
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        g->grid[i] = calloc(WINDOW_WIDTH, sizeof(cell_t));
    }
    g->rows = WINDOW_HEIGHT;
    g->cols = WINDOW_WIDTH;
}

void print_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void update_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grid[i][j].neighbors_alive == 2 || g->grid[i][j].neighbors_alive == 3) {
                g->grid[i][j].alive = 1;
            } else if (g->grid[i][j].alive && g->grid[i][j].neighbors_alive == 0) {
                g->grid[i][j].alive = 0;
            }
        }
    }
}

int main() {
    grid_t* g = calloc(1, sizeof(grid_t));
    init_grid(g);
    print_grid(g);
    update_grid(g);
    print_grid(g);
    return 0;
}