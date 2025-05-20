//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100
#define GENERATIONS 100

typedef struct {
    int alive;
} cell_t;

cell_t** generate_grid(void) {
    cell_t** grid = calloc(GRID_SIZE, sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = calloc(CELL_SIZE, sizeof(cell_t));
        for (int j = 0; j < CELL_SIZE; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
    return grid;
}

void update_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= GRID_SIZE || j + l < 0 || j + l >= CELL_SIZE) {
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
            } else if (alive_neighbors == 2 && grid[i][j].alive) {
                grid[i][j].alive = 1;
            }
        }
    }
}

void print_grid(cell_t** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < CELL_SIZE; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    cell_t** grid = generate_grid();
    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    free(grid);
    return 0;
}