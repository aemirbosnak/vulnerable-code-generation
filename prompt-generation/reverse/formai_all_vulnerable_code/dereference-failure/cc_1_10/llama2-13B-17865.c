//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a cell in the game
typedef struct {
    int state; // 0 for dead, 1 for alive
    int neighbors; // Number of alive neighbors
} Cell;

// Function to create a 2D array of cells
Cell** createGrid(int rows, int cols) {
    Cell** grid = calloc(rows, sizeof(Cell*));
    for (int i = 0; i < rows; i++) {
        grid[i] = calloc(cols, sizeof(Cell));
    }
    return grid;
}

// Function to update the game state
void updateGrid(Cell** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i][j].state == 1 && grid[i][j].neighbors >= 2 && grid[i][j].neighbors <= 3) {
                grid[i][j].state = 1;
            }
            // If the cell is dead and has exactly three alive neighbors, bring it to life
            else if (grid[i][j].state == 0 && grid[i][j].neighbors == 3) {
                grid[i][j].state = 1;
            }
            // If the cell is alive and has no alive neighbors, kill it
            else if (grid[i][j].state == 1 && grid[i][j].neighbors == 0) {
                grid[i][j].state = 0;
            }
            // If the cell is dead and has alive neighbors, bring it to life
            else if (grid[i][j].state == 0 && grid[i][j].neighbors > 0) {
                grid[i][j].state = 1;
            }
        }
    }
}

// Function to draw the game grid
void drawGrid(Cell** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].state == 1) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a 10x10 grid of cells
    Cell** grid = createGrid(10, 10);

    // Initialize the cells with random states
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].state = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors = 0;
        }
    }

    // Add some cells to the grid
    for (int i = 0; i < 5; i++) {
        grid[5][i].state = 1;
    }
    for (int i = 5; i < 10; i++) {
        grid[i][5].state = 1;
    }

    // Update the game state for a few generations
    for (int generation = 0; generation < 10; generation++) {
        updateGrid(grid, 10, 10);
    }

    // Draw the final game state
    drawGrid(grid, 10, 10);

    // Free the memory used by the grid
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}