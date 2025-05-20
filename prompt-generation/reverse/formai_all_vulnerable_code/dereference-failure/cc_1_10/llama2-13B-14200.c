//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int rows, int cols) {
    cell_t** grid = (cell_t**) malloc(rows * sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (cell_t*) malloc(cols * sizeof(cell_t));
        for (int j = 0; j < cols; j++) {
            grid[i][j].alive = 0; // Initialize all cells as dead
            grid[i][j].neighbors = 0; // Initialize all cells as having 0 alive neighbors
        }
    }
    return grid;
}

// Function to apply the game of life rules to a grid of cells
void apply_rules(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Count the number of alive neighbors of the current cell
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= rows || j + l < 0 || j + l >= cols) {
                        continue; // Skip if the neighbor is outside the grid
                    }
                    if (grid[i + k][j + l].alive) {
                        alive_neighbors++; // Count the alive neighbor
                    }
                }
            }
            // Update the current cell's state based on the number of alive neighbors
            if (alive_neighbors < 2) {
                grid[i][j].alive = 0; // If the current cell has less than 2 alive neighbors, it dies
            } else if (alive_neighbors > 3) {
                grid[i][j].alive = 0; // If the current cell has more than 3 alive neighbors, it dies
            } else {
                grid[i][j].alive = 1; // If the current cell has 2 or 3 alive neighbors, it stays alive
            }
        }
    }
}

// Function to print the grid of cells
void print_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].alive) {
                printf("O"); // Print an "O" if the cell is alive
            } else {
                printf("."); // Print a "." if the cell is dead
            }
        }
        printf("\n");
    }
}

int main() {
    int rows = 10; // Size of the grid
    int cols = 10;
    cell_t** grid = create_grid(rows, cols);
    apply_rules(grid, rows, cols);
    print_grid(grid, rows, cols);
    return 0;
}