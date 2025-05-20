//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
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

    grid->grid = calloc(grid->rows, sizeof(cell_t*) );

    for (i = 0; i < grid->rows; i++) {
        grid->grid[i] = calloc(grid->cols, sizeof(cell_t) );

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
                // Count the number of alive neighbors
                int alive_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0 || i + k < 0 || i + k >= grid->rows || j + l < 0 || j + l >= grid->cols) {
                            continue;
                        }

                        if (grid->grid[i + k][j + l].alive) {
                            alive_neighbors++;
                        }
                    }
                }

                // Apply the rules
                if (alive_neighbors < 2 && alive_neighbors > 0) {
                    grid->grid[i][j].alive = 0;
                } else if (alive_neighbors == 2) {
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

    grid_t *grid = calloc(1, sizeof(grid_t) );
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1);
    }

    return 0;
}