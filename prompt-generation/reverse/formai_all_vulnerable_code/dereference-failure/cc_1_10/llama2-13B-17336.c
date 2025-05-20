//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
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

void init_grid(grid_t* grid) {
    int i, j;

    grid->rows = GRID_SIZE;
    grid->cols = GRID_SIZE;

    grid->grid = calloc(grid->rows, sizeof(cell_t*));

    for (i = 0; i < grid->rows; i++) {
        grid->grid[i] = calloc(grid->cols, sizeof(cell_t));

        for (j = 0; j < grid->cols; j++) {
            grid->grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void update_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            int alive_neighbors = 0;

            if (i - 1 >= 0 && grid->grid[i - 1][j].alive) {
                alive_neighbors++;
            }

            if (i + 1 < grid->rows && grid->grid[i + 1][j].alive) {
                alive_neighbors++;
            }

            if (j - 1 >= 0 && grid->grid[i][j - 1].alive) {
                alive_neighbors++;
            }

            if (j + 1 < grid->cols && grid->grid[i][j + 1].alive) {
                alive_neighbors++;
            }

            grid->grid[i][j].alive = (alive_neighbors == 2 || alive_neighbors == 3);
        }
    }
}

void print_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            printf("%d ", grid->grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t* grid = calloc(1, sizeof(grid_t));

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }

    return 0;
}