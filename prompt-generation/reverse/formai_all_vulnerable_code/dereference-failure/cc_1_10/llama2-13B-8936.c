//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define CELL_COLORS { \
    { 255, 0, 0 }, /* red */ \
    { 0, 255, 0 }, /* green */ \
    { 0, 0, 255 }, /* blue */ \
    { 255, 255, 0 }, /* yellow */ \
    { 0, 0, 0 }, /* black */ \
    { 255, 0, 255 }, /* purple */ \
    { 0, 255, 255 }, /* cyan */ \
    { 255, 255, 255 }, /* white */ \
    { 0, 0, 0, 0 }  /* transparent */ \
}

typedef struct cell {
    int x;
    int y;
    int state;
} cell_t;

void init_grid(cell_t **grid, int size_x, int size_y) {
    int i, j;
    for (i = 0; i < size_x; i++) {
        for (j = 0; j < size_y; j++) {
            grid[i][j].x = i * CELL_WIDTH;
            grid[i][j].y = j * CELL_HEIGHT;
            grid[i][j].state = rand() % 8;
        }
    }
}

void draw_grid(cell_t **grid, int size_x, int size_y) {
    int i, j;
    for (i = 0; i < size_x; i++) {
        for (j = 0; j < size_y; j++) {
            switch (grid[i][j].state) {
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf(" 🔵");
                    break;
                case 2:
                    printf(" 🔴");
                    break;
                case 3:
                    printf(" 🔵");
                    break;
                case 4:
                    printf(" 🔴");
                    break;
                case 5:
                    printf("   ");
                    break;
                case 6:
                    printf(" 🔵");
                    break;
                case 7:
                    printf(" 🔴");
                    break;
            }
        }
        printf("\n");
    }
}

void update_grid(cell_t **grid, int size_x, int size_y, int generations) {
    int i, j, alive_neighbors = 0;
    for (i = 0; i < size_x; i++) {
        for (j = 0; j < size_y; j++) {
            int neighbor_count = 0;
            if (i - 1 >= 0 && grid[i - 1][j].state == 1) neighbor_count++;
            if (i + 1 < size_x && grid[i + 1][j].state == 1) neighbor_count++;
            if (j - 1 >= 0 && grid[i][j - 1].state == 1) neighbor_count++;
            if (j + 1 < size_y && grid[i][j + 1].state == 1) neighbor_count++;
            if (neighbor_count == 2 || neighbor_count == 3) {
                grid[i][j].state = 1;
                alive_neighbors++;
            } else if (neighbor_count == 0) {
                grid[i][j].state = 0;
            }
        }
    }
    if (alive_neighbors == 0) {
        for (i = 0; i < size_x; i++) {
            for (j = 0; j < size_y; j++) {
                grid[i][j].state = 0;
            }
        }
    }
    generations++;
}

int main() {
    srand(time(0));
    int size_x = 100;
    int size_y = 100;
    cell_t **grid = malloc(size_x * sizeof(cell_t *));
    for (int i = 0; i < size_x; i++) {
        grid[i] = malloc(size_y * sizeof(cell_t));
    }
    init_grid(grid, size_x, size_y);
    draw_grid(grid, size_x, size_y);
    int generations = 0;
    while (1) {
        update_grid(grid, size_x, size_y, generations);
        generations++;
        if (generations % 100 == 0) {
            draw_grid(grid, size_x, size_y);
            printf("Generation %d\n", generations);
        }
    }
    return 0;
}