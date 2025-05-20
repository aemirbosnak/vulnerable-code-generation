//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0); // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate through the grid and apply the game of life rules
void apply_rules(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check the current cell and its neighbors
            if (grid[i][j].alive) {
                int num_alive_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) continue; // Skip diagonal neighbors
                        if (grid[i + k][j + l].alive) {
                            num_alive_neighbors++;
                        }
                    }
                }
                // Apply the game of life rules
                if (num_alive_neighbors < 2 && num_alive_neighbors > 0) {
                    grid[i][j].alive = 0; // If there are too few alive neighbors, the cell dies
                } else if (num_alive_neighbors > 3) {
                    grid[i][j].alive = 0; // If there are too many alive neighbors, the cell dies
                }
            }
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the grid
    cell_t** grid = calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }
    init_grid(grid);

    // Apply the game of life rules for a few generations
    for (int generation = 0; generation < 10; generation++) {
        apply_rules(grid);
    }

    // Print the final state of the grid
    print_grid(grid);

    return 0;
}