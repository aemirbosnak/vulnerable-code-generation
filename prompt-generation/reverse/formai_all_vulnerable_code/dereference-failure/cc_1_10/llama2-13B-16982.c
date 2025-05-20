//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

cell_t *grid;

void init_grid(void) {
    grid = calloc(GRID_SIZE, sizeof(cell_t));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i].x = i % CELL_WIDTH;
        grid[i].y = i / CELL_WIDTH;
        grid[i].alive = (i % 2) == 0;
    }
}

void update_grid(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        int alive_neighbors = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (j == 0 || k == 0 || i + j + k >= GRID_SIZE || i + j + k < 0) continue;
                if (grid[i + j + k].alive) alive_neighbors++;
            }
        }
        if (alive_neighbors < 2 && grid[i].alive) {
            grid[i].alive = 0;
        } else if (alive_neighbors > 3) {
            grid[i].alive = 0;
        } else {
            grid[i].alive = 1;
        }
    }
}

void draw_grid(void) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i].alive) {
            printf("O ");
        } else {
            printf(" . ");
        }
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    init_grid();
    for (int i = 0; i < 100; i++) {
        update_grid();
        draw_grid();
    }
    return 0;
}