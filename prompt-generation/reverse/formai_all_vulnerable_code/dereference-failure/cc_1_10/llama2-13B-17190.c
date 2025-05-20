//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the grid
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Calculate the number of alive neighbors
            int neighbors = count_alive_neighbors(grid, i, j);

            // Apply the rules of the Game of Life
            if (grid[i][j].alive && neighbors >= 2 && neighbors <= 3) {
                // Cell is alive and has 2-3 alive neighbors, leave it alone
                grid[i][j].alive = 1;
            } else if (!grid[i][j].alive && neighbors == 3) {
                // Cell is dead and has 3 alive neighbors, bring it back to life
                grid[i][j].alive = 1;
            } else {
                // Cell is either dead or alive, and has fewer than 2 or more than 3 alive neighbors
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to count the number of alive neighbors of a cell
int count_alive_neighbors(cell_t** grid, int i, int j) {
    int neighbors = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) {
                continue; // Don't count the current cell
            }
            if (grid[i + k][j + l].alive) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create a 2D array to represent the grid
    cell_t** grid = malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid);

    // Update the grid for a few generations
    for (int generation = 0; generation < 10; generation++) {
        update_grid(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf(" alive cell at (%d, %d)\n", i, j);
            }
        }
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}