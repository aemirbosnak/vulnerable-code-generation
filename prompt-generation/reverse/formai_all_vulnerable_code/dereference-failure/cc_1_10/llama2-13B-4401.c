//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t* g) {
    g->grid = calloc(GRID_SIZE, sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        g->grid[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            g->grid[i][j].alive = rand() % 2;
        }
    }
    g->rows = GRID_SIZE;
    g->cols = CELL_SIZE;
}

void update_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k < 0 || i + k >= g->rows || j + l < 0 || j + l >= g->cols) {
                        continue;
                    }
                    if (g->grid[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }
            g->grid[i][j].alive = alive_neighbors == 2 || alive_neighbors == 3;
        }
    }
}

void draw_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    grid_t* g = calloc(1, sizeof(grid_t));
    init_grid(g);

    for (int i = 0; i < 100; i++) {
        update_grid(g);
        draw_grid(g);
        sleep(1);
    }

    free(g);
    return 0;
}