//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate through the grid and update the values
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has alive neighbors
            if (grid[i][j].alive && (grid[i][j].neighbors_alive > 0)) {
                // Increment the number of alive neighbors
                grid[i][j].neighbors_alive++;
            }
            // If the cell is dead and has alive neighbors, set it alive
            else if (!grid[i][j].alive && (grid[i][j].neighbors_alive > 0)) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has no alive neighbors, set it dead
            else if (grid[i][j].alive && (grid[i][j].neighbors_alive == 0)) {
                grid[i][j].alive = 0;
            }
            // Update the number of alive neighbors
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= WIDTH || j + l < 0 || j + l >= HEIGHT)
                        continue;
                    if (grid[i + k][j + l].alive)
                        grid[i][j].neighbors_alive++;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));  // Initialize random number generator

    // Create a 2D array to represent the grid
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * HEIGHT);
    }

    // Initialize the grid with random values
    init_grid(grid);

    // Update the grid for a specified number of generations
    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
    }

    // Free the memory used by the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}