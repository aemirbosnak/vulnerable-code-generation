//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

// Structure to represent a cell
typedef struct {
    int alive;
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
    }
    return grid;
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j].alive == grid[i][j + 1].alive && grid[i][j].alive == grid[i][j - 1].alive) ||
                    (grid[i][j].alive && grid[i][j + 1].alive && grid[i][j - 1].alive)) {
                grid[i][j].alive = 1;
            }
            // If the cell is dead and has exactly three alive neighbors, bring it to life
            else if (!grid[i][j].alive && grid[i][j + 1].alive && grid[i][j - 1].alive && grid[i][j + 2].alive) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has less than two alive neighbors, kill it
            else if (grid[i][j].alive && (grid[i][j + 1].alive || grid[i][j - 1].alive) < 2) {
                grid[i][j].alive = 0;
            }
            // If the cell is dead and has more than three alive neighbors, bring it to life
            else if (!grid[i][j].alive && grid[i][j + 1].alive && grid[i][j - 1].alive && grid[i][j + 2].alive > 3) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has exactly two alive neighbors, do nothing
            else {
                grid[i][j].alive = 1;
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
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
    srand(time(NULL));

    // Create a 10x10 grid of cells
    cell_t** grid = create_grid(10, 10);

    // Initialize the grid with random alive cells
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (rand() % 2) {
                grid[i][j].alive = 1;
            }
        }
    }

    // Update the grid for 100 generations
    for (int i = 0; i < 100; i++) {
        update_grid(grid, 10, 10);
    }

    // Draw the final grid
    draw_grid(grid, 10, 10);

    return 0;
}