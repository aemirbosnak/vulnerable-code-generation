//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a cell in the grid
typedef struct cell {
    int state;  // 0 for dead, 1 for alive
    int neighbors[8];  // Array of neighbors (up, down, left, right, diag_up, diag_down)
} cell_t;

// Function to create a grid of cells
cell_t* create_grid(int rows, int cols) {
    int i, j;
    cell_t** grid = calloc(rows, sizeof(cell_t*));
    for (i = 0; i < rows; i++) {
        grid[i] = calloc(cols, sizeof(cell_t));
        for (j = 0; j < cols; j++) {
            // Initialize cells with random states
            grid[i][j].state = rand() % 2;
            grid[i][j].neighbors[0] = (i > 0) ? grid[i-1][j].state : 0;
            grid[i][j].neighbors[1] = (i < rows-1) ? grid[i+1][j].state : 0;
            grid[i][j].neighbors[2] = (j > 0) ? grid[i][j-1].state : 0;
            grid[i][j].neighbors[3] = (j < cols-1) ? grid[i][j+1].state : 0;
            grid[i][j].neighbors[4] = (i > 0 && j > 0) ? grid[i-1][j-1].state : 0;
            grid[i][j].neighbors[5] = (i < rows-1 && j > 0) ? grid[i+1][j-1].state : 0;
            grid[i][j].neighbors[6] = (i > 0 && j < cols-1) ? grid[i-1][j+1].state : 0;
            grid[i][j].neighbors[7] = (i < rows-1 && j < cols-1) ? grid[i+1][j+1].state : 0;
        }
    }
    return grid;
}

// Function to update the state of a cell based on its neighbors
void update_cell(cell_t* cell) {
    int alive_neighbors = 0;
    for (int i = 0; i < 8; i++) {
        if (cell->neighbors[i]) {
            alive_neighbors++;
        }
    }
    if (cell->state == 0 && alive_neighbors > 1) {
        cell->state = 1;  // If dead and has alive neighbors, become alive
    } else if (cell->state == 1 && alive_neighbors < 2) {
        cell->state = 0;  // If alive and has dead neighbors, become dead
    }
}

// Function to display the grid
void display_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < sizeof(grid) / sizeof(grid[0]); i++) {
        for (j = 0; j < sizeof(grid[i]) / sizeof(grid[i][0]); j++) {
            if (grid[i][j].state) {
                printf("Alive");
            } else {
                printf("Dead");
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a grid of 20x20 cells
    cell_t** grid = create_grid(20, 20);

    // Update the state of each cell for 100 generations
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < sizeof(grid) / sizeof(grid[0]); j++) {
            for (int k = 0; k < sizeof(grid[j]) / sizeof(grid[j][0]); k++) {
                update_cell(&grid[j][k]);
            }
        }
        display_grid(grid);
    }

    // Free the memory allocated for the grid
    for (int i = 0; i < sizeof(grid) / sizeof(grid[0]); i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}