//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and apply the game of life rules
void apply_rules(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= WIDTH || j + l < 0 || j + l >= HEIGHT) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1;  // Stay alive if there are 2 or 3 alive neighbors
            } else if (grid[i][j].alive && neighbors_alive == 0) {
                grid[i][j].alive = 0;  // Die if there are no alive neighbors
            } else {
                grid[i][j].alive = 0;  // Stay alive if there are 4 or more alive neighbors
            }
        }
    }
}

// Main function
int main() {
    cell_t** grid = (cell_t**) calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) calloc(HEIGHT, sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid);

    // Apply the game of life rules for 100 generations
    for (int i = 0; i < 100; i++) {
        apply_rules(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}