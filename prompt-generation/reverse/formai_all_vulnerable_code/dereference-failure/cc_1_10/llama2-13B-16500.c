//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_HEIGHT; i++) {
        for (j = 0; j < CELL_WIDTH; j++) {
            grid->cells[i * CELL_WIDTH + j].alive = (i + j) % 2;
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < CELL_HEIGHT; i++) {
        for (j = 0; j < CELL_WIDTH; j++) {
            if (grid->cells[i * CELL_WIDTH + j].alive) {
                printf("O ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

void apply_rules(grid_t *grid) {
    int i, j, alive_neighbors = 0;
    for (i = 0; i < CELL_HEIGHT; i++) {
        for (j = 0; j < CELL_WIDTH; j++) {
            if (grid->cells[i * CELL_WIDTH + j].alive) {
                alive_neighbors = count_alive_neighbors(grid, i, j);
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    grid->cells[i * CELL_WIDTH + j].alive = 0;
                }
            }
        }
    }
}

int count_alive_neighbors(grid_t *grid, int i, int j) {
    int alive_neighbors = 0;
    int offset = 1;
    if (i - 1 >= 0) {
        alive_neighbors += grid->cells[(i - 1) * CELL_WIDTH + j].alive;
    }
    if (i + 1 < CELL_HEIGHT) {
        alive_neighbors += grid->cells[i * CELL_WIDTH + (j + offset)].alive;
    }
    if (j - 1 >= 0) {
        alive_neighbors += grid->cells[i * CELL_WIDTH + (j - offset)].alive;
    }
    if (j + 1 < CELL_WIDTH) {
        alive_neighbors += grid->cells[(i + offset) * CELL_WIDTH + j].alive;
    }
    return alive_neighbors;
}

int main() {
    srand(time(NULL));
    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
        print_grid(grid);
    }

    free(grid);
    return 0;
}