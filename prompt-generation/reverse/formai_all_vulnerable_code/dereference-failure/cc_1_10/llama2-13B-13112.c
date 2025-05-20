//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

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
    int i, j;
    for (i = 0; i < g->rows; i++) {
        g->grid[i] = (cell_t*)calloc(g->cols, sizeof(cell_t));
        for (j = 0; j < g->cols; j++) {
            g->grid[i][j].alive = rand() % 2;
            g->grid[i][j].neighbors_alive = 0;
        }
    }
}

void update_grid(grid_t* g) {
    int i, j, k;
    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            g->grid[i][j].neighbors_alive = 0;
            for (k = -1; k <= 1; k++) {
                if (k == 0 || j + k >= 0 && j + k < g->cols) {
                    if (g->grid[i][j + k].alive) {
                        g->grid[i][j].neighbors_alive++;
                    }
                }
            }
        }
    }
}

void draw_grid(grid_t* g) {
    int i, j;
    for (i = 0; i < g->rows; i++) {
        for (j = 0; j < g->cols; j++) {
            if (g->grid[i][j].alive) {
                printf("O ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void run_game(grid_t* g) {
    int generations = 100;
    for (int i = 0; i < generations; i++) {
        update_grid(g);
        draw_grid(g);
    }
}

int main() {
    srand(time(NULL));
    grid_t* g = (grid_t*)calloc(1, sizeof(grid_t));
    init_grid(g);
    run_game(g);
    return 0;
}