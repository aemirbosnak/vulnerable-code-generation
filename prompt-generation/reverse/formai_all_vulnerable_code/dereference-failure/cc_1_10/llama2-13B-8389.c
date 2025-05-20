//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int x; // position x
    int y; // position y
    int alive; // whether the cell is alive or not
} cell_t;

// Function to generate a random initial state for the grid
void init_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

// Function to iterate through the grid and apply the game of life rules
void apply_rules(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].alive && (grid[i][j - 1].alive || grid[i][j + 1].alive || grid[i - 1][j].alive || grid[i + 1][j].alive)) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                grid[i][j].alive = 1;
            } else {
                // If the cell is alive and has less than two alive neighbors, die
                grid[i][j].alive = 0;
            }
        }
    }
}

int main() {
    cell_t **grid;
    init_grid(&grid);

    // Loop through the grid and apply the game of life rules for 100 generations
    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }

    return 0;
}