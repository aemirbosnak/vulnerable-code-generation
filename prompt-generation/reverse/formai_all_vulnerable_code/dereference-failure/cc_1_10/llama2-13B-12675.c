//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a grid cell
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the grid
void init_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Initialize cell as alive with 2 alive neighbors
            grid[i][j].alive = 1;
            grid[i][j].neighbors = 2;
        }
    }
}

// Function to update the grid
void update_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculate the number of alive neighbors
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) neighbors++;
                }
            }

            // Update the cell's state based on the number of alive neighbors
            if (grid[i][j].alive && neighbors < 2) {
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors >= 2) {
                grid[i][j].alive = 1;
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the grid
    cell_t** grid = (cell_t**)calloc(10, sizeof(cell_t*));
    for (int i = 0; i < 10; i++) {
        grid[i] = (cell_t*)calloc(10, sizeof(cell_t));
    }
    init_grid(grid, 10);

    // Update the grid for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        update_grid(grid, 10);
    }

    // Print the final grid
    print_grid(grid, 10);

    return 0;
}