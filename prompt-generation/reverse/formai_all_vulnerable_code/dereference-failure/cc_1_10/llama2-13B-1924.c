//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t cells[GRID_SIZE][CELL_SIZE];
} grid_t;

void create_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            grid->cells[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void apply_rules(grid_t *grid) {
    int i, j, alive_neighbors = 0;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                alive_neighbors = 0;

                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) {
                            continue;
                        }

                        if (grid->cells[i + k][j + l].alive) {
                            alive_neighbors++;
                        }
                    }
                }

                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    grid->cells[i][j].alive = 0;
                }
            }
        }
    }
}

int main() {
    grid_t *grid = (grid_t *)malloc(sizeof(grid_t));
    create_grid(grid);

    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
        print_grid(grid);
    }

    free(grid);
    return 0;
}