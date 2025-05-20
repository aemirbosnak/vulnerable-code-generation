//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct {
    int alive;
} cell_t;

typedef struct {
    cell_t cells[GRID_SIZE][GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void apply_rules(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i][j].alive) {
                // Check if the cell is alive and has two or three alive neighbors
                int num_alive_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) {
                            continue;
                        }
                        if (grid->cells[i + k][j + l].alive) {
                            num_alive_neighbors++;
                        }
                    }
                }

                // If the cell is alive and has two or three alive neighbors, leave it alive
                if (num_alive_neighbors >= 2 && num_alive_neighbors <= 3) {
                    grid->cells[i][j].alive = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (num_alive_neighbors < 2) {
                        grid->cells[i][j].alive = 0;
                    }
                }
            }
        }
    }
}

void print_grid(grid_t *grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid->cells[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    grid_t *grid = (grid_t *)malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
        print_grid(grid);
    }

    free(grid);
    return 0;
}