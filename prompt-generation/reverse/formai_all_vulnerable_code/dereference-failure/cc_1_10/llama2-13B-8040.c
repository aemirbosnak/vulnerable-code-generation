//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20

// Structure to represent a cell in the game of life
typedef struct cell {
    int state; // 0 for dead, 1 for alive
    int next_state; // The next state of the cell (used for the next iteration)
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
        for (int j = 0; j < height; j++) {
            grid[i][j].state = (rand() % 2) == 0 ? 1 : 0; // Initialize cells with a 50% chance of being alive
            grid[i][j].next_state = grid[i][j].state; // Initialize the next state of each cell to its current state
        }
    }
    return grid;
}

// Function to print the grid
void print_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].state == 1) {
                printf("X ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to update the grid based on the rules of the game of life
void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Check the current state of the cell and its neighbors
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue; // Skip diagonals
                    }
                    if (grid[i + k][j + l].state == 1) {
                        alive_neighbors++;
                    }
                }
            }
            
            // Update the state of the cell based on the rules of the game of life
            if (alive_neighbors < 2 && grid[i][j].state == 1) {
                grid[i][j].next_state = 0; // If the cell is alive and has fewer than two alive neighbors, it dies
            } else if (alive_neighbors > 3) {
                grid[i][j].next_state = 0; // If the cell is alive and has more than three alive neighbors, it dies
            } else {
                grid[i][j].next_state = grid[i][j].state; // If the cell is alive and has two or three alive neighbors, it stays alive
            }
            grid[i][j].state = grid[i][j].next_state; // Update the current state of the cell
        }
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Create a 2D array of cells
    cell_t** grid = create_grid(WIDTH, HEIGHT);
    
    // Print the initial grid
    print_grid(grid, WIDTH, HEIGHT);
    
    // Update the grid for a specified number of generations
    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid, WIDTH, HEIGHT);
    }
    
    // Print the final grid
    print_grid(grid, WIDTH, HEIGHT);
    
    // Free the memory allocated for the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);
    
    return 0;
}