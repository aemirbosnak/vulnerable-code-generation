//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to simulate one generation of the game of life
void simulate_generation(cell_t **grid, int width, int height) {
    int i, j;

    // Loop through each cell in the grid
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // If the cell is alive and has 2 or 3 alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j].neighbors_alive >= 2 && grid[i][j].neighbors_alive <= 3)) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has less than 2 alive neighbors, die
            else if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                grid[i][j].alive = 0;
            }
            // If the cell is dead and has 3 alive neighbors, come to life
            else if (!grid[i][j].alive && grid[i][j].neighbors_alive == 3) {
                grid[i][j].alive = 1;
            }
            // Otherwise, do nothing

            // Update the number of alive neighbors for the current cell
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= width || j + l < 0 || j + l >= height) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors_alive++;
                    }
                }
            }
        }
    }
}

// Function to display the grid
void display_grid(cell_t **grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    int width = 20;  // Grid size
    int height = 20;

    // Initialize the grid with random values
    cell_t **grid = malloc(width * sizeof(cell_t *));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
    }
    init_grid(grid, width, height);

    // Simulate the game of life for 100 generations
    for (int i = 0; i < 100; i++) {
        simulate_generation(grid, width, height);
    }

    // Display the final grid
    display_grid(grid, width, height);

    // Free memory
    for (int i = 0; i < width; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}