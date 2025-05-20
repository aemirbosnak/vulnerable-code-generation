//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t* grid) {
    int i, j;

    grid->grid = malloc(GRID_SIZE * CELL_SIZE * sizeof(cell_t*));
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            grid->grid[i * CELL_SIZE + j] = malloc(sizeof(cell_t));
            grid->grid[i * CELL_SIZE + j]->alive = 0;
        }
    }

    grid->rows = GRID_SIZE;
    grid->cols = CELL_SIZE;
}

void update_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i * CELL_SIZE + j]->alive) {
                // Rule 1: Alive cell dies if it has two or three living neighbors
                if (grid->grid[i * CELL_SIZE + j - 1]->alive &&
                        grid->grid[i * CELL_SIZE + j + 1]->alive &&
                        grid->grid[i * CELL_SIZE + j - CELL_SIZE]->alive) {
                    grid->grid[i * CELL_SIZE + j]->alive = 0;
                }

                // Rule 2: Dead cell becomes alive if it has exactly three living neighbors
                else if (grid->grid[i * CELL_SIZE + j - 1]->alive &&
                        grid->grid[i * CELL_SIZE + j + 1]->alive &&
                        grid->grid[i * CELL_SIZE + j - CELL_SIZE]->alive &&
                        !grid->grid[i * CELL_SIZE + j]->alive) {
                    grid->grid[i * CELL_SIZE + j]->alive = 1;
                }
            }
        }
    }
}

void draw_grid(grid_t* grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i * CELL_SIZE + j]->alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    grid_t* grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
    }

    free(grid);

    return 0;
}