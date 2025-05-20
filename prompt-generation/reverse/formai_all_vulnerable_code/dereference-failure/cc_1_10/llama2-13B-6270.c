//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initalize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check the current cell's alive status and its neighbors
            if (grid[i][j].alive) {
                // Count the number of alive neighbors
                grid[i][j].neighbors_alive = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) {
                            continue;  // Skip if k or l is 0
                        }
                        if (grid[i + k][j + l].alive) {
                            grid[i][j].neighbors_alive++;
                        }
                    }
                }
                // Apply the game of life rules
                if (grid[i][j].neighbors_alive < 2 || grid[i][j].neighbors_alive > 3) {
                    grid[i][j].alive = 0;  // If there are too few or too many alive neighbors, the cell dies
                } else if (grid[i][j].neighbors_alive == 2) {
                    grid[i][j].alive = 1;  // If there are exactly 2 alive neighbors, the cell stays alive
                } else {
                    grid[i][j].alive = 0;  // If there are more than 2 alive neighbors, the cell dies
                }
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O");  // Represent alive cells with 'O'
            } else {
                printf(".");  // Represent dead cells with '.'
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }
    init_grid(grid);
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", i + 1);
    }
    return 0;
}