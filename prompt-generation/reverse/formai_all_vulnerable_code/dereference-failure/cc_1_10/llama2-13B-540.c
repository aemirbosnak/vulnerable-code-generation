//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int next;   // The next state of the cell (0 or 1)
} Cell;

// Function to create a 2D array of cells
Cell** createGrid(int width, int height) {
    Cell** grid = malloc(width * sizeof(Cell*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(Cell));
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;  // Initialize cells with random alive state
            grid[i][j].next = grid[i][j].alive;      // Initialize next state as current state
        }
    }
    return grid;
}

// Function to update the game of life
void updateGrid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j].next == 1 || grid[i][j].next == 1 && grid[i][j-1].alive && grid[i][j+1].alive)) {
                grid[i][j].next = 1;
            } else {
                // If the cell is alive and has less than two alive neighbors, die
                if (grid[i][j].alive && grid[i][j].next == 1 && !(grid[i][j-1].alive || grid[i][j+1].alive)) {
                    grid[i][j].next = 0;
                }
                // If the cell is dead and has exactly three alive neighbors, come to life
                else if (!grid[i][j].alive && grid[i][j-1].alive && grid[i][j+1].alive && grid[i][j-1].next == 1 && grid[i][j+1].next == 1) {
                    grid[i][j].next = 1;
                }
                // Otherwise, keep the cell dead
                else {
                    grid[i][j].next = 0;
                }
            }
        }
    }
}

int main() {
    // Create a 100x100 grid of cells
    Cell** grid = createGrid(WIDTH, HEIGHT);

    // Set the initial state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }

    // Update the grid for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        updateGrid(grid, WIDTH, HEIGHT);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O");  // Print an "O" for alive cells
            } else {
                printf(".");  // Print a "." for dead cells
            }
        }
        printf("\n");
    }

    // Free the memory used by the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}