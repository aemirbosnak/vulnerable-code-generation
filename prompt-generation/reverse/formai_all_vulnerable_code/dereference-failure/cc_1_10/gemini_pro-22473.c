//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A grid of cells, each of which can be open or closed.
typedef struct {
    int rows;
    int cols;
    int *cells;
} Grid;

// Creates a new grid with the given dimensions.
Grid *create_grid(int rows, int cols) {
    Grid *grid = malloc(sizeof(Grid));
    grid->rows = rows;
    grid->cols = cols;
    grid->cells = malloc(rows * cols * sizeof(int));
    return grid;
}

// Frees the memory allocated for the grid.
void free_grid(Grid *grid) {
    free(grid->cells);
    free(grid);
}

// Opens a cell at the given coordinates.
void open_cell(Grid *grid, int row, int col) {
    grid->cells[row * grid->cols + col] = 1;
}

// Checks if a cell at the given coordinates is open.
int is_open(Grid *grid, int row, int col) {
    return grid->cells[row * grid->cols + col] == 1;
}

// Checks if the grid percolates, i.e. if there is a path from the top to the bottom of the grid.
int does_percolate(Grid *grid) {
    // Start at the top of the grid.
    int row = 0;
    int col = 0;

    // While we haven't reached the bottom of the grid, keep going.
    while (row < grid->rows) {
        // If the current cell is open, move down one row.
        if (is_open(grid, row, col)) {
            row++;
        } else {
            // If the current cell is closed, move right one column.
            col++;
            if (col == grid->cols) {
                // If we've reached the end of the row, start over at the beginning.
                row = 0;
            }
        }
    }

    // If we've reached the bottom of the grid, then the grid percolates.
    return row == grid->rows;
}

// Prints the grid to the console.
void print_grid(Grid *grid) {
    for (int row = 0; row < grid->rows; row++) {
        for (int col = 0; col < grid->cols; col++) {
            printf("%d", is_open(grid, row, col));
        }
        printf("\n");
    }
}

// The main function.
int main() {
    // Create a new grid.
    Grid *grid = create_grid(10, 10);

    // Open some cells.
    open_cell(grid, 0, 0);
    open_cell(grid, 1, 2);
    open_cell(grid, 2, 4);
    open_cell(grid, 3, 6);
    open_cell(grid, 4, 8);

    // Print the grid.
    print_grid(grid);

    // Check if the grid percolates.
    int percolates = does_percolate(grid);

    // Print the result.
    printf("Does the grid percolate? %s\n", percolates ? "Yes" : "No");

    // Free the memory allocated for the grid.
    free_grid(grid);

    return 0;
}