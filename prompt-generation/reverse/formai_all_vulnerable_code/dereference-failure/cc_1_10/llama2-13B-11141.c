//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct {
    int x;
    int y;
} cell_t;

typedef struct {
    cell_t cells[GRID_SIZE];
} grid_t;

void init_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid->cells[i * GRID_SIZE + j].x = i % CELL_WIDTH;
            grid->cells[i * GRID_SIZE + j].y = j % CELL_HEIGHT;
        }
    }
}

void draw_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("{%d, %d}", grid->cells[i * GRID_SIZE + j].x, grid->cells[i * GRID_SIZE + j].y);
            if (grid->cells[i * GRID_SIZE + j].x == 0 || grid->cells[i * GRID_SIZE + j].y == 0) {
                printf(" (dead)");
            } else {
                printf(" (alive)");
            }
            printf("\n");
        }
    }
}

void update_grid(grid_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid->cells[i * GRID_SIZE + j].x == 0 || grid->cells[i * GRID_SIZE + j].y == 0) {
                continue;
            }
            int num_alive_neighbors = count_alive_neighbors(grid, i, j);
            if (num_alive_neighbors > 2) {
                grid->cells[i * GRID_SIZE + j].x = 0;
                grid->cells[i * GRID_SIZE + j].y = 0;
            } else if (num_alive_neighbors < 2) {
                grid->cells[i * GRID_SIZE + j].x = 1;
                grid->cells[i * GRID_SIZE + j].y = 1;
            }
        }
    }
}

int count_alive_neighbors(grid_t *grid, int x, int y) {
    int count = 0;
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (x + i >= 0 && x + i < GRID_SIZE && y + j >= 0 && y + j < GRID_SIZE && grid->cells[x + i * GRID_SIZE + y + j].x != 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    grid_t *grid = malloc(sizeof(grid_t));
    init_grid(grid);
    draw_grid(grid);
    update_grid(grid);
    free(grid);
    return 0;
}