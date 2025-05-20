//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define CELL_DEPTH 3

// Struct to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int age;    // The age of the cell (used for simulating the game)
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int rows, int cols) {
    int i, j;
    cell_t** grid = (cell_t**) malloc(rows * sizeof(cell_t*));
    for (i = 0; i < rows; i++) {
        grid[i] = (cell_t*) malloc(cols * sizeof(cell_t));
        for (j = 0; j < cols; j++) {
            grid[i][j].alive = rand() % 2;  // Initialize cells randomly
            grid[i][j].age = 0;
        }
    }
    return grid;
}

// Function to simulate one generation of the game of life
void simulate_generation(cell_t** grid, int rows, int cols) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            // Check the current cell's neighbors
            int alive_neighbors = 0;
            for (k = -1; k <= 1; k++) {
                if (k == 0 || (i + k >= 0 && i + k < rows) && (j + k >= 0 && j + k < cols)) {
                    if (grid[i + k][j + k].alive) {
                        alive_neighbors++;
                    }
                }
            }
            // Apply the game of life rules
            if (grid[i][j].alive && alive_neighbors < 2 && alive_neighbors > 0) {
                grid[i][j].alive = 0;  // Die if there are too few alive neighbors
            } else if (!grid[i][j].alive && alive_neighbors >= 2) {
                grid[i][j].alive = 1;  // Born if there are too many alive neighbors
            }
            // Update the cell's age
            grid[i][j].age++;
        }
    }
}

// Main function
int main() {
    // Create a 10x10 grid of cells
    cell_t** grid = create_grid(10, 10);
    // Simulate 100 generations of the game of life
    for (int i = 0; i < 100; i++) {
        simulate_generation(grid, 10, 10);
    }
    // Print the final state of the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
    // Free the memory allocated for the grid
    free(grid);
    return 0;
}