//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to iterate through the grid and update the state of each cell
void update_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < size && grid[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < size && grid[i][j + 1].alive) {
                neighbors++;
            }

            // Update the cell's state based on the number of alive neighbors
            if (neighbors == 2 || neighbors == 3) {
                grid[i][j].alive = 1;
            } else if (neighbors == 0 || neighbors == 4) {
                grid[i][j].alive = 0;
            } else {
                grid[i][j].alive = grid[i][j].alive; // No change
            }
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t** grid, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main() {
    int size = 20; // Size of the grid
    cell_t** grid = calloc(size, sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = calloc(size, sizeof(cell_t));
    }

    init_grid(grid, size);

    for (int i = 0; i < 100; i++) {
        update_grid(grid, size);
    }

    print_grid(grid, size);

    return 0;
}