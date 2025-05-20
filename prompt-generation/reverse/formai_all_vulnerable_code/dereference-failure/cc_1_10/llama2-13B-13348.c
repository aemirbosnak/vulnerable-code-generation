//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a grid cell
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to create a 2D grid of cell_t structs
cell_t** create_grid(int rows, int cols) {
    cell_t** grid = malloc(rows * sizeof(cell_t*));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(cell_t));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (cell_t){0, 0}; // Initialize all cells as dead
        }
    }
    return grid;
}

// Function to update the grid based on the rules of life
void update_grid(cell_t** grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Calculate the number of alive neighbors
            int neighbors = count_alive_neighbors(grid, i, j);
            grid[i][j].neighbors = neighbors;
            // Apply the rules of life
            if (grid[i][j].alive && neighbors < 2 && neighbors > 0) {
                grid[i][j].alive = 0; // Death
            } else if (!grid[i][j].alive && neighbors >= 2) {
                grid[i][j].alive = 1; // Birth
            }
        }
    }
}

// Function to count the number of alive neighbors
int count_alive_neighbors(cell_t** grid, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue; // Don't count the current cell
            }
            if (grid[row + i][col + j].alive) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    int rows = 20; // Grid size
    int cols = 20;
    cell_t** grid = create_grid(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j].alive = rand() % 2; // Initialize cells randomly
        }
    }
    for (int generation = 0; generation < 100; generation++) {
        update_grid(grid, rows, cols);
        printf("Generation %d: ", generation);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j].alive) {
                    printf("X ");
                } else {
                    printf(" . ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}