//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid, int size) {
    int i, j, alive_neighbors;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            alive_neighbors = 0;

            // Count the number of alive neighbors
            if (grid[i][j].alive && grid[i][j-1].alive) {
                alive_neighbors++;
            }
            if (grid[i][j].alive && grid[i][j+1].alive) {
                alive_neighbors++;
            }
            if (grid[i][j].alive && grid[i-1][j].alive) {
                alive_neighbors++;
            }
            if (grid[i][j].alive && grid[i+1][j].alive) {
                alive_neighbors++;
            }

            // Update the cell's state based on the number of alive neighbors
            if (alive_neighbors >= 2 && grid[i][j].alive) {
                grid[i][j].alive = 1; // Cell stays alive if it has 2 or more alive neighbors
            } else if (alive_neighbors < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0; // Cell dies if it has less than 2 alive neighbors
            }
        }
    }
}

// Function to print the game of life grid
void print_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("O"); // Print an "O" if the cell is alive
            } else {
                printf("."); // Print a "." if the cell is dead
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a 10x10 game of life grid
    cell_t** grid = (cell_t**) malloc(10 * sizeof(cell_t*));
    for (int i = 0; i < 10; i++) {
        grid[i] = (cell_t*) malloc(10 * sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid, 10);

    // Run the game of life for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid, 10);
    }

    // Print the final state of the grid
    print_grid(grid, 10);

    // Free the memory
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}