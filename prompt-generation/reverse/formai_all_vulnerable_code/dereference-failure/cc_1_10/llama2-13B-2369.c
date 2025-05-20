//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int born;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        grid->grid[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (j = 0; j < CELL_SIZE; j++) {
            grid->grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
            grid->grid[i][j].born = 0;
        }
    }
    grid->rows = GRID_SIZE;
    grid->cols = CELL_SIZE;
}

void update_grid(grid_t *grid) {
    int i, j, alive_neighbors = 0;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                alive_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0 || i + k < 0 || i + k >= GRID_SIZE || j + l < 0 || j + l >= CELL_SIZE) {
                            continue;
                        }
                        if (grid->grid[i + k][j + l].alive) {
                            alive_neighbors++;
                        }
                    }
                }
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    grid->grid[i][j].alive = 0;
                }
            }
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
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
    grid_t *grid = calloc(1, sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
        sleep(1);
    }

    return 0;
}