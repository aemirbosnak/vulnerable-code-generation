//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} Cell;

// Function to create a 2D array of cells
Cell** create_grid(int width, int height) {
    Cell** grid = calloc(width, sizeof(Cell*));
    for (int i = 0; i < width; i++) {
        grid[i] = calloc(height, sizeof(Cell));
    }
    return grid;
}

// Function to update the game of life
void update_grid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Check the alive status of the cell and its neighbors
            if (grid[i][j].alive && (grid[i][j].neighbors < 2 || grid[i][j].neighbors > 3)) {
                // If the cell is alive and has less than 2 or more than 3 alive neighbors, it dies
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && (grid[i][j].neighbors == 2 || grid[i][j].neighbors == 3)) {
                // If the cell is dead and has exactly 2 or 3 alive neighbors, it comes to life
                grid[i][j].alive = 1;
            }
            // Update the number of alive neighbors for the current cell
            grid[i][j].neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
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

// Function to draw the game of life
void draw_grid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int width = 500;
    int height = 500;
    Cell** grid = create_grid(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Initialize the cell with a random alive status
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
    for (int i = 0; i < 100; i++) {
        update_grid(grid, width, height);
        draw_grid(grid, width, height);
        printf("Generation %d\n", i + 1);
    }
    return 0;
}