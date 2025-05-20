//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to create a 2D grid of cells
cell_t** create_grid(int size) {
    cell_t** grid = malloc(size * size * sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(cell_t));
        for (int j = 0; j < size; j++) {
            grid[i][j] = (cell_t){0, 0};
        }
    }
    return grid;
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculate the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || j + l < 0 || i + k >= size || j + l >= size) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }
            
            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive > 0) {
                grid[i][j].alive = 0;  // Die of loneliness
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1;  // Reproduction
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
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
    // Create a 10x10 grid of cells
    cell_t** grid = create_grid(10);

    // Initialize all cells to be alive
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].alive = 1;
        }
    }

    // Update the grid 10 times
    for (int i = 0; i < 10; i++) {
        update_grid(grid, 10);
    }

    // Draw the final grid
    draw_grid(grid, 10);

    // Free the memory used by the grid
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}