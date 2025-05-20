//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to create the grid
void create_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;  // Initialize cells randomly
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and apply the Game of Life rules
void apply_rules(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;  // Skip diagonals
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the rules
            if (grid[i][j].alive && neighbors_alive < 2 && neighbors_alive > 0) {
                grid[i][j].alive = 0;  // Death
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1;  // Life
            }
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

// Main function
int main() {
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * HEIGHT);
    }

    create_grid(grid);

    // Iterate over the grid 50 times
    for (int i = 0; i < 50; i++) {
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