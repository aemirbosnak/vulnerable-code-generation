//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0); // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < width && grid[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < height && grid[i][j + 1].alive) {
                neighbors++;
            }

            // Apply the rules
            if (grid[i][j].alive && neighbors == 2) {
                grid[i][j].alive = 1; // Cell is alive and has 2 alive neighbors, so it stays alive
            } else if (grid[i][j].alive && neighbors < 2) {
                grid[i][j].alive = 0; // Cell is alive but has fewer than 2 alive neighbors, so it dies
            } else if (!grid[i][j].alive && neighbors == 3) {
                grid[i][j].alive = 1; // Cell is dead but has 3 alive neighbors, so it comes to life
            }
        }
    }
}

int main() {
    // Create a 2D array to represent the game of life grid
    cell_t** grid = (cell_t**) calloc(WINDOW_WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        grid[i] = (cell_t*) calloc(WINDOW_HEIGHT, sizeof(cell_t));
    }

    // Initialize the grid
    init_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Apply the rules for a few generations
    for (int generation = 0; generation < 10; generation++) {
        apply_rules(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    // Print the final state of the grid
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        for (int j = 0; j < WINDOW_HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}