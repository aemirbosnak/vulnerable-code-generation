//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Initialize each cell as randomly alive or dead
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= size || j + l < 0 || j + l >= size) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the rules based on the number of alive neighbors
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive > 0) {
                // Cell is alive and has fewer than 2 alive neighbors, so it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                // Cell is dead and has at least 2 alive neighbors, so it comes to life
                grid[i][j].alive = 1;
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("O");  // Represent alive cells as "O"
            } else {
                printf(" ");  // Represent dead cells as " "
            }
        }
        printf("\n");
    }
}

int main() {
    int size = WINDOW_WIDTH * WINDOW_HEIGHT;
    cell_t** grid = malloc(size * sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid, size);

    // Apply the game of life rules for a few generations
    for (int generation = 0; generation < 10; generation++) {
        apply_rules(grid, size);
    }

    // Draw the final state of the grid
    draw_grid(grid, size);

    // Free the memory allocated for the grid
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}