//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 100
#define CELL_SIZE 10

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to allocate memory for the grid
void *grid_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    return ptr;
}

// Function to deallocate memory for the grid
void grid_free(void *ptr) {
    free(ptr);
}

// Function to initialize the grid
void init_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and apply the game of life rules
void update_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;  // Skip diagonals
                    }
                    if (i + k < 0 || i + k >= GRID_SIZE || j + l < 0 || j + l >= GRID_SIZE) {
                        continue;  // Skip outside the grid
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }
            // Update the cell's state based on the number of alive neighbors
            if (neighbors_alive < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0;  // If the cell is alone, it dies
            } else if (neighbors_alive >= 2 && !grid[i][j].alive) {
                grid[i][j].alive = 1;  // If the cell has two or more alive neighbors, it comes to life
            }
        }
    }
}

int main() {
    cell_t **grid = NULL;
    // Allocate memory for the grid
    grid = grid_alloc(GRID_SIZE * GRID_SIZE * sizeof(cell_t));
    if (grid == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    // Initialize the grid
    init_grid(grid);
    // Run the game of life for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }
    // Free the memory for the grid
    grid_free(grid);
    return 0;
}