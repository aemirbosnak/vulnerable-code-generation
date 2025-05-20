//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the grid size
#define GRID_SIZE 10

// Define the number of generations to run
#define GENERATIONS 50

// Define the initial population
int init_grid[GRID_SIZE][GRID_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Define the game of life rules
void update_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Check for alive neighbors
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    if (grid[i + k][j + l] == 1) alive_neighbors++;
                }
            }

            // Update the cell
            if (grid[i][j] == 1 && alive_neighbors < 2 && alive_neighbors > 0) {
                grid[i][j] = 1; // alive
            } else if (grid[i][j] == 1 && alive_neighbors == 2) {
                grid[i][j] = 0; // dead
            } else if (grid[i][j] == 0 && alive_neighbors == 3) {
                grid[i][j] = 1; // alive
            } else {
                grid[i][j] = 0; // dead
            }
        }
    }
}

int main() {
    // Run the game of life for 50 generations
    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(init_grid);
    }

    // Print the final grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", init_grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}