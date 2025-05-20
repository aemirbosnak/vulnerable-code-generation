//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
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

void initialize_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            grid->cells[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

void apply_rules(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                if (((i + j) % 2 == 0) && (grid->cells[i + 1][j].alive)) {
                    grid->cells[i][j].alive = 1;
                } else if (((i + j) % 2 == 1) && (grid->cells[i - 1][j].alive)) {
                    grid->cells[i][j].alive = 1;
                } else {
                    grid->cells[i][j].alive = 0;
                }
            }
        }
    }
}

int main() {
    grid_t *grid = malloc(sizeof(grid_t));
    initialize_grid(grid);

    for (int i = 0; i < 10; i++) {
        apply_rules(grid);
        print_grid(grid);
    }

    free(grid);
    return 0;
}