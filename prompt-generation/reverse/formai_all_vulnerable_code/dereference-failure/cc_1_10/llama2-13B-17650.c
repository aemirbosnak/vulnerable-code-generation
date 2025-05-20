//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Structure to represent a cell in the grid
typedef struct {
    int alive; // Whether the cell is alive or dead
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to create a 2D grid of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
    return grid;
}

// Function to update the state of a cell
void update_cell(cell_t** grid, int x, int y) {
    // Calculate the number of alive neighbors
    int neighbors_alive = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 || j == 0 || x + i < 0 || x + i >= WIDTH || y + j < 0 || y + j >= HEIGHT) {
                continue;
            }
            if (grid[x + i][y + j].alive) {
                neighbors_alive++;
            }
        }
    }

    // Update the cell's state based on its neighbors
    if (grid[x][y].alive && neighbors_alive < 2 && neighbors_alive > 0) {
        // Cell is alive and has fewer than 2 alive neighbors, so it dies
        grid[x][y].alive = 0;
    } else if (!grid[x][y].alive && neighbors_alive >= 2) {
        // Cell is dead and has at least 2 alive neighbors, so it comes to life
        grid[x][y].alive = 1;
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf(" "); // Draw a white border around alive cells
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    cell_t** grid = create_grid(WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Initialize cells with a 50% chance of being alive
            if (rand() % 2) {
                grid[i][j].alive = 1;
            }
        }
    }

    // Simulate the game for 100 iterations
    for (int i = 0; i < 100; i++) {
        for (int x = 0; x < WIDTH; x++) {
            for (int y = 0; y < HEIGHT; y++) {
                update_cell(grid, x, y);
            }
        }
        draw_grid(grid);
        printf("Iteration %d\n", i + 1);
    }

    return 0;
}