//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
} cell_t;

typedef struct grid {
    cell_t grid[GRID_SIZE][CELL_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            grid->grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i][j].alive) {
                if (((i + j) % 2 == 0) && (i % 2 == 0) && (j % 2 == 0)) {
                    grid->grid[i][j].alive = 1 - grid->grid[i][j].alive;
                } else {
                    grid->grid[i][j].alive = 0;
                }
            }
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (grid->grid[i][j].alive) {
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
    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);

    for (int i = 0; i < 1000; i++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", i + 1);
        sleep(1);
    }

    free(grid);
    return 0;
}