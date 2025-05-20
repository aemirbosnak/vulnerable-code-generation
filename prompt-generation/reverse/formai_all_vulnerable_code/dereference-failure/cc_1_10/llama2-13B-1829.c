//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 20)

typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

cell_t *create_grid(int size) {
    cell_t *grid = calloc(size, sizeof(cell_t));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i * size + j].x = i * CELL_SIZE;
            grid[i * size + j].y = j * CELL_SIZE;
            grid[i * size + j].alive = 1; // initialize all cells as alive
        }
    }
    return grid;
}

void draw_grid(cell_t *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i * size + j].alive) {
                printf("O"); // draw a dot for alive cells
            } else {
                printf("_"); // draw an underscore for dead cells
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1 * size + j].alive) {
                neighbors++;
            }
            if (i + 1 < size && grid[i + 1 * size + j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i * size + j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < size && grid[i * size + j + 1].alive) {
                neighbors++;
            }
            if (neighbors == 2 || neighbors == 3) {
                grid[i * size + j].alive = 1; // alive cell stays alive
            } else if (neighbors == 0 || neighbors == 1) {
                grid[i * size + j].alive = 0; // dead cell becomes alive
            } else {
                grid[i * size + j].alive = 0; // dead cell stays dead
            }
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int size = 20; // size of the grid
    cell_t *grid = create_grid(size);
    draw_grid(grid, size);
    for (int i = 0; i < 100; i++) {
        update_grid(grid, size);
        draw_grid(grid, size);
    }
    free(grid);
    return 0;
}