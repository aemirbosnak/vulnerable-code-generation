//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0);  // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate through the grid and update cell states
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Calculate the number of alive neighbors for the current cell
            int neighbors_alive = count_alive_neighbors(grid, i, j);

            // Update the cell's state based on the number of alive neighbors
            if (grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1;  // If the cell is alive and has 2 or more alive neighbors, keep it alive
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1;  // If the cell is dead and has 3 alive neighbors, bring it to life
            } else {
                grid[i][j].alive = 0;  // Otherwise, kill the cell
            }
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

// Function to count the number of alive neighbors for a given cell
int count_alive_neighbors(cell_t** grid, int i, int j) {
    int count = 0;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0) continue;  // Don't count the current cell
            if (grid[i + k][j + l].alive) count++;
        }
    }

    return count;
}

int main() {
    cell_t** grid = (cell_t**)calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*)calloc(HEIGHT, sizeof(cell_t));
    }

    init_grid(grid);

    for (int gen = 0; gen < 100; gen++) {
        update_grid(grid);

        // Print the current state of the grid
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j].alive) {
                    printf("|%d|", grid[i][j].alive);
                } else {
                    printf("|   |");
                }
            }
            printf("\n");
        }
    }

    return 0;
}