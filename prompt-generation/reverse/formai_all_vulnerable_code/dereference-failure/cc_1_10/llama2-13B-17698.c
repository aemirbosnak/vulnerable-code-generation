//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int size;
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    grid->size = GRID_SIZE;
    grid->grid = calloc(GRID_SIZE, sizeof(cell_t *));

    for (i = 0; i < GRID_SIZE; i++) {
        grid->grid[i] = calloc(CELL_SIZE, sizeof(cell_t));

        for (j = 0; j < CELL_SIZE; j++) {
            grid->grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j, next_alive = 0;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                if (i == 0 || i == GRID_SIZE - 1 || j == 0 || j == CELL_SIZE - 1) {
                    next_alive = 1;
                } else if (grid->grid[i - 1][j].alive && grid->grid[i + 1][j].alive &&
                           grid->grid[i][j - 1].alive && grid->grid[i][j + 1].alive) {
                    next_alive = 1;
                }
            }
        }
    }

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i][j].alive && next_alive) {
                grid->grid[i][j].alive = 1 - grid->grid[i][j].alive;
            }
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            printf("%d ", grid->grid[i][j].alive);
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
    }

    free(grid);

    return 0;
}