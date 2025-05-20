//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH  80
#define HEIGHT 25

typedef char cell_t;
typedef cell_t* grid_t;

grid_t grid_create(int width, int height) {
    cell_t* grid = malloc(sizeof(cell_t) * width * height);
    memset(grid, ' ', sizeof(cell_t) * width * height);
    return grid;
}

void grid_free(grid_t grid) {
    free(grid);
}

void grid_randomize(grid_t grid, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[y * width + x] = rand() % 2 ? 'X' : ' ';
        }
    }
}

int grid_count_neighbors(grid_t grid, int width, int height, int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                continue;
            }
            if (grid[ny * width + nx] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void grid_evolve(grid_t grid, grid_t next_grid, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int count = grid_count_neighbors(grid, width, height, x, y);
            if (grid[y * width + x] == 'X') {
                if (count < 2 || count > 3) {
                    next_grid[y * width + x] = ' ';
                } else {
                    next_grid[y * width + x] = 'X';
                }
            } else {
                if (count == 3) {
                    next_grid[y * width + x] = 'X';
                } else {
                    next_grid[y * width + x] = ' ';
                }
            }
        }
    }
}

void grid_print(grid_t grid, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(grid[y * width + x]);
        }
        putchar('\n');
    }
}

int main() {
    grid_t grid = grid_create(WIDTH, HEIGHT);
    grid_t next_grid = grid_create(WIDTH, HEIGHT);

    grid_randomize(grid, WIDTH, HEIGHT);

    while (true) {
        grid_evolve(grid, next_grid, WIDTH, HEIGHT);
        grid_print(next_grid, WIDTH, HEIGHT);
        memcpy(grid, next_grid, sizeof(cell_t) * WIDTH * HEIGHT);
        usleep(100000);
    }

    grid_free(grid);
    grid_free(next_grid);

    return 0;
}