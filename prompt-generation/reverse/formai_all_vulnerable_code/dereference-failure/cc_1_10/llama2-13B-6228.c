//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int x;
    int y;
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
            g->grid[i][j].x = i * CELL_SIZE + j;
            g->grid[i][j].y = i;
            g->grid[i][j].alive = 0;
        }
    }
    g->rows = GRID_SIZE;
    g->cols = CELL_SIZE;
}

void update_grid(grid_t* g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (g->grid[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }
            if (g->grid[i][j].alive && alive_neighbors < 2 && alive_neighbors > 0) {
                g->grid[i][j].alive = 0;
            } else if (!g->grid[i][j].alive && alive_neighbors >= 2) {
                g->grid[i][j].alive = 1;
            }
        }
    }
}

void draw_grid(grid_t* g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (g->grid[i][j].alive) {
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
    grid_t* g = calloc(1, sizeof(grid_t));
    init_grid(g);
    for (int i = 0; i < 100; i++) {
        update_grid(g);
        draw_grid(g);
    }
    free(g);
    return 0;
}