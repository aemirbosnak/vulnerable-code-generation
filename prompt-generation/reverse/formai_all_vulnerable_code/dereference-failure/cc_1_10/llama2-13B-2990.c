//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

// Structure to represent a grid cell
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0); // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Calculate the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors_alive++;
            }

            // Update the cell's state based on the number of alive neighbors
            if (neighbors_alive < 2) {
                grid[i][j].alive = 0; // If there are fewer than two alive neighbors, the cell dies
            } else if (neighbors_alive > 3) {
                grid[i][j].alive = 0; // If there are more than three alive neighbors, the cell dies
            } else {
                grid[i][j].alive = 1; // If there are exactly two alive neighbors, the cell stays alive
            }
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

int main() {
    cell_t** grid = calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }

    init_grid(grid);

    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
        printf("Generation %d\n", generation);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j].alive) {
                    printf("Alive cell at (%d, %d)\n", i, j);
                }
            }
        }
    }

    return 0;
}