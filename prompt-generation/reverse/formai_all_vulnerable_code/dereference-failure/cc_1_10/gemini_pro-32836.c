//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 100  // Grid size
#define P_THRESH 0.5  // Percolation threshold

// Grid cell states
enum { CLOSED, OPEN, PERCOLATED };

// Grid data structure
struct grid_cell {
    int state;
    double p;
};

// Generate a grid of closed cells
struct grid_cell** create_grid(int size) {
    struct grid_cell** grid = malloc(sizeof(struct grid_cell*) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(struct grid_cell) * size);
        for (int j = 0; j < size; j++) {
            grid[i][j].state = CLOSED;
            grid[i][j].p = 0.0;
        }
    }
    return grid;
}

// Open a cell at a given row and column
void open_cell(struct grid_cell** grid, int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return;
    }
    grid[row][col].state = OPEN;
}

// Check if a cell is open
int is_open(struct grid_cell** grid, int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return 0;
    }
    return grid[row][col].state == OPEN;
}

// Check if a cell is percolated
int is_percolated(struct grid_cell** grid, int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return 0;
    }
    return grid[row][col].state == PERCOLATED;
}

// Perform a depth-first search to find all open cells connected to a given cell
void dfs(struct grid_cell** grid, int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return;
    }
    if (grid[row][col].state != OPEN) {
        return;
    }
    grid[row][col].state = PERCOLATED;
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
}

// Check if the grid percolates
int does_percolate(struct grid_cell** grid) {
    // Check the top row for open cells
    for (int i = 0; i < GRID_SIZE; i++) {
        if (is_open(grid, 0, i)) {
            dfs(grid, 0, i);
        }
    }
    // Check the bottom row for percolated cells
    for (int i = 0; i < GRID_SIZE; i++) {
        if (is_percolated(grid, GRID_SIZE - 1, i)) {
            return 1;
        }
    }
    return 0;
}

// Print the grid
void print_grid(struct grid_cell** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            switch (grid[i][j].state) {
                case CLOSED:
                    printf(" . ");
                    break;
                case OPEN:
                    printf(" o ");
                    break;
                case PERCOLATED:
                    printf(" * ");
                    break;
            }
        }
        printf("\n");
    }
}

// Free the grid memory
void free_grid(struct grid_cell** grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    // Create a grid
    struct grid_cell** grid = create_grid(GRID_SIZE);

    // Open cells randomly
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (rand() / (double)RAND_MAX < P_THRESH) {
                open_cell(grid, i, j);
            }
        }
    }

    // Check if the grid percolates
    int does_perc = does_percolate(grid);

    // Print the grid
    print_grid(grid);

    // Free the grid memory
    free_grid(grid);

    return 0;
}