//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0);  // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules to a single generation
void apply_rules(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Count the number of alive neighbors
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors_alive++;
                    }
                }
            }

            // Apply the game of life rules
            if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                grid[i][j].alive = 0;  // If the cell is alive and has fewer than two alive neighbors, it dies
            } else if (!grid[i][j].alive && grid[i][j].neighbors_alive >= 2) {
                grid[i][j].alive = 1;  // If the cell is dead and has two or more alive neighbors, it comes to life
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O ");  // Print an "O" if the cell is alive
            } else {
                printf(" . ");  // Print a "." if the cell is dead
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the game of life grid
    cell_t** grid = (cell_t**) malloc(WIDTH * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(HEIGHT * sizeof(cell_t));
    }
    init_grid(grid, WIDTH, HEIGHT);

    // Run the game of life for 100 generations
    for (int i = 0; i < 100; i++) {
        apply_rules(grid, WIDTH, HEIGHT);
    }

    // Draw the final state of the game of life grid
    draw_grid(grid, WIDTH, HEIGHT);

    return 0;
}