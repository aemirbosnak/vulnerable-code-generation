//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100
#define GENERATIONS 100

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

    grid->rows = GRID_SIZE;
    grid->cols = GRID_SIZE;

    grid->grid = calloc(grid->rows, sizeof(cell_t*));

    for (i = 0; i < grid->rows; i++) {
        grid->grid[i] = calloc(grid->cols, sizeof(cell_t));

        for (j = 0; j < grid->cols; j++) {
            grid->grid[i][j].alive = rand() % 2;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j].alive) {
                // Check if the cell is alive and has two or three alive neighbors
                int neighbors = 0;
                if (grid->grid[i][j-1].alive && grid->grid[i][j+1].alive) {
                    neighbors++;
                }
                if (grid->grid[i-1][j].alive && grid->grid[i+1][j].alive) {
                    neighbors++;
                }
                if (neighbors >= 2 && neighbors <= 3) {
                    grid->grid[i][j].alive = 1; // Cell stays alive
                } else {
                    grid->grid[i][j].alive = 0; // Cell dies
                }
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j].alive) {
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

    grid_t grid;
    init_grid(&grid);

    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(&grid);
        draw_grid(&grid);
    }

    return 0;
}