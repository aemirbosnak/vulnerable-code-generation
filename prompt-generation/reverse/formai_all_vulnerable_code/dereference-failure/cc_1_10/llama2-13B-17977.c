//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct {
    int state;  // 0 for dead, 1 for alive
    int neighbors;  // number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].state = (i % 2 == 0 && j % 2 == 0) ? 1 : 0;  // initialize cells with a 50% chance of being alive
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to update the game of life grid based on the current state and neighbors
void update_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Check if the cell is alive and has 2 or 3 alive neighbors
            if (grid[i][j].state == 1 && grid[i][j].neighbors >= 2 && grid[i][j].neighbors <= 3) {
                // If so, leave the cell alive
                grid[i][j].state = 1;
            } else if (grid[i][j].state == 1 && grid[i][j].neighbors == 0) {
                // If the cell is alive but has no alive neighbors, it dies
                grid[i][j].state = 0;
            } else if (grid[i][j].state == 0 && grid[i][j].neighbors >= 3) {
                // If the cell is dead but has 3 alive neighbors, it comes to life
                grid[i][j].state = 1;
            }
            grid[i][j].neighbors = 0;  // reset the number of alive neighbors
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].state == 1) {
                        grid[i][j].neighbors++;
                    }
                }
            }
        }
    }
}

// Function to print the game of life grid
void print_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));  // seed the random number generator

    // Initialize the game of life grid
    int size = 20;
    cell_t** grid = (cell_t**) malloc(size * size * sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = (cell_t*) malloc(size * sizeof(cell_t));
    }
    init_grid(grid, size);

    // Run the game of life simulation for 100 steps
    for (int i = 0; i < 100; i++) {
        update_grid(grid, size);
    }

    // Print the final state of the game of life grid
    print_grid(grid, size);

    return 0;
}