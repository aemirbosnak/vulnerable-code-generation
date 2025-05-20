//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int born;   // Whether the cell was born in the current generation
} cell_t;

// Function to generate a random initial grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].born = 0;
        }
    }
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two alive neighbors
            if (grid[i][j].alive &&
                    (grid[i][j-1].alive && grid[i][j+1].alive) &&
                    (grid[i-1][j].alive && grid[i+1][j].alive)) {
                // If so, leave the cell alive in the next generation
                grid[i][j].born = 0;
            } else {
                // If not, check if the cell is alive and has three alive neighbors
                if (grid[i][j].alive &&
                        (grid[i][j-1].alive && grid[i][j+1].alive &&
                         grid[i-1][j].alive && grid[i+1][j].alive)) {
                    // If so, leave the cell alive in the next generation
                    grid[i][j].born = 0;
                } else {
                    // If the cell is not alive, set it to dead in the next generation
                    grid[i][j].born = 1;
                }
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
        sleep(1); // Add some randomness to the simulation
    }

    free(grid);
    return 0;
}