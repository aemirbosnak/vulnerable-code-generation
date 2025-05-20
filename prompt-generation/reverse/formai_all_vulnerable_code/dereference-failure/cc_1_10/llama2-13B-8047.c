//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_WIDTH  10
#define CELL_HEIGHT 10
#define CELL_SIZE  2

#define MAX_GENERATIONS 100

typedef struct {
    int x;
    int y;
} cell_t;

cell_t* generate_random_grid(int width, int height) {
    cell_t* grid = (cell_t*)calloc(width * height, sizeof(cell_t));
    for (int i = 0; i < width * height; i++) {
        grid[i].x = rand() % width;
        grid[i].y = rand() % height;
    }
    return grid;
}

void draw_grid(cell_t* grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i * height + j].x == 0) {
                printf("   ");
            } else if (grid[i * height + j].x == width) {
                printf("|");
            } else {
                printf("%d", grid[i * height + j].x);
            }
            if (grid[i * height + j].y == 0) {
                printf("____");
            } else if (grid[i * height + j].y == height) {
                printf("____");
            } else {
                printf("%d", grid[i * height + j].y);
            }
            printf("\n");
        }
    }
}

void update_grid(cell_t* grid, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        int x = grid[i].x;
        int y = grid[i].y;
        if (x == 0 || x == width || y == 0 || y == height) {
            continue;
        }
        int alive_neighbors = 0;
        if (x - 1 >= 0 && grid[i - CELL_SIZE].x == x - 1 && grid[i - CELL_SIZE].y == y) {
            alive_neighbors++;
        }
        if (x + 1 < width && grid[i + CELL_SIZE].x == x + 1 && grid[i + CELL_SIZE].y == y) {
            alive_neighbors++;
        }
        if (y - 1 >= 0 && grid[i].x == x && grid[i - 1].y == y - 1) {
            alive_neighbors++;
        }
        if (y + 1 < height && grid[i].x == x && grid[i + 1].y == y + 1) {
            alive_neighbors++;
        }
        if (alive_neighbors < 2 || alive_neighbors > 3) {
            grid[i].x = 0;
        } else {
            grid[i].x = 1;
        }
    }
}

int main() {
    int width = 20;
    int height = 10;
    cell_t* grid = generate_random_grid(width, height);
    draw_grid(grid, width, height);
    for (int i = 0; i < MAX_GENERATIONS; i++) {
        update_grid(grid, width, height);
        draw_grid(grid, width, height);
    }
    free(grid);
    return 0;
}