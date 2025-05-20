//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 60

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int born;   // Whether the cell was born in the current generation
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t *grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i * HEIGHT + j].alive = rand() % 2;
            grid[i * HEIGHT + j].born = 0;
        }
    }
}

// Function to apply the Game of Life rules to the grid
void apply_rules(cell_t *grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i * HEIGHT + j].alive &&
                    (grid[i * HEIGHT + j - 1].alive && grid[i * HEIGHT + j + 1].alive && grid[i * HEIGHT + j - 2].alive)) {
                // If so, leave the cell alive in the next generation
                grid[i * HEIGHT + j].alive = 1;
            } else if (!grid[i * HEIGHT + j].alive &&
                    (grid[i * HEIGHT + j - 1].alive || grid[i * HEIGHT + j + 1].alive || grid[i * HEIGHT + j - 2].alive)) {
                // If not, set the cell to alive in the next generation
                grid[i * HEIGHT + j].alive = 1;
            } else {
                // If the cell is not alive and has no alive neighbors, set it to dead
                grid[i * HEIGHT + j].alive = 0;
            }
        }
    }
}

// Main function
int main() {
    cell_t *grid;
    int i, j;

    // Initialize the grid with random values
    init_grid(grid);

    // Apply the Game of Life rules for a certain number of generations
    for (int gen = 0; gen < 10; gen++) {
        apply_rules(grid);

        // Print the current state of the grid
        for (i = 0; i < WIDTH; i++) {
            for (j = 0; j < HEIGHT; j++) {
                if (grid[i * HEIGHT + j].alive) {
                    printf(" alive");
                } else {
                    printf(" dead");
                }
            }
            printf("\n");
        }
    }

    return 0;
}