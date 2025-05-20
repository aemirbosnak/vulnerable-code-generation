//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = (cell_t**) malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = (cell_t*) malloc(height * sizeof(cell_t));
    }
    return grid;
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Calculate the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= width || j + l < 0 || j + l >= height) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }
            
            // Update the cell based on the number of alive neighbors
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive > 0) {
                grid[i][j].alive = 0; // Die
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1; // Born
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O"); // Alive cell
            } else {
                printf("."); // Dead cell
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    
    // Create a 100x100 grid of cells
    cell_t** grid = create_grid(100, 100);
    
    // Initialize the cells with a random state (alive or dead)
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
    
    // Update the grid for a few generations
    for (int generation = 0; generation < 10; generation++) {
        update_grid(grid, 100, 100);
    }
    
    // Draw the final state of the grid
    draw_grid(grid, 100, 100);
    
    return 0;
}