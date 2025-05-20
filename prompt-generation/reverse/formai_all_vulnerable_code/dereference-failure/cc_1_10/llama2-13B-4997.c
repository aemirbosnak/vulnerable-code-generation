//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate through the grid and update the state of each cell
void update_grid(cell_t** grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || j + l < 0 || i + k >= width || j + l >= height) continue;
                    if (grid[i + k][j + l].alive) neighbors_alive++;
                }
            }
            
            // Update the cell's state based on the number of alive neighbors
            if (grid[i][j].alive && neighbors_alive < 2) {
                grid[i][j].alive = 0; // Die of loneliness
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1; // Reproduce
            }
            grid[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the grid
    cell_t** grid = malloc(sizeof(cell_t*) * 10);
    for (int i = 0; i < 10; i++) {
        grid[i] = malloc(sizeof(cell_t) * 10);
    }
    init_grid(grid, 10, 10);

    // Update the grid for a few generations
    for (int generation = 0; generation < 10; generation++) {
        update_grid(grid, 10, 10);
    }

    // Draw the final grid
    draw_grid(grid, 10, 10);

    return 0;
}