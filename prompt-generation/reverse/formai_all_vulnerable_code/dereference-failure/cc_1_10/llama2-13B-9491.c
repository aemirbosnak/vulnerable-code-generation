//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE (CELL_SIZE * CELL_SIZE)

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t grid[GRID_SIZE][GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->grid[i][j].alive = (i % 2 == 0 && j % 2 == 0) ? 1 : 0;
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j, next_alive = 0;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                next_alive = (i % 2 == 0 && j % 2 == 1) ? 1 : 0;
                grid->grid[i][j].alive = next_alive;
            }
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid->grid[i][j].alive);
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
        print_grid(grid);
    }

    free(grid);

    return 0;
}