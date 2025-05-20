//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int next;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int size;
} grid_t;

void init_grid(grid_t *g) {
    g->grid = (cell_t **)calloc(GRID_SIZE, sizeof(cell_t *));
    for (int i = 0; i < GRID_SIZE; i++) {
        g->grid[i] = (cell_t *)calloc(CELL_SIZE, sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            g->grid[i][j].alive = (rand() % 2) ? 1 : 0;
            g->grid[i][j].next = (rand() % 2) ? 1 : 0;
        }
    }
    g->size = GRID_SIZE * CELL_SIZE;
}

void update_grid(grid_t *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (g->grid[i][j].alive) {
                if (g->grid[i][j].next) {
                    g->grid[i][j].alive = 0;
                } else {
                    g->grid[i][j].alive = 1;
                    g->grid[i][j].next = 1;
                }
            }
        }
    }
}

void draw_grid(grid_t *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            if (g->grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    grid_t *g = (grid_t *)calloc(1, sizeof(grid_t));
    init_grid(g);

    for (int i = 0; i < 1000; i++) {
        update_grid(g);
        draw_grid(g);
        usleep(10000);
    }

    return 0;
}