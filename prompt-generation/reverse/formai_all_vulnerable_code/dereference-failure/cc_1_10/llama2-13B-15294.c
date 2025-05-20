//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int next;   // The next state of the cell (0 or 1)
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].next = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // If the cell is alive and has two alive neighbors, keep it alive
            if (grid[i][j].alive && (grid[i][j-1].alive || grid[i][j+1].alive)) {
                grid[i][j].next = 1;
            }
            // If the cell is alive and has three alive neighbors, die
            else if (grid[i][j].alive && (grid[i][j-1].alive && grid[i][j+1].alive)) {
                grid[i][j].next = 0;
            }
            // If the cell is dead and has three alive neighbors, come to life
            else if (!grid[i][j].alive && (grid[i][j-1].alive && grid[i][j+1].alive)) {
                grid[i][j].next = 1;
            }
            // Otherwise, do nothing
        }
    }
}

// Main function
int main() {
    // Create a 10x10 grid of cells
    cell_t** grid = (cell_t**) malloc(10 * sizeof(cell_t*));
    for (int i = 0; i < 10; i++) {
        grid[i] = (cell_t*) malloc(10 * sizeof(cell_t));
    }

    // Initialize the grid with random alive and dead cells
    init_grid(grid, 10);

    // Apply the game of life rules for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        apply_rules(grid, 10);
    }

    // Print the final state of the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}