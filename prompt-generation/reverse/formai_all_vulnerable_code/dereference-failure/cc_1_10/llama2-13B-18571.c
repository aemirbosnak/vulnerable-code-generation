//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 100

// Define the cell states
typedef enum {
    ALIVE,
    DEAD
} cell_state;

// Define the game of life rules
void update_grid(cell_state** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Check the current cell state
            cell_state current_state = grid[i][j];

            // Apply the game of life rules
            if (current_state == ALIVE) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                if (grid[i][j - 1] == ALIVE && grid[i][j + 1] == ALIVE && grid[i + 1][j] == ALIVE) {
                    grid[i][j] = ALIVE;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (grid[i][j - 1] == ALIVE && grid[i][j + 1] == ALIVE) {
                        grid[i][j] = DEAD;
                    }
                }
            } else {
                // If the cell is dead and has three alive neighbors, come alive
                if (grid[i][j - 1] == ALIVE && grid[i][j + 1] == ALIVE && grid[i + 1][j] == ALIVE) {
                    grid[i][j] = ALIVE;
                }
            }
        }
    }
}

int main() {
    // Initialize the grid with random values
    cell_state** grid = (cell_state**) malloc(GRID_SIZE * sizeof(cell_state*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (cell_state*) malloc(GRID_SIZE * sizeof(cell_state));
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = (random() % 2) ? ALIVE : DEAD;
        }
    }

    // Run the game of life for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    // Print the final grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}