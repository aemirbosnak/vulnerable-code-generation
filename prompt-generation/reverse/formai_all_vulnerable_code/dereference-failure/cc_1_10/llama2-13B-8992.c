//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define MAX_GENERATIONS 100

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

typedef struct grid {
    cell_t **grid;
    int width;
    int height;
} grid_t;

void create_grid(grid_t *grid, int width, int height) {
    grid->width = width;
    grid->height = height;
    grid->grid = calloc(width * height, sizeof(cell_t *));
    for (int i = 0; i < width * height; i++) {
        grid->grid[i] = calloc(1, sizeof(cell_t));
        grid->grid[i]->x = i % width;
        grid->grid[i]->y = i / width;
        grid->grid[i]->alive = (i % 2) == 0;
    }
}

void update_grid(grid_t *grid) {
    for (int i = 0; i < grid->width * grid->height; i++) {
        cell_t *cell = grid->grid[i];
        int alive_neighbors = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (j == 0 || k == 0) continue;
                if (cell->x + j < grid->width && cell->y + k < grid->height) {
                    if (grid->grid[cell->x + j + k * grid->width]->alive) {
                        alive_neighbors++;
                    }
                }
            }
        }
        if (alive_neighbors < 2 || alive_neighbors > 3) {
            cell->alive = !cell->alive;
        }
    }
}

void draw_grid(grid_t *grid) {
    for (int i = 0; i < grid->width * grid->height; i++) {
        cell_t *cell = grid->grid[i];
        if (cell->alive) {
            printf("O");
        } else {
            printf(".");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    grid_t grid;
    create_grid(&grid, CELL_WIDTH, CELL_HEIGHT);
    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        update_grid(&grid);
        draw_grid(&grid);
        printf("Generation %d\n", generation + 1);
        sleep(1);
    }
    return 0;
}