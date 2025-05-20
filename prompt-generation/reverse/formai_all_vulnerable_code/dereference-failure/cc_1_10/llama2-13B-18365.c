//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define MAX_GENERATIONS 100

typedef struct cell {
    int alive;
} cell_t;

void draw_cell(cell_t *cell, int x, int y) {
    if (cell->alive) {
        printf("O");
    } else {
        printf(".");
    }
}

void update_cell(cell_t *cell, int x, int y) {
    if (cell->alive) {
        if (x < CELL_WIDTH / 2 && y < CELL_HEIGHT / 2) {
            cell->alive = 1 - cell->alive;
        }
    }
}

void draw_grid(cell_t *grid, int width, int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            draw_cell(&grid[x * height + y], x * CELL_WIDTH, y * CELL_WIDTH);
        }
    }
}

int main() {
    srand(time(NULL));

    cell_t *grid = (cell_t *) malloc(CELL_WIDTH * CELL_HEIGHT * sizeof(cell_t));

    for (int x = 0; x < CELL_WIDTH; x++) {
        for (int y = 0; y < CELL_HEIGHT; y++) {
            grid[x * CELL_HEIGHT + y].alive = rand() % 2;
        }
    }

    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        for (int x = 0; x < CELL_WIDTH; x++) {
            for (int y = 0; y < CELL_HEIGHT; y++) {
                update_cell(&grid[x * CELL_HEIGHT + y], x, y);
            }
        }
        draw_grid(grid, CELL_WIDTH, CELL_HEIGHT);
        printf("Generation %d\n", generation + 1);
    }

    free(grid);
    return 0;
}