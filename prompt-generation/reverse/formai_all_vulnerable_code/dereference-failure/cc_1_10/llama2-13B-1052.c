//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0);  // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the Game of Life rules
void apply_rules(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;  // Skip diagonals
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors_alive++;
                    }
                }
            }

            // Apply the rules
            if (grid[i][j].alive && grid[i][j].neighbors_alive >= 2 && grid[i][j].neighbors_alive <= 3) {
                // Cell is alive and has 2-3 alive neighbors, leave it alive
                grid[i][j].alive = 1;
            } else if (grid[i][j].alive && grid[i][j].neighbors_alive == 0) {
                // Cell is alive but has no alive neighbors, kill it
                grid[i][j].alive = 0;
            } else if (grid[i][j].alive && grid[i][j].neighbors_alive > 3) {
                // Cell is alive but has too many alive neighbors, kill it
                grid[i][j].alive = 0;
            } else {
                // Cell is dead or has no alive neighbors, leave it dead
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to display the grid
void display_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("O");  // Alive cell
            } else {
                printf(".");  // Dead cell
            }
        }
        printf("\n");
    }
}

int main() {
    int size = 10;  // Size of the grid
    cell_t** grid = malloc(size * size * sizeof(cell_t));  // Allocate memory for the grid

    init_grid(grid, size);  // Initialize the grid

    for (int i = 0; i < 100; i++) {
        apply_rules(grid, size);  // Apply the Game of Life rules
        display_grid(grid, size);  // Display the updated grid
        sleep(1);  // Pause for 1 second
    }

    free(grid);  // Free the memory for the grid

    return 0;
}