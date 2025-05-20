//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

typedef struct cell {
    int alive;
    int neighbors[CELL_SIZE * CELL_SIZE];
} cell_t;

void game_of_life(cell_t *grid, int generation) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cell_t *cell = &grid[i * CELL_SIZE + j];
            int alive = cell->alive;

            // Count the number of alive neighbors
            int neighbors = 0;
            for (int k = -CELL_SIZE; k <= CELL_SIZE; k++) {
                for (int l = -CELL_SIZE; l <= CELL_SIZE; l++) {
                    if (k == 0 && l == 0) continue;
                    int index = (i + k) * CELL_SIZE + j + l;
                    if (index < 0 || index >= GRID_SIZE * GRID_SIZE) continue;
                    if (grid[index].alive) neighbors++;
                }
            }

            // Apply the rules
            if (alive && neighbors < 2) {
                // If alive and has fewer than 2 alive neighbors, die
                cell->alive = 0;
            } else if (!alive && neighbors >= 3) {
                // If dead and has 3 or more alive neighbors, come to life
                cell->alive = 1;
            } else {
                // Otherwise, keep the current state
            }
        }
    }
}

int main() {
    cell_t *grid = calloc(GRID_SIZE, sizeof(cell_t));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i * CELL_SIZE + j].alive = (i % 2 == 0) ? 1 : 0;
        }
    }

    for (int generation = 0; generation < 100; generation++) {
        game_of_life(grid, generation);
    }

    free(grid);
    return 0;
}