//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j].alive) {
                if (rand() % 2) {
                    grid->grid[i][j].alive = 0;
                } else {
                    grid->grid[i][j].alive = 1;
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
    grid_t *grid;

    srand(time(NULL));

    init_grid(&grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
    }

    return 0;
}