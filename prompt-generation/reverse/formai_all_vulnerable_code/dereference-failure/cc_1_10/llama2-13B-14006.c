//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and apply the game of life rules
void apply_rules(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Check the current cell's alive status and its neighbors
            if (grid[i][j].alive) {
                // Count the number of alive neighbors
                grid[i][j].neighbors_alive = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0 || i + k < 0 || j + l < 0 || i + k >= GRID_SIZE || j + l >= GRID_SIZE)
                            continue;
                        if (grid[i + k][j + l].alive)
                            grid[i][j].neighbors_alive++;
                    }
                }
                // Apply the game of life rules
                if (grid[i][j].neighbors_alive < 2 && grid[i][j].alive) {
                    grid[i][j].alive = 0; // Death
                } else if (grid[i][j].neighbors_alive > 3 && grid[i][j].alive) {
                    grid[i][j].alive = 0; // Overpopulation
                } else if (grid[i][j].neighbors_alive == 2 && grid[i][j].alive) {
                    grid[i][j].alive = 1; // Survival
                }
            }
        }
    }
}

// Main function to run the game of life
int main() {
    cell_t** grid = (cell_t**) malloc(GRID_SIZE * sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (cell_t*) malloc(GRID_SIZE * sizeof(cell_t));
    }
    init_grid(grid);

    for (int generations = 0; generations < 100; generations++) {
        apply_rules(grid);
        printf("Generation %d\n", generations);
    }

    free(grid);
    return 0;
}