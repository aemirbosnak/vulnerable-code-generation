//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and update the state of each cell
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Update the cell's state based on its neighbors
            if (grid[i][j].alive && (grid[i][j - 1].alive || grid[i][j + 1].alive || grid[i - 1][j].alive || grid[i + 1][j].alive)) {
                grid[i][j].alive = 1 - grid[i][j].alive;  // Flip the cell's state if it has alive neighbors
            }
            // Increment the number of alive neighbors for the cell
            grid[i][j].neighbors_alive += (grid[i][j - 1].alive || grid[i][j + 1].alive || grid[i - 1][j].alive || grid[i + 1][j].alive);
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the grid
    cell_t** grid = (cell_t**) malloc(WIDTH * HEIGHT * sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(HEIGHT * sizeof(cell_t));
    }
    init_grid(grid);

    // Update the grid for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        update_grid(grid);
    }

    // Draw the final state of the grid
    draw_grid(grid);

    // Free the memory used by the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}