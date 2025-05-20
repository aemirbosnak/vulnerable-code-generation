//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors;  // Number of living neighbors
} cell_t;

// Function to initialize the grid with random cells
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Set the cell to be alive with a 50% chance
            if (rand() % 2) {
                grid[i][j].alive = 1;
            } else {
                grid[i][j].alive = 0;
            }

            // Set the number of living neighbors to 0
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to count the number of living neighbors for a cell
void count_neighbors(cell_t* cell, cell_t** grid) {
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 || j == 0) {
                continue;  // Skip the current cell
            }

            if (grid[cell->alive + i][cell->alive + j].alive) {
                cell->neighbors++;
            }
        }
    }
}

// Function to update the state of the cells
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            // Update the state of the current cell
            count_neighbors(&grid[i][j], grid);

            // Apply the rules of the Game of Life
            if (grid[i][j].alive && grid[i][j].neighbors >= 2 && grid[i][j].neighbors <= 3) {
                grid[i][j].alive = 1;  // Cell stays alive
            } else if (!grid[i][j].alive && grid[i][j].neighbors == 3) {
                grid[i][j].alive = 1;  // Cell is born
            } else {
                grid[i][j].alive = 0;  // Cell dies
            }
        }
    }
}

int main() {
    cell_t** grid = (cell_t**)malloc(GRID_SIZE * sizeof(cell_t*));

    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = (cell_t*)malloc(GRID_SIZE * sizeof(cell_t));
    }

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d", grid[i][j].alive);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}