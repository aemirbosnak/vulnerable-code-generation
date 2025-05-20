//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Empty cell
#define EMPTY_CELL 0

// Grid size
#define GRID_SIZE 9

// Row
typedef struct row {
    int cells[GRID_SIZE];
    int num_empty_cells;
} row;

// Sudoku grid
typedef struct grid {
    row rows[GRID_SIZE];
    int num_empty_cells;
} grid;

// Create a new grid
grid* create_grid() {
    grid* g = malloc(sizeof(grid));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            g->rows[i].cells[j] = EMPTY_CELL;
            g->rows[i].num_empty_cells++;
            g->num_empty_cells++;
        }
    }
    return g;
}

// Free a grid
void free_grid(grid* g) {
    free(g);
}

// Print a grid
void print_grid(grid* g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", g->rows[i].cells[j]);
        }
        printf("\n");
    }
}

// Check if a number is valid in a row
int is_valid_in_row(grid* g, int row, int num) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (g->rows[row].cells[i] == num) {
            return 0;
        }
    }
    return 1;
}

// Check if a number is valid in a column
int is_valid_in_column(grid* g, int column, int num) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (g->rows[i].cells[column] == num) {
            return 0;
        }
    }
    return 1;
}

// Check if a number is valid in a box
int is_valid_in_box(grid* g, int row, int column, int num) {
    int box_row = row / 3;
    int box_column = column / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_column * 3; j < box_column * 3 + 3; j++) {
            if (g->rows[i].cells[j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Check if a number is valid in a cell
int is_valid(grid* g, int row, int column, int num) {
    return is_valid_in_row(g, row, num) && is_valid_in_column(g, column, num) && is_valid_in_box(g, row, column, num);
}

// Solve a Sudoku grid
int solve_sudoku(grid* g) {
    // If there are no more empty cells, the grid is solved
    if (g->num_empty_cells == 0) {
        return 1;
    }

    // Find the first empty cell
    int row, column;
    for (row = 0; row < GRID_SIZE; row++) {
        for (column = 0; column < GRID_SIZE; column++) {
            if (g->rows[row].cells[column] == EMPTY_CELL) {
                break;
            }
        }
        if (column < GRID_SIZE) {
            break;
        }
    }

    // Try all possible numbers for the empty cell
    for (int num = 1; num <= GRID_SIZE; num++) {
        if (is_valid(g, row, column, num)) {
            // Fill the empty cell with the number
            g->rows[row].cells[column] = num;
            g->rows[row].num_empty_cells--;
            g->num_empty_cells--;

            // Recursively solve the grid
            if (solve_sudoku(g)) {
                return 1;
            }

            // If the grid could not be solved, reset the empty cell
            g->rows[row].cells[column] = EMPTY_CELL;
            g->rows[row].num_empty_cells++;
            g->num_empty_cells++;
        }
    }

    // If no possible numbers for the empty cell could lead to a solution, the grid cannot be solved
    return 0;
}

int main() {
    // Create a new grid
    grid* g = create_grid();

    // Read the grid from a file
    FILE* f = fopen("sudoku.txt", "r");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            fscanf(f, "%d ", &g->rows[i].cells[j]);
            if (g->rows[i].cells[j] == EMPTY_CELL) {
                g->rows[i].num_empty_cells++;
                g->num_empty_cells++;
            }
        }
    }
    fclose(f);

    // Print the original grid
    printf("Original grid:\n");
    print_grid(g);

    // Solve the grid
    if (solve_sudoku(g)) {
        // Print the solved grid
        printf("Solved grid:\n");
        print_grid(g);
    } else {
        printf("The grid cannot be solved.\n");
    }

    // Free the grid
    free_grid(g);

    return 0;
}