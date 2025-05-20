//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell
typedef struct cell {
    int alive;   // Whether the cell is alive or not
    int born;   // Whether the cell was born this iteration
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = calloc(width, sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = calloc(height, sizeof(cell_t));
    }
    return grid;
}

// Function to update the cells
void update_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].alive && (grid[i][j].born || grid[i][j-1].alive || grid[i][j+1].alive)) {
                // If so, leave the cell alive
                grid[i][j].alive = 1;
            } else {
                // If not, die
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create a 50x50 grid of cells
    cell_t** grid = create_grid(WIDTH, HEIGHT);

    // Initialize the cells with a 50% chance of being alive
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }

    // Update the grid for 100 iterations
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    // Draw the grid
    draw_grid(grid);

    // Free the memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}