//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to update the grid based on the game of life rules
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < GRID_SIZE && grid[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < GRID_SIZE && grid[i][j + 1].alive) {
                neighbors++;
            }

            // Update the cell based on the number of alive neighbors
            if (grid[i][j].alive && neighbors >= 2 && neighbors <= 3) {
                grid[i][j].alive = 1;
            } else if (!grid[i][j].alive && neighbors == 3) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = (cell_t**)calloc(GRID_SIZE, sizeof(cell_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (cell_t*)calloc(GRID_SIZE, sizeof(cell_t));
    }

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }

    return 0;
}