//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

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
            grid[i * size + j].alive = (i % 2) == 0;
        }
    }
    return grid;
}

void update_grid(cell_t *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    int x = grid[i * size + j].x + k * CELL_SIZE;
                    int y = grid[i * size + j].y + l * CELL_SIZE;
                    if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT && grid[i * size + j].alive == grid[x + y * size].alive) {
                        alive_neighbors++;
                    }
                }
            }
            grid[i * size + j].alive = (alive_neighbors == 2 || alive_neighbors == 3) ? 1 : 0;
        }
    }
}

void draw_grid(cell_t *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i * size + j].alive) {
                printf("O ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 100;
    cell_t *grid = create_grid(size);
    update_grid(grid, size);
    draw_grid(grid, size);
    system("pause");
    free(grid);
    return 0;
}