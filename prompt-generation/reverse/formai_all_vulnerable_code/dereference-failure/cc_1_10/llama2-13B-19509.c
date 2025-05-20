//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CELL_SIZE 10
#define WINDOW_SIZE (CELL_SIZE * CELL_SIZE)

// Structure to represent a cell in the game of life
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int age;   // The age of the cell (used for simulating the game)
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int rows, int cols) {
    cell_t** grid = malloc(rows * sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(cell_t));
        for (int j = 0; j < cols; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].age = 0;
        }
    }
    return grid;
}

// Function to print the grid
void print_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Check the current cell's neighbors
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        alive_neighbors++;
                    }
                }
            }
            
            // Update the cell's state based on the number of alive neighbors
            if (alive_neighbors < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0; // Underpopulation
            } else if (alive_neighbors > 3) {
                grid[i][j].alive = 0; // Overpopulation
            } else {
                grid[i][j].alive = grid[i][j].alive; // Stay the same
            }
            grid[i][j].age++; // Increment the cell's age
        }
    }
}

int main() {
    // Create a 10x10 grid of cells
    cell_t** grid = create_grid(10, 10);
    
    // Print the initial grid
    print_grid(grid, 10, 10);
    
    // Update the grid for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid, 10, 10);
    }
    
    // Print the final grid
    print_grid(grid, 10, 10);
    
    // Free the memory allocated for the grid
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}