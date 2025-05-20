//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1); // Initial state based on position
            grid[i][j].neighbors_alive = 0;
        }
    }
    return grid;
}

// Function to iterate over the grid and apply the game of life rules
void apply_rules(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue; // Don't count the current cell
                    if (grid[i + k][j + l].alive) neighbors_alive++;
                }
            }
            
            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive > 0) {
                grid[i][j].alive = 0; // Die of loneliness
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1; // Born from neighbors
            }
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Create the grid
    cell_t** grid = create_grid(WIDTH, HEIGHT);
    
    // Apply the game of life rules for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        apply_rules(grid);
    }
    
    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
    
    return 0;
}