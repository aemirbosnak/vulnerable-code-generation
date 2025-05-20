//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors_alive++;
            }

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1; // Stay alive if there are 2 or 3 alive neighbors
            } else if (grid[i][j].alive && neighbors_alive == 0) {
                grid[i][j].alive = 0; // Die if there are no alive neighbors
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1; // Revive if there are 3 alive neighbors
            }
        }
    }
}

// Main function
int main() {
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * HEIGHT);
    }
    init_grid(grid);

    // Run the game of life for 100 steps
    for (int step = 0; step < 100; step++) {
        update_grid(grid);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O"); // Print an "O" if the cell is alive
            } else {
                printf("."); // Print a "." if the cell is dead
            }
        }
        printf("\n");
    }

    return 0;
}