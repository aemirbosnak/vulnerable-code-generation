//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int rows, int cols) {
    cell_t** grid = calloc(rows, sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid[i] = calloc(cols, sizeof(cell_t));
    }
    return grid;
}

// Function to update the game of life
void update_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Update the cell based on its neighbors
            if (grid[i][j].alive) {
                int neighbors = 0;
                if (i - 1 >= 0 && grid[i - 1][j].alive) neighbors++;
                if (i + 1 < rows && grid[i + 1][j].alive) neighbors++;
                if (j - 1 >= 0 && grid[i][j - 1].alive) neighbors++;
                if (j + 1 < cols && grid[i][j + 1].alive) neighbors++;
                if (neighbors == 2 || neighbors == 3) {
                    grid[i][j].alive = 1; // alive cell stays alive
                } else if (neighbors == 0 || neighbors == 4) {
                    grid[i][j].alive = 0; // dead cell becomes alive
                }
            }
        }
    }
}

// Function to draw the game of life
void draw_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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
    srand(time(NULL)); // Initialize random number generator

    // Create a 10x10 grid of cells
    cell_t** grid = create_grid(10, 10);

    // Initialize the cells with a random state
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }

    // Update the grid for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        update_grid(grid, 10, 10);
    }

    // Draw the final state of the grid
    draw_grid(grid, 10, 10);

    return 0;
}