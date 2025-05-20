//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int next;
} cell_t;

typedef struct grid {
    cell_t** cells;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t* g) {
    g->rows = GRID_SIZE;
    g->cols = GRID_SIZE;
    g->cells = (cell_t**) malloc(g->rows * sizeof(cell_t*));
    for (int i = 0; i < g->rows; i++) {
        g->cells[i] = (cell_t*) malloc(g->cols * sizeof(cell_t));
        for (int j = 0; j < g->cols; j++) {
            g->cells[i][j].alive = 0;
            g->cells[i][j].next = 0;
        }
    }
}

void update_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->cells[i][j].alive) {
                // Check for alive neighbors
                int alive_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int m = -1; m <= 1; m++) {
                        if (k == 0 || m == 0) continue;
                        if (g->cells[i + k][j + m].alive) {
                            alive_neighbors++;
                        }
                    }
                }
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    g->cells[i][j].alive = 0;
                } else {
                    g->cells[i][j].alive = 1;
                }
            }
        }
    }
}

void draw_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->cells[i][j].alive) {
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
    grid_t* g = (grid_t*) malloc(sizeof(grid_t));
    init_grid(g);
    for (int i = 0; i < 100; i++) {
        update_grid(g);
        draw_grid(g);
        printf("\n");
    }
    return 0;
}