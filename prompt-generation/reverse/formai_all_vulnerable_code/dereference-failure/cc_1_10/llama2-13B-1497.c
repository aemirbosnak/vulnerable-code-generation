//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= size || j + l < 0 || j + l >= size) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors++;
                    }
                }
            }

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors < 2) {
                grid[i][j].alive = 0; // die of loneliness
            } else if (!grid[i][j].alive && neighbors >= 2) {
                grid[i][j].alive = 1; // reproduction
            }
        }
    }
}

// Function to print the game of life grid
void print_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    int size = 10; // Size of the grid
    cell_t** grid = calloc(size, sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = calloc(size, sizeof(cell_t));
    }

    // Initialize the grid
    init_grid(grid, size);

    // Apply the game of life rules for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        apply_rules(grid, size);
    }

    // Print the final grid
    print_grid(grid, size);

    return 0;
}