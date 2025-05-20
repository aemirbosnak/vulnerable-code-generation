//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100
#define MAX_GENERATIONS 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int rows;
    int cols;
} grid_t;

void init_grid(grid_t *grid) {
    grid->grid = calloc(GRID_SIZE, sizeof(cell_t *));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid->grid[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            grid->grid[i][j].alive = (rand() % 2) == 0;
        }
    }
    grid->rows = GRID_SIZE;
    grid->cols = CELL_SIZE;
}

void update_grid(grid_t *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int neighbors = count_neighbors(grid, i, j);
            grid->grid[i][j].alive = (grid->grid[i][j].alive && neighbors >= 2) ||
                                        (!grid->grid[i][j].alive && neighbors < 2);
        }
    }
}

int count_neighbors(grid_t *grid, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (i + k >= 0 && i + k < GRID_SIZE &&
                    j + l >= 0 && j + l < CELL_SIZE) {
                if (grid->grid[i + k][j + l].alive) {
                    count++;
                }
            }
        }
    }
    return count;
}

void draw_grid(grid_t *grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
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
    grid_t grid;
    init_grid(&grid);
    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        update_grid(&grid);
        draw_grid(&grid);
        printf("Generation %d\n", generation + 1);
    }
    return 0;
}