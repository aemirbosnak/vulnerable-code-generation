//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

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
    g->grid = malloc(GRID_SIZE * CELL_SIZE * sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            g->grid[i * CELL_SIZE + j] = malloc(sizeof(cell_t));
            g->grid[i * CELL_SIZE + j]->x = i * CELL_SIZE;
            g->grid[i * CELL_SIZE + j]->y = j;
            g->grid[i * CELL_SIZE + j]->alive = rand() % 2;
        }
    }
    g->rows = GRID_SIZE;
    g->cols = CELL_SIZE;
}

void update_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            cell_t* cell = g->grid[i * g->cols + j];
            if (cell->alive) {
                if (cell->x + 1 < g->rows && g->grid[i * g->cols + cell->x + 1]->alive) {
                    cell->alive = 1 - cell->alive;
                }
                if (cell->x - 1 >= 0 && g->grid[i * g->cols + cell->x - 1]->alive) {
                    cell->alive = 1 - cell->alive;
                }
                if (cell->y + 1 < g->cols && g->grid[i * g->cols + cell->y + 1]->alive) {
                    cell->alive = 1 - cell->alive;
                }
                if (cell->y - 1 >= 0 && g->grid[i * g->cols + cell->y - 1]->alive) {
                    cell->alive = 1 - cell->alive;
                }
            }
        }
    }
}

void draw_grid(grid_t* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            cell_t* cell = g->grid[i * g->cols + j];
            if (cell->alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    grid_t* g = malloc(sizeof(grid_t));
    init_grid(g);
    for (int i = 0; i < 100; i++) {
        update_grid(g);
        draw_grid(g);
        usleep(100000);
    }
    free(g->grid);
    return 0;
}