//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50
#define PROBABILITY 0.6

// Struct to represent each site in the grid
typedef struct {
    int row;
    int col;
    int is_open;
    int is_full;
} site;

// Function signatures
void initialize_grid(site** grid);
void open_site(site** grid, int row, int col);
int is_valid(site** grid, int row, int col);
void percolate(site** grid);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create 2D array of sites
    site** grid = (site**) malloc(sizeof(site*) * ROWS);
    int i, j;
    for (i = 0; i < ROWS; i++) {
        grid[i] = (site*) malloc(sizeof(site) * COLS);
    }

    // Initialize grid
    initialize_grid(grid);

    // Percolate
    percolate(grid);

    // Free memory
    for (i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

// Initializes all sites in the grid to be closed
void initialize_grid(site** grid) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].is_open = 0;
            grid[i][j].is_full = 0;
        }
    }
}

// Opens a site in the grid and recursively opens neighboring sites if they are also closed
void open_site(site** grid, int row, int col) {
    if (!is_valid(grid, row, col) || grid[row][col].is_open) {
        return;
    }
    grid[row][col].is_open = 1;
    if (row == 0) {
        grid[row][col].is_full = 1;
    }
    open_site(grid, row-1, col);
    open_site(grid, row+1, col);
    open_site(grid, row, col-1);
    open_site(grid, row, col+1);
}

// Returns 1 if the given row and column are within the bounds of the grid and 0 otherwise
int is_valid(site** grid, int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// Performs percolation on the grid
void percolate(site** grid) {
    int i, j;
    int num_open = 0;
    while (1) {
        i = rand() % ROWS;
        j = rand() % COLS;
        if (!grid[i][j].is_open) {
            open_site(grid, i, j);
            num_open++;
        }
        if ((float) num_open / (ROWS * COLS) >= PROBABILITY) {
            break;
        }
    }
    int percolates = 0;
    for (j = 0; j < COLS; j++) {
        if (grid[ROWS-1][j].is_full) {
            percolates = 1;
            break;
        }
    }
    if (percolates) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
}