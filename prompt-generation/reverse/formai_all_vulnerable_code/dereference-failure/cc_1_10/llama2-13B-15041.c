//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of living neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to iterate over the grid and update the values
void update_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check the alive and neighbors of the current cell
            if (grid[i][j].alive) {
                // Increment the number of living neighbors
                grid[i][j].neighbors += (i + j) % WIDTH;
            }
            // Check if the cell is alive and has 2 or 3 living neighbors
            if (grid[i][j].alive && (grid[i][j].neighbors == 2 || grid[i][j].neighbors == 3)) {
                // Keep the cell alive in the next generation
                grid[i][j].alive = 1;
            } else {
                // If the cell is not alive and has 3 living neighbors, make it alive
                if (!grid[i][j].alive && grid[i][j].neighbors == 3) {
                    grid[i][j].alive = 1;
                } else {
                    // Otherwise, make the cell dead
                    grid[i][j].alive = 0;
                }
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t **grid;
    srand(time(NULL));
    init_grid(&grid);
    for (int gen = 0; gen < 10; gen++) {
        update_grid(grid);
        print_grid(grid);
    }
    return 0;
}