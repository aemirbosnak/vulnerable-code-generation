//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024

// Structure to represent a cell in the grid
typedef struct {
    int x;
    int y;
    int state; // 0 for dead, 1 for alive
} Cell;

// Function to create a 2D array of cells
Cell** createGrid(int width, int height) {
    Cell** grid = malloc(width * sizeof(Cell*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(Cell));
    }
    return grid;
}

// Function to update the grid based on the current state of the cells
void updateGrid(Cell** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // If the cell is alive and has two or three alive neighbors, keep it alive
            if (grid[i][j].state == 1 && countNeighbors(grid, i, j, width, height) >= 2 && countNeighbors(grid, i, j, width, height) <= 3) {
                grid[i][j].state = 1; // Keep the cell alive
            } else {
                // If the cell is alive and has less than two alive neighbors, die
                if (grid[i][j].state == 1 && countNeighbors(grid, i, j, width, height) < 2) {
                    grid[i][j].state = 0; // Make the cell die
                }
                // If the cell is dead and has exactly three alive neighbors, come to life
                else if (grid[i][j].state == 0 && countNeighbors(grid, i, j, width, height) == 3) {
                    grid[i][j].state = 1; // Make the cell come to life
                }
            }
        }
    }
}

// Function to count the number of alive neighbors of a cell
int countNeighbors(Cell** grid, int x, int y, int width, int height) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height && grid[x + i][y + j].state == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Create a 2D array of cells
    Cell** grid = createGrid(WIDTH, HEIGHT);

    // Initialize the grid with random values
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].state = (rand() % 2) == 0 ? 1 : 0;
        }
    }

    // Update the grid for 100 generations
    for (int i = 0; i < 100; i++) {
        updateGrid(grid, WIDTH, HEIGHT);
    }

    // Print the final state of the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].state == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}