//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive; // Whether the cell is alive or not
    int born;  // Whether the cell was born this generation
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].born = 0;
        }
    }
}

// Function to update the grid based on the rules of life
void update_grid(cell_t **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j-1].alive || grid[i][j+1].alive || grid[i-1][j].alive || grid[i+1][j].alive)) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has less than two alive neighbors, die (underpopulation)
            else if (grid[i][j].alive && !(grid[i][j-1].alive || grid[i][j+1].alive || grid[i-1][j].alive || grid[i+1][j].alive)) {
                grid[i][j].alive = 0;
            }
            // If the cell is dead and has exactly three alive neighbors, come to life (overpopulation)
            else if (!grid[i][j].alive && grid[i][j-1].alive && grid[i][j+1].alive && grid[i-1][j].alive && grid[i+1][j].alive) {
                grid[i][j].alive = 1;
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    int size = 100; // Size of the grid
    cell_t **grid = calloc(size, sizeof(cell_t)); // Allocate memory for the grid
    init_grid(grid, size); // Initialize the grid with random values

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < 1000; i++) {
        update_grid(grid, size); // Update the grid based on the rules of life
        print_grid(grid, size); // Print the current state of the grid
    }

    return 0;
}