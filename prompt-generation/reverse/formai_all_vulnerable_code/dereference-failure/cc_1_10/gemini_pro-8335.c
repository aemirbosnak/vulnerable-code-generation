//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the grid size
#define SIZE 100

// Define the number of simulations
#define SIMULATIONS 1000

// Define the probability of a cell being open
#define PROBABILITY 0.5

// Define the data structure for a cell
typedef struct {
    int open;
    int visited;
} cell;

// Define the data structure for the grid
typedef struct {
    cell cells[SIZE][SIZE];
    int num_open;
} grid;

// Create a new grid
grid *create_grid() {
    grid *g = malloc(sizeof(grid));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            g->cells[i][j].open = (rand() / (RAND_MAX + 1.0)) < PROBABILITY;
            g->cells[i][j].visited = 0;
        }
    }
    g->num_open = 0;
    return g;
}

// Free a grid
void free_grid(grid *g) {
    free(g);
}

// Open a cell
void open_cell(grid *g, int i, int j) {
    if (g->cells[i][j].open && !g->cells[i][j].visited) {
        g->cells[i][j].visited = 1;
        g->num_open++;
        // Recursively open adjacent cells
        if (i > 0) open_cell(g, i - 1, j);
        if (i < SIZE - 1) open_cell(g, i + 1, j);
        if (j > 0) open_cell(g, i, j - 1);
        if (j < SIZE - 1) open_cell(g, i, j + 1);
    }
}

// Check if a grid percolates
int percolates(grid *g) {
    // Open the top row of cells
    for (int i = 0; i < SIZE; i++) {
        open_cell(g, i, 0);
    }

    // Check if any cells in the bottom row are open
    for (int i = 0; i < SIZE; i++) {
        if (g->cells[i][SIZE - 1].visited) {
            return 1;
        }
    }

    return 0;
}

// Run a simulation
int run_simulation() {
    grid *g = create_grid();
    int result = percolates(g);
    free_grid(g);
    return result;
}

// Main function
int main() {
    srand(time(NULL));

    int num_percolates = 0;
    for (int i = 0; i < SIMULATIONS; i++) {
        num_percolates += run_simulation();
    }

    printf("The probability of percolation is %f\n", (double)num_percolates / SIMULATIONS);

    return 0;
}