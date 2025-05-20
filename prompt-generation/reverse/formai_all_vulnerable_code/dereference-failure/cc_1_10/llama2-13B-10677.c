//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
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

    grid->grid = malloc(GRID_SIZE * sizeof(cell_t *));

    for (i = 0; i < GRID_SIZE; i++) {
        grid->grid[i] = malloc(GRID_SIZE * sizeof(cell_t));

        for (j = 0; j < GRID_SIZE; j++) {
            grid->grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                if (((i + j) % 2) == 0) {
                    // alive cell has two or three alive neighbors, leave it alive
                    if (grid->grid[i][j - 1].alive && grid->grid[i][j + 1].alive && grid->grid[i + 1][j].alive) {
                        grid->grid[i][j].alive = 1;
                    } else {
                        // otherwise, it dies
                        grid->grid[i][j].alive = 0;
                    }
                } else {
                    // alive cell has one alive neighbor, leave it alive
                    if (grid->grid[i][j - 1].alive) {
                        grid->grid[i][j].alive = 1;
                    } else {
                        // otherwise, it dies
                        grid->grid[i][j].alive = 0;
                    }
                }
            } else {
                // dead cell has three alive neighbors, bring it to life
                if (grid->grid[i][j - 1].alive && grid->grid[i][j + 1].alive && grid->grid[i + 1][j].alive) {
                    grid->grid[i][j].alive = 1;
                }
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1);
    }

    free(grid);

    return 0;
}