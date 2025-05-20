//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int rows;
    int cols;
} grid_t;

void create_grid(grid_t* grid, int rows, int cols) {
    grid->grid = (cell_t**) malloc(rows * sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid->grid[i] = (cell_t*) malloc(cols * sizeof(cell_t));
        for (int j = 0; j < cols; j++) {
            grid->grid[i][j].alive = 0;
        }
    }
    grid->rows = rows;
    grid->cols = cols;
}

void update_grid(grid_t* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j].alive) {
                if (is_alive_neighbors(grid, i, j)) {
                    grid->grid[i][j].alive = 1;
                } else {
                    grid->grid[i][j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int is_alive_neighbors(grid_t* grid, int row, int col) {
    int count = 0;
    if (row - 1 >= 0) {
        if (grid->grid[row - 1][col].alive) {
            count++;
        }
    }
    if (row + 1 < grid->rows) {
        if (grid->grid[row + 1][col].alive) {
            count++;
        }
    }
    if (col - 1 >= 0) {
        if (grid->grid[row][col - 1].alive) {
            count++;
        }
    }
    if (col + 1 < grid->cols) {
        if (grid->grid[row][col + 1].alive) {
            count++;
        }
    }
    return count;
}

int main() {
    grid_t* grid = (grid_t*) malloc(sizeof(grid_t));
    create_grid(grid, 10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid->grid[i][j].alive = 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
        draw_grid(grid);
    }
    free(grid);
    return 0;
}