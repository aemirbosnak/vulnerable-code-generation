//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

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

    grid->rows = WINDOW_HEIGHT / CELL_SIZE;
    grid->cols = WINDOW_WIDTH / CELL_SIZE;

    grid->grid = calloc(grid->rows, sizeof(cell_t *));

    for (i = 0; i < grid->rows; i++) {
        grid->grid[i] = calloc(grid->cols, sizeof(cell_t));

        for (j = 0; j < grid->cols; j++) {
            grid->grid[i][j].alive = 0;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            int alive_neighbors = 0;

            // Check north neighbor
            if (i > 0 && grid->grid[i - 1][j].alive) {
                alive_neighbors++;
            }

            // Check south neighbor
            if (i < grid->rows - 1 && grid->grid[i + 1][j].alive) {
                alive_neighbors++;
            }

            // Check west neighbor
            if (j > 0 && grid->grid[i][j - 1].alive) {
                alive_neighbors++;
            }

            // Check east neighbor
            if (j < grid->cols - 1 && grid->grid[i][j + 1].alive) {
                alive_neighbors++;
            }

            // Update cell state based on number of alive neighbors
            if (alive_neighbors < 2 && grid->grid[i][j].alive) {
                grid->grid[i][j].alive = 0;
            } else if (alive_neighbors > 3 && !grid->grid[i][j].alive) {
                grid->grid[i][j].alive = 1;
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j].alive) {
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

    grid_t grid;
    init_grid(&grid);

    for (int i = 0; i < 100; i++) {
        update_grid(&grid);
        draw_grid(&grid);
        printf("\n");
    }

    return 0;
}