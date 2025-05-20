//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the Game of Life rules
void update_grid(cell_t** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the Game of Life rules
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1;  // alive cell stays alive
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1;  // dead cell becomes alive
            } else {
                grid[i][j].alive = 0;  // all other cells die
            }
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

// Main function
int main() {
    int size = 100;  // Size of the grid
    cell_t** grid = malloc(size * size * sizeof(cell_t));  // Allocate memory for the grid
    init_grid(grid, size);

    int generations = 10;  // Number of generations to run the game
    for (int i = 0; i < generations; i++) {
        update_grid(grid, size);
    }

    // Print the final state of the grid
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    free(grid);  // Free memory for the grid
    return 0;
}