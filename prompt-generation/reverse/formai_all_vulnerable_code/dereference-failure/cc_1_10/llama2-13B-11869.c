//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the grid
typedef struct {
    int x; // X position of the cell
    int y; // Y position of the cell
    int size; // Size of the cell
} Cell;

// Function to create a 2D array to represent the grid
Cell** createGrid(int width, int height) {
    Cell** grid = malloc(width * sizeof(Cell*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(Cell));
    }
    return grid;
}

// Function to initialize the grid with random data
void initializeGrid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Set the cell's size and position randomly
            grid[i][j].x = rand() % (width - 1);
            grid[i][j].y = rand() % (height - 1);
            grid[i][j].size = rand() % 3 + 1;
        }
    }
}

// Function to draw the grid
void drawGrid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("{%d, %d, %d} ", grid[i][j].x, grid[i][j].y, grid[i][j].size);
        }
        printf("\n");
    }
}

// Function to update the grid based on the Game of Life rules
void updateGrid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Check if the cell is alive (has a non-zero size)
            if (grid[i][j].size > 0) {
                // Check if the cell is surrounded by two or three alive cells
                int countAlive = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) {
                            continue;
                        }
                        if (grid[i + k][j + l].size > 0) {
                            countAlive++;
                        }
                    }
                }
                // If the cell is surrounded by two or three alive cells, leave it alone
                if (countAlive >= 2 && countAlive <= 3) {
                    grid[i][j].size++; // Keep the cell alive
                } else {
                    grid[i][j].size = 0; // Make the cell dead
                }
            }
        }
    }
}

int main() {
    // Create a 2D array to represent the grid
    Cell** grid = createGrid(10, 10);

    // Initialize the grid with random data
    initializeGrid(grid, 10, 10);

    // Draw the grid
    drawGrid(grid, 10, 10);

    // Update the grid based on the Game of Life rules
    updateGrid(grid, 10, 10);

    // Free the memory used by the grid
    free(grid);

    return 0;
}