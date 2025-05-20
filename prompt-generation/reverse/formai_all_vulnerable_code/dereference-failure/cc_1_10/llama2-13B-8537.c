//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define CELL_SIZE 10
#define GRID_SIZE 100
#define GENERATIONS 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t* g) {
    g->grid = (cell_t**) malloc(GRID_SIZE * sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        g->grid[i] = (cell_t*) malloc(CELL_SIZE * sizeof(cell_t));
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
            if (g->grid[i][j].alive) {
                if (((i + j) % 2) == 0) {
                    g->grid[i][j].alive = 1 - g->grid[i][j].alive;
                } else {
                    g->grid[i][j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    grid_t* g = (grid_t*) malloc(sizeof(grid_t));
    init_grid(g);

    for (int gen = 0; gen < GENERATIONS; gen++) {
        update_grid(g);
        draw_grid(g);
        usleep(100000);
    }

    free(g->grid);
    free(g);
    return 0;
}