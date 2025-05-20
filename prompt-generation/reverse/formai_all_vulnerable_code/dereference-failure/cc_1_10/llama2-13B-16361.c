//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

typedef struct {
    int x;
    int y;
} cell_t;

cell_t** generate_grid(int width, int height) {
    cell_t** grid = calloc(width, sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = calloc(height, sizeof(cell_t));
        for (int j = 0; j < height; j++) {
            grid[i][j] = (cell_t) {i * CELL_SIZE, j * CELL_SIZE};
        }
    }
    return grid;
}

void draw_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("{%d, %d}", grid[i][j].x, grid[i][j].y);
            if (grid[i][j].x % CELL_SIZE == 0 && grid[i][j].y % CELL_SIZE == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].x < CELL_SIZE - 1 && grid[i][j].y < CELL_SIZE - 1) {
                if (grid[i][j].x + 1 == grid[i][j].x && grid[i][j].y + 1 == grid[i][j].y) {
                    grid[i][j].x++;
                } else if (grid[i][j].x - 1 == grid[i][j].x && grid[i][j].y + 1 == grid[i][j].y) {
                    grid[i][j].y++;
                } else if (grid[i][j].x + 1 == grid[i][j].x && grid[i][j].y - 1 == grid[i][j].y) {
                    grid[i][j].x++;
                } else if (grid[i][j].x - 1 == grid[i][j].x && grid[i][j].y - 1 == grid[i][j].y) {
                    grid[i][j].y--;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    cell_t** grid = generate_grid(WINDOW_WIDTH, WINDOW_HEIGHT);
    draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    for (int i = 0; i < 1000; i++) {
        update_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
        draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    return 0;
}