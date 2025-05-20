//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WIDTH (100 / CELL_SIZE)
#define HEIGHT (100 / CELL_SIZE)

typedef struct cell {
    int alive;
} cell_t;

cell_t** generate_grid(void) {
    cell_t** grid = calloc(HEIGHT, sizeof(cell_t*));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = calloc(WIDTH, sizeof(cell_t));
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
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
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= HEIGHT || j + l < 0 || j + l >= WIDTH) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }
            if (alive_neighbors < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0;
            } else if (alive_neighbors > 3) {
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
                printf("O ");
            } else {
                printf(" . ");
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