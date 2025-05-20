//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10

typedef struct cell {
    char alive;
    int x;
    int y;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t *grid, int rows, int cols) {
    grid->rows = rows;
    grid->cols = cols;
    grid->grid = calloc(sizeof(cell_t*), rows * cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid->grid[i * cols + j] = calloc(1, sizeof(cell_t));
            grid->grid[i * cols + j]->alive = 0;
        }
    }
}

void print_grid(grid_t *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->grid[i * grid->cols + j]->alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void update_grid(grid_t *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->grid[i * grid->cols + j]->alive) {
                if (i < grid->rows - 1 && grid->grid[i * grid->cols + j]->alive &&
                        grid->grid[i * grid->cols + j + 1]->alive &&
                        grid->grid[i * grid->cols + j - 1]->alive) {
                    grid->grid[i * grid->cols + j]->alive = 1 - grid->grid[i * grid->cols + j]->alive;
                } else if (j < grid->cols - 1 && grid->grid[i * grid->cols + j]->alive &&
                           grid->grid[i * grid->cols + j + 1]->alive &&
                           grid->grid[i * grid->cols + j - 1]->alive) {
                    grid->grid[i * grid->cols + j]->alive = 1 - grid->grid[i * grid->cols + j]->alive;
                } else {
                    grid->grid[i * grid->cols + j]->alive = 0;
                }
            }
        }
    }
}

int main() {
    grid_t *grid = calloc(1, sizeof(grid_t));
    init_grid(grid, 10, 10);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }

    return 0;
}