//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a grid cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} Cell;

// Function to create a 2D grid of cells
Cell** createGrid(int rows, int cols) {
    Cell** grid = calloc(rows, sizeof(Cell*));
    for (int i = 0; i < rows; i++) {
        grid[i] = calloc(cols, sizeof(Cell));
    }
    return grid;
}

// Function to update the grid based on the game of life rules
void updateGrid(Cell** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Calculate the number of alive neighbors
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    int x = i * cols + j + k;
                    int y = i * cols + j + l;
                    if (x >= 0 && x < rows * cols && y >= 0 && y < rows * cols) {
                        if (grid[x][y].alive) {
                            neighbors++;
                        }
                    }
                }
            }
            // Update the cell's state based on the number of alive neighbors
            if (grid[i][j].alive && neighbors < 2) {
                grid[i][j].alive = 0;
            } else if (!grid[i][j].alive && neighbors >= 2) {
                grid[i][j].alive = 1;
            }
        }
    }
}

// Function to print the grid
void printGrid(Cell** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a 10x10 grid of cells
    Cell** grid = createGrid(10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0);
        }
    }

    // Update the grid for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        updateGrid(grid, 10, 10);
    }

    // Print the final grid
    printGrid(grid, 10, 10);

    return 0;
}