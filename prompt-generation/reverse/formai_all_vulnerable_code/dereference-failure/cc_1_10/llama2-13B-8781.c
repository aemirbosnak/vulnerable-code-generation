//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct {
    int x;
    int y;
} cell_t;

cell_t** generate_grid(int width, int height) {
    cell_t** grid = (cell_t**)calloc(width, sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = (cell_t*)calloc(height, sizeof(cell_t));
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j].x = i * CELL_SIZE;
            grid[i][j].y = j * CELL_SIZE;
        }
    }
    return grid;
}

void draw_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].x == 0 && grid[i][j].y == 0) {
                continue;
            }
            printf(" %d", grid[i][j].x);
        }
        printf("\n");
    }
}

void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].x == grid[i][j].x) {
                neighbors++;
            }
            if (i + 1 < width && grid[i + 1][j].x == grid[i][j].x) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].x == grid[i][j].x) {
                neighbors++;
            }
            if (j + 1 < height && grid[i][j + 1].x == grid[i][j].x) {
                neighbors++;
            }
            if (neighbors == 2 || neighbors == 3) {
                grid[i][j].x++;
            } else if (neighbors == 0) {
                grid[i][j].x--;
            }
        }
    }
}

int main() {
    cell_t** grid = generate_grid(WINDOW_WIDTH, WINDOW_HEIGHT);
    draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    update_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    while (1) {
        update_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
        draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    return 0;
}