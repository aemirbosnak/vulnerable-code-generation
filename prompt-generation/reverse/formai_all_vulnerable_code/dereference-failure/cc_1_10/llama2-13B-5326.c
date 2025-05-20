//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 100
#define GENERATIONS 10

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;
    int neighbors_alive;
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < POPULATION_SIZE; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to calculate the number of alive neighbors for a given cell
int count_neighbors(cell_t** grid, int i, int j) {
    int alive_neighbors = 0;
    if (i - 1 >= 0) {
        alive_neighbors += grid[i - 1][j].alive;
    }
    if (i + 1 < POPULATION_SIZE) {
        alive_neighbors += grid[i + 1][j].alive;
    }
    if (j - 1 >= 0) {
        alive_neighbors += grid[i][j - 1].alive;
    }
    if (j + 1 < POPULATION_SIZE) {
        alive_neighbors += grid[i][j + 1].alive;
    }
    return alive_neighbors;
}

// Function to update the state of a cell based on its neighbors
void update_cell(cell_t** grid, int i, int j) {
    int alive_neighbors = count_neighbors(grid, i, j);
    if (alive_neighbors < 2) {
        grid[i][j].alive = 0;
    } else if (alive_neighbors > 3) {
        grid[i][j].alive = 0;
    } else {
        grid[i][j].alive = grid[i][j].alive * 2;
    }
}

// Function to print the final state of the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < POPULATION_SIZE; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid;
    init_grid(grid);

    for (int generation = 0; generation < GENERATIONS; generation++) {
        for (int i = 0; i < POPULATION_SIZE; i++) {
            for (int j = 0; j < POPULATION_SIZE; j++) {
                update_cell(grid, i, j);
            }
        }
    }

    print_grid(grid);

    return 0;
}