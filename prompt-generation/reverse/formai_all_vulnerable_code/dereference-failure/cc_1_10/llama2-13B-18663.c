//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        grid->grid[i] = (cell_t *)calloc(GRID_SIZE, sizeof(cell_t));
        for (j = 0; j < GRID_SIZE; j++) {
            grid->grid[i][j].alive = rand() % 2;
        }
    }
    grid->rows = GRID_SIZE;
    grid->cols = GRID_SIZE;
}

void update_grid(grid_t *grid) {
    int i, j, next_alive = 0;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                next_alive++;
                if (i + 1 < GRID_SIZE && grid->grid[i + 1][j].alive) {
                    next_alive++;
                }
                if (i - 1 >= 0 && grid->grid[i - 1][j].alive) {
                    next_alive++;
                }
                if (j + 1 < GRID_SIZE && grid->grid[i][j + 1].alive) {
                    next_alive++;
                }
                if (j - 1 >= 0 && grid->grid[i][j - 1].alive) {
                    next_alive++;
                }
            }
        }
    }
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (next_alive > 0) {
                grid->grid[i][j].alive = 1 - grid->grid[i][j].alive;
                next_alive--;
            }
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid->grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    grid_t *grid = (grid_t *)malloc(sizeof(grid_t));
    init_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    free(grid);
    return 0;
}