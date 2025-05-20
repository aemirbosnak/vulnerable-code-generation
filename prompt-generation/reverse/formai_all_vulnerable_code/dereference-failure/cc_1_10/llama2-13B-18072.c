//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and update the values
void update_grid(cell_t **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < size && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < size && grid[i][j + 1].alive) {
                neighbors_alive++;
            }
            // Update the cell value based on the number of alive neighbors
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1; // Stay alive if there are 2 or 3 alive neighbors
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1; // Born if there are 3 alive neighbors
            } else {
                grid[i][j].alive = 0; // Die if there are fewer than 2 or more than 3 alive neighbors
            }
        }
    }
}

// Main function
int main() {
    int size = 10; // Size of the grid
    cell_t **grid = calloc(size, sizeof(cell_t *));
    for (int i = 0; i < size; i++) {
        grid[i] = calloc(size, sizeof(cell_t));
    }
    init_grid(grid, size);
    int generations = 100; // Number of generations to run
    for (int i = 0; i < generations; i++) {
        update_grid(grid, size);
    }
    // Print the final state of the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf(" alive");
            } else {
                printf(" dead");
            }
        }
        printf("\n");
    }
    return 0;
}