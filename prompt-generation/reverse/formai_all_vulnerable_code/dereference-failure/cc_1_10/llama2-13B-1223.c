//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to create a 2D grid of cell_t structures
cell_t** create_grid(int rows, int cols) {
    cell_t** grid = malloc(rows * sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(cell_t));
        for (int j = 0; j < cols; j++) {
            grid[i][j].alive = (i == 0 || j == 0) ? 1 : 0;  // Initialize cells at edges as alive
            grid[i][j].neighbors_alive = 0;
        }
    }
    return grid;
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Calculate the number of alive neighbors
            int neighbors_alive = 0;
            if (i > 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i < rows - 1 && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j > 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j < cols - 1 && grid[i][j + 1].alive) {
                neighbors_alive++;
            }
            
            // Update the cell's state based on the rules
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive > 0) {
                grid[i][j].alive = 0;  // If alive and has fewer than 2 alive neighbors, die
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1;  // If dead and has exactly 3 alive neighbors, come to life
            }
        }
    }
}

int main() {
    // Create a 2D grid of size 10 x 10
    cell_t** grid = create_grid(10, 10);
    
    // Initialize the grid with random values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }
    
    // Update the grid 100 times
    for (int i = 0; i < 100; i++) {
        update_grid(grid, 10, 10);
    }
    
    // Print the final state of the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
    
    return 0;
}