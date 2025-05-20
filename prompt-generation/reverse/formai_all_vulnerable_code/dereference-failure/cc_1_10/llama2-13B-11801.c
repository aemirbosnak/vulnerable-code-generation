//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define POPULATION_SIZE 100
#define GENERATIONS 10

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int age;    // The age of the cell
} cell_t;

// Function to initialize the grid with random cells
void initialize_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < POPULATION_SIZE; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].age = 0;
        }
    }
}

// Function to update the grid based on the current state
void update_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < POPULATION_SIZE; j++) {
            // If the cell is alive and has an age of 0, it dies of old age
            if (grid[i][j].alive && grid[i][j].age == 0) {
                grid[i][j].alive = 0;
            }
            // If the cell is alive and has an age of 1, it reproduces
            else if (grid[i][j].alive && grid[i][j].age == 1) {
                int neighbors_alive = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (k == 0 || l == 0) continue;
                        if (grid[i + k][j + l].alive) {
                            neighbors_alive++;
                        }
                    }
                }
                if (neighbors_alive >= 2 && rand() % 2 == 0) {
                    grid[i][j].alive = 1;
                    grid[i][j].age = 0;
                }
            }
            // If the cell is dead and has an age of 1, it resurrects
            else if (!grid[i][j].alive && grid[i][j].age == 1) {
                grid[i][j].alive = 1;
                grid[i][j].age = 0;
            }
            grid[i][j].age++;
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < POPULATION_SIZE; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t **grid;
    initialize_grid(&grid);
    for (int i = 0; i < GENERATIONS; i++) {
        update_grid(grid);
    }
    print_grid(grid);
    return 0;
}