//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct cell {
    int alive;
} cell_t;

cell_t** grid;

void init_grid(void) {
    grid = (cell_t**) malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(HEIGHT * sizeof(cell_t));
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

void update_grid(void) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= WIDTH || j + l < 0 || j + l >= HEIGHT) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }
            if (neighbors_alive < 2 || neighbors_alive > 3) {
                grid[i][j].alive = !grid[i][j].alive;
            }
        }
    }
}

void draw_grid(void) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    init_grid();
    for (int generations = 0; generations < 100; generations++) {
        update_grid();
        draw_grid();
    }
    return 0;
}