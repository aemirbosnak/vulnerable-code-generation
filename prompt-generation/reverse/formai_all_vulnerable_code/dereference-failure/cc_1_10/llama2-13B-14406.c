//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0); // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors = 0;
        }
    }
    return grid;
}

// Function to iterate over the grid and update cell states
void update_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Update cell state based on number of alive neighbors
            if (grid[i][j].alive && grid[i][j].neighbors < 2) {
                // Cell is alive and has fewer than 2 alive neighbors, so it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && grid[i][j].neighbors >= 2) {
                // Cell is dead and has at least 2 alive neighbors, so it comes to life
                grid[i][j].alive = 1;
            } else {
                // Cell is already alive or dead, so do nothing
            }
            grid[i][j].neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || j + l < 0 || i + k >= WIDTH || j + l >= HEIGHT) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        grid[i][j].neighbors++;
                    }
                }
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create a 100x100 grid of cells
    cell_t** grid = create_grid(WIDTH, HEIGHT);

    // Run the game of life for 100 generations
    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid);
        printf("Generation %d:", generation);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                if (grid[i][j].alive) {
                    printf(" O ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    // Free the grid memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}