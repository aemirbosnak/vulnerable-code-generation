//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WIDTH (100 / CELL_SIZE)
#define HEIGHT (100 / CELL_SIZE)

typedef struct {
    int alive;
} cell_t;

cell_t** generate_grid(void) {
    cell_t** grid = calloc(HEIGHT, sizeof(cell_t*));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = calloc(WIDTH, sizeof(cell_t));
        for (int j = 0; j < WIDTH; j++) {
            int x = rand() % CELL_SIZE;
            int y = rand() % CELL_SIZE;
            if (x < CELL_SIZE / 2 && y < CELL_SIZE / 2) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }
        }
    }
    return grid;
}

void update_grid(cell_t** grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    int x = i * CELL_SIZE + j + k * CELL_SIZE;
                    int y = i * CELL_SIZE + j + l * CELL_SIZE;
                    if (x >= 0 && x < WIDTH * CELL_SIZE && y >= 0 && y < HEIGHT * CELL_SIZE) {
                        if (grid[x / CELL_SIZE][y / CELL_SIZE].alive) {
                            alive_neighbors++;
                        }
                    }
                }
            }
            if (alive_neighbors < 2 || alive_neighbors > 3) {
                grid[i][j].alive = 0;
            } else {
                grid[i][j].alive = 1;
            }
        }
    }
}

void draw_grid(cell_t** grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    cell_t** grid = generate_grid();
    update_grid(grid);
    draw_grid(grid);
    return 0;
}