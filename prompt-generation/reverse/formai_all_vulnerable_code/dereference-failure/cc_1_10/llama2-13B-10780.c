//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} Cell;

// Function to initialize the game of life grid
void initGrid(Cell** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Initialize each cell as randomly alive or dead
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to iterate over the grid and apply the game of life rules
void updateGrid(Cell** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors++;
            }
            // Apply the game of life rules
            if (grid[i][j].alive && neighbors >= 2 && neighbors <= 3) {
                // Cell is alive and has 2 or 3 alive neighbors, leave it alone
                grid[i][j].alive = 1;
            } else if (grid[i][j].alive && neighbors == 0) {
                // Cell is alive but has no alive neighbors, kill it
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors >= 3) {
                // Cell is dead but has 3 alive neighbors, bring it to life
                grid[i][j].alive = 1;
            }
        }
    }
}

int main() {
    // Initialize the game of life grid
    Cell** grid = malloc(WIDTH * sizeof(Cell*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(Cell));
    }
    initGrid(grid);

    // Update the grid for a specified number of generations
    for (int gen = 0; gen < 100; gen++) {
        updateGrid(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("Alive cell at (%d, %d)\n", i, j);
            } else {
                printf("Dead cell at (%d, %d)\n", i, j);
            }
        }
    }

    // Free the memory used by the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}