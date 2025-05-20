//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;    // Whether the cell is alive or dead
    int born;    // Whether the cell was born this iteration
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].alive = rand() % 2;
            grid[i * GRID_SIZE + j].born = 0;
        }
    }
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(cell_t* grid) {
    int i, j, alive_neighbors, dead_neighbors;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            alive_neighbors = 0;
            dead_neighbors = 0;
            // Count the number of alive and dead neighbors
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid[i * GRID_SIZE + j].alive && grid[i * GRID_SIZE + j + k].alive && grid[i * GRID_SIZE + j + l].alive) {
                        alive_neighbors++;
                    }
                    if (!grid[i * GRID_SIZE + j].alive && grid[i * GRID_SIZE + j + k].alive && grid[i * GRID_SIZE + j + l].alive) {
                        dead_neighbors++;
                    }
                }
            }
            // Update the cell's status based on the number of alive and dead neighbors
            if (alive_neighbors > 2 && dead_neighbors < 2) {
                grid[i * GRID_SIZE + j].alive = 1;
            } else if (alive_neighbors < 2 && dead_neighbors > 2) {
                grid[i * GRID_SIZE + j].alive = 0;
            } else {
                grid[i * GRID_SIZE + j].alive = grid[i * GRID_SIZE + j].alive;
            }
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t* grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    cell_t* grid = malloc(GRID_SIZE * GRID_SIZE * sizeof(cell_t));
    init_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }
    print_grid(grid);
    free(grid);
    return 0;
}