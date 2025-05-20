//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define GRID_SIZE 20
#define PERCOLATION_THRESHOLD 0.592746

// Grid structure
typedef struct {
    int cells[GRID_SIZE][GRID_SIZE];
    int open_count;
} grid_t;

// Function to create a new grid
grid_t* create_grid() {
    grid_t* grid = (grid_t*)malloc(sizeof(grid_t));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid->cells[i][j] = 0;
        }
    }
    grid->open_count = 0;
    return grid;
}

// Function to open a cell at a given position
void open_cell(grid_t* grid, int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return;
    }
    if (grid->cells[x][y] == 1) {
        return;
    }
    grid->cells[x][y] = 1;
    grid->open_count++;
}

// Function to check if a cell is open at a given position
int is_cell_open(grid_t* grid, int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return 0;
    }
    return grid->cells[x][y] == 1;
}

// Function to check if the grid percolates
int does_grid_percolate(grid_t* grid) {
    // Check if the top row has any open cells
    for (int i = 0; i < GRID_SIZE; i++) {
        if (is_cell_open(grid, i, 0)) {
            // Perform a depth-first search to find if any open cells reach the bottom row
            int visited[GRID_SIZE][GRID_SIZE];
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                    visited[i][j] = 0;
                }
            }
            int stack[GRID_SIZE * GRID_SIZE];
            int stack_top = 0;
            stack[stack_top++] = i * GRID_SIZE + 0;
            while (stack_top > 0) {
                int current_cell = stack[--stack_top];
                int x = current_cell / GRID_SIZE;
                int y = current_cell % GRID_SIZE;
                if (visited[x][y]) {
                    continue;
                }
                visited[x][y] = 1;
                if (y == GRID_SIZE - 1) {
                    return 1;
                }
                if (is_cell_open(grid, x + 1, y)) {
                    stack[stack_top++] = (x + 1) * GRID_SIZE + y;
                }
                if (is_cell_open(grid, x - 1, y)) {
                    stack[stack_top++] = (x - 1) * GRID_SIZE + y;
                }
                if (is_cell_open(grid, x, y + 1)) {
                    stack[stack_top++] = x * GRID_SIZE + (y + 1);
                }
                if (is_cell_open(grid, x, y - 1)) {
                    stack[stack_top++] = x * GRID_SIZE + (y - 1);
                }
            }
            return 0;
        }
    }
    return 0;
}

// Function to run the percolation experiment
double run_percolation_experiment(int num_trials) {
    int num_percolated = 0;
    for (int i = 0; i < num_trials; i++) {
        grid_t* grid = create_grid();
        while (grid->open_count < GRID_SIZE * GRID_SIZE * PERCOLATION_THRESHOLD) {
            int x = rand() % GRID_SIZE;
            int y = rand() % GRID_SIZE;
            open_cell(grid, x, y);
        }
        if (does_grid_percolate(grid)) {
            num_percolated++;
        }
        free(grid);
    }
    return (double)num_percolated / num_trials;
}

// Main function
int main() {
    srand(time(NULL));
    double percolation_probability = run_percolation_experiment(10000);
    printf("Percolation probability: %f\n", percolation_probability);
    return 0;
}