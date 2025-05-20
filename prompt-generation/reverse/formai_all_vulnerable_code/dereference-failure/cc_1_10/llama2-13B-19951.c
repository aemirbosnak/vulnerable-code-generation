//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int next;   // The next state of the cell (for the next iteration)
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].next = grid[i][j].alive;
        }
    }
}

// Function to iterate through the grid and update cell states
void update_grid(cell_t** grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // If the cell is alive and has two or three alive neighbors, keep it alive
            // Otherwise, set it to dead
            if (grid[i][j].alive && (grid[i][j].next == grid[i][j].alive)) {
                grid[i][j].next = grid[i][j].alive;
            } else {
                grid[i][j].next = 0; // Set to dead
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    // Create a 2D grid of size 10x10
    cell_t** grid = calloc(10, sizeof(cell_t*));
    for (int i = 0; i < 10; i++) {
        grid[i] = calloc(10, sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid, 10, 10);

    // Update the grid for 100 iterations
    for (int i = 0; i < 100; i++) {
        update_grid(grid, 10, 10);
    }

    // Print the final grid
    print_grid(grid, 10, 10);

    return 0;
}