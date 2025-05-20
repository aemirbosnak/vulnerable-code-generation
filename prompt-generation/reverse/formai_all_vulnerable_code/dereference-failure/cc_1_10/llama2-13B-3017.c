//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct cell {
    int x;
    int y;
    int state; // 0 for dead, 1 for alive
} cell_t;

// Function to generate a random initial state for the game
void init_state(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Set a random state for each cell
            grid[i][j].state = rand() % 2;
        }
    }
}

// Function to update the state of each cell based on its neighbors
void update_state(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Calculate the number of alive neighbors for this cell
            int alive_neighbors = 0;
            if (grid[i][j].state) { // Cell is alive
                if (i > 0 && grid[i][j].state) alive_neighbors++; // Check left neighbor
                if (i + 1 < width && grid[i + 1][j].state) alive_neighbors++; // Check right neighbor
                if (j > 0 && grid[i][j - 1].state) alive_neighbors++; // Check top neighbor
                if (j + 1 < height && grid[i][j + 1].state) alive_neighbors++; // Check bottom neighbor
            }

            // Update the state of the cell based on its neighbors
            if (alive_neighbors < 2 && grid[i][j].state) {
                grid[i][j].state = 0; // If less than two alive neighbors, cell dies
            } else if (alive_neighbors > 3) {
                grid[i][j].state = 0; // If more than three alive neighbors, cell dies
            } else {
                grid[i][j].state = 1; // If two or three alive neighbors, cell stays alive
            }
        }
    }
}

int main() {
    // Create a 2D array to represent the game board
    cell_t **grid = (cell_t **) calloc(WIDTH, sizeof(cell_t *));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t *) calloc(HEIGHT, sizeof(cell_t));
    }

    // Initialize the game state with a random initial state
    init_state(grid, WIDTH, HEIGHT);

    // Update the game state for a specified number of generations
    for (int gen = 0; gen < 100; gen++) {
        update_state(grid, WIDTH, HEIGHT);
    }

    // Print the final state of the game
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].state) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }

    return 0;
}