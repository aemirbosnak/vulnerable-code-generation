//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int random = rand() % 2;  // 0 or 1 for alive or dead
            grid[i][j].alive = random;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;  // Skip if we're not moving diagonally
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive < 2) {
                // Cell is alive and has fewer than two alive neighbors, so it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                // Cell is dead and has two or more alive neighbors, so it comes to life
                grid[i][j].alive = 1;
            }
        }
    }
}

int main() {
    // Create the grid
    cell_t** grid = (cell_t**) malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(HEIGHT * sizeof(cell_t));
    }
    init_grid(grid);

    // Main game loop
    for (int generations = 0; generations < 100; generations++) {
        update_grid(grid);
        printf("Generation %d\n", generations);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j].alive) {
                    printf("*");  // Print a living cell
                } else {
                    printf(".");  // Print a dead cell
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    // Clean up
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}