//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = calloc(width, sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = calloc(height, sizeof(cell_t));
    }
    return grid;
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // If the cell is alive and has 2 or 3 alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j].neighbors_alive >= 2 && grid[i][j].neighbors_alive <= 3)) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has less than 2 alive neighbors, die
            else if (grid[i][j].alive && grid[i][j].neighbors_alive < 2) {
                grid[i][j].alive = 0;
            }
            // If the cell is dead and has exactly 3 alive neighbors, come to life
            else if (!grid[i][j].alive && grid[i][j].neighbors_alive == 3) {
                grid[i][j].alive = 1;
            }
            // Otherwise, do nothing
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
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
    // Create a 100x100 grid of cells
    cell_t** grid = create_grid(100, 100);

    // Initialize all cells as dead
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            grid[i][j].alive = 0;
        }
    }

    // Run the game of life for 100 steps
    for (int step = 0; step < 100; step++) {
        update_grid(grid, 100, 100);
    }

    // Draw the final state of the grid
    draw_grid(grid, 100, 100);

    return 0;
}