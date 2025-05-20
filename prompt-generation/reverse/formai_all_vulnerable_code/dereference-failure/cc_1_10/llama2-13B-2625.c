//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int born;   // Whether the cell was born in the current generation
} Cell;

// Function to initialize the grid with random values
void initGrid(Cell *grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i * HEIGHT + j].alive = (rand() % 2) ? 1 : 0;
            grid[i * HEIGHT + j].born = 0;
        }
    }
}

// Function to apply the game of life rules
void applyRules(Cell *grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i * HEIGHT + j].alive && (grid[i * HEIGHT + j - 1].alive || grid[i * HEIGHT + j + 1].alive || grid[i * HEIGHT + j - HEIGHT].alive)) {
                grid[i * HEIGHT + j].alive = 1;
            }
            // If the cell is alive and has less than two alive neighbors, die (underpopulation)
            else if (grid[i * HEIGHT + j].alive && !(grid[i * HEIGHT + j - 1].alive && grid[i * HEIGHT + j + 1].alive)) {
                grid[i * HEIGHT + j].alive = 0;
            }
            // If the cell is dead and has exactly three alive neighbors, come to life (reproduction)
            else if (!grid[i * HEIGHT + j].alive && (grid[i * HEIGHT + j - 1].alive && grid[i * HEIGHT + j + 1].alive && grid[i * HEIGHT + j - HEIGHT].alive)) {
                grid[i * HEIGHT + j].alive = 1;
            }
        }
    }
}

int main() {
    // Initialize the grid
    Cell *grid = malloc(WIDTH * HEIGHT * sizeof(Cell));
    initGrid(grid);

    // Run the game of life for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        applyRules(grid);
        printf("Generation %d\n", gen);
    }

    // Free the memory
    free(grid);
    return 0;
}