//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdlib.h>
#include <stdio.h>

#define GRID_SIZE 100
#define GENERATIONS 100

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int births; // Number of births in the current generation
    int deaths; // Number of deaths in the current generation
} grid_cell_t;

// Function to initialize the grid
void init_grid(grid_cell_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].alive = rand() % 2;
            grid[i * GRID_SIZE + j].births = 0;
            grid[i * GRID_SIZE + j].deaths = 0;
        }
    }
}

// Function to update the grid
void update_grid(grid_cell_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Calculate the number of alive neighbors
            int alive_neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1 * GRID_SIZE + j].alive) {
                alive_neighbors++;
            }
            if (i + 1 < GRID_SIZE && grid[i + 1 * GRID_SIZE + j].alive) {
                alive_neighbors++;
            }
            if (j - 1 >= 0 && grid[i * GRID_SIZE + j - 1].alive) {
                alive_neighbors++;
            }
            if (j + 1 < GRID_SIZE && grid[i * GRID_SIZE + j + 1].alive) {
                alive_neighbors++;
            }
            
            // Update the cell's state based on the number of alive neighbors
            if (alive_neighbors < 2 && grid[i * GRID_SIZE + j].alive) {
                grid[i * GRID_SIZE + j].alive = 0;
                grid[i * GRID_SIZE + j].deaths++;
            } else if (alive_neighbors >= 2 && !grid[i * GRID_SIZE + j].alive) {
                grid[i * GRID_SIZE + j].alive = 1;
                grid[i * GRID_SIZE + j].births++;
            }
        }
    }
}

// Function to print the grid
void print_grid(grid_cell_t *grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    grid_cell_t *grid;
    init_grid(grid);
    
    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    
    return 0;
}