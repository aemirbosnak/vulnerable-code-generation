//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GENERATIONS 100

typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

cell_t** create_grid(int size) {
    cell_t** grid = malloc(size * size * sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(cell_t));
        for (int j = 0; j < size; j++) {
            grid[i][j] = (cell_t){1, 0}; // Initialize all cells as alive
        }
    }
    return grid;
}

void update_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < size && j + l >= 0 && j + l < size) {
                        if (grid[i + k][j + l].alive) {
                            alive_neighbors++;
                        }
                    }
                }
            }
            grid[i][j].neighbors_alive = alive_neighbors;
            if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                grid[i][j].alive = 0; // Die of loneliness
            } else if (!grid[i][j].alive && grid[i][j].neighbors_alive >= 2) {
                grid[i][j].alive = 1; // Reproduce with many neighbors
            }
        }
    }
}

void draw_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size = CELL_WIDTH * CELL_HEIGHT;
    cell_t** grid = create_grid(size);
    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(grid, size);
        draw_grid(grid, size);
        printf("Generation %d\n", i + 1);
    }
    free(grid);
    return 0;
}