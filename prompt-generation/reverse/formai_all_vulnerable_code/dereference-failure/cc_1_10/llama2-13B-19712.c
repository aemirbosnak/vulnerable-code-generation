//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)

// Structure to represent a cell in the grid
typedef struct {
    int alive;
} cell_t;

// Function to create a 2D grid of cells
cell_t** create_grid(void) {
    int i, j;
    cell_t** grid = calloc(CELL_HEIGHT, sizeof(cell_t*));

    for (i = 0; i < CELL_HEIGHT; i++) {
        grid[i] = calloc(CELL_WIDTH, sizeof(cell_t));

        for (j = 0; j < CELL_WIDTH; j++) {
            grid[i][j] = (cell_t) { 1 }; // Initialize all cells as alive
        }
    }

    return grid;
}

// Function to print the grid
void print_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < CELL_HEIGHT; i++) {
        for (j = 0; j < CELL_WIDTH; j++) {
            if (grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to apply the Game of Life rules
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < CELL_HEIGHT; i++) {
        for (j = 0; j < CELL_WIDTH; j++) {
            // Check the cell's neighbors
            if (grid[i][j].alive && grid[i][j-1].alive && grid[i][j+1].alive && grid[i][j-2].alive) {
                // If the cell has 2 alive neighbors and is alive, it stays alive
                grid[i][j].alive = 1;
            } else if (grid[i][j].alive && !grid[i][j-1].alive && !grid[i][j+1].alive && !grid[i][j-2].alive) {
                // If the cell is alive and has no alive neighbors, it dies
                grid[i][j].alive = 0;
            } else {
                // If the cell is dead and has at least 3 alive neighbors, it comes to life
                grid[i][j].alive = 1;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));

    // Create a 2D grid of cells
    cell_t** grid = create_grid();

    // Print the initial grid
    print_grid(grid);

    // Apply the Game of Life rules for 10 generations
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
    }

    // Print the final grid
    print_grid(grid);

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}