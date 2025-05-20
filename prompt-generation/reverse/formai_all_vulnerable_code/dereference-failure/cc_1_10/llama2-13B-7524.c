//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0); // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and update the cells
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Update the cell's state based on its neighbors
            if (grid[i][j].alive && (grid[i][j].neighbors_alive < 2)) {
                // If the cell is alive and has fewer than 2 alive neighbors, it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && (grid[i][j].neighbors_alive >= 2)) {
                // If the cell is dead and has at least 2 alive neighbors, it comes to life
                grid[i][j].alive = 1;
            }

            // Update the cell's number of alive neighbors
            grid[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors_alive++;
                    }
                }
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = (cell_t**)malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*)malloc(sizeof(cell_t) * HEIGHT);
    }

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
    }

    free(grid);
    return 0;
}