//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules
void update_grid(cell_t **grid) {
    int i, j, neighbors_alive;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) neighbors_alive++;
                }
            }

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive < 2) {
                // If the cell is alive and has less than two alive neighbors, it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                // If the cell is dead and has two or more alive neighbors, it comes to life
                grid[i][j].alive = 1;
            }
        }
    }
}

// Main function
int main() {
    cell_t **grid = (cell_t **)malloc(WIDTH * HEIGHT * sizeof(cell_t *));
    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        // Print the current state of the grid
        for (int j = 0; j < HEIGHT; j++) {
            for (int i = 0; i < WIDTH; i++) {
                if (grid[i][j].alive) printf("O ");
                else printf(" . ");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}