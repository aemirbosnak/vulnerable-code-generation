//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define GRID_SIZE 100

// Define the number of generations to run
#define GENERATIONS 100

// Define the rules for the game of life
#define ALIVE 1
#define DEAD 0

// Define a structure to represent a cell in the grid
typedef struct cell {
    int state; // The current state of the cell (ALIVE or DEAD)
    int neighbors[GRID_SIZE]; // The number of alive neighbors of the cell
} cell_t;

// Define a function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j].state = (rand() % 2) ? ALIVE : DEAD;
            grid[i][j].neighbors[0] = 0;
        }
    }
}

// Define a function to update the state of a cell based on its neighbors
void update_cell(cell_t** grid, int i, int j) {
    int neighbors = 0;
    int alive_neighbors = 0;

    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 || l == 0 || i + k < 0 || i + k >= GRID_SIZE ||
                    j + l < 0 || j + l >= GRID_SIZE) {
                continue;
            }

            if (grid[i + k][j + l].state == ALIVE) {
                neighbors++;
                alive_neighbors++;
            }
        }
    }

    if (alive_neighbors < 2 || alive_neighbors > 3) {
        grid[i][j].state = DEAD;
    } else if (neighbors == 2 && alive_neighbors == 3) {
        grid[i][j].state = ALIVE;
    } else {
        grid[i][j].state = DEAD;
    }
}

// Define a function to print the grid
void print_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j].state == ALIVE) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = malloc(GRID_SIZE * GRID_SIZE * sizeof(cell_t));
    init_grid(grid);

    for (int i = 0; i < GENERATIONS; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            for (int k = 0; k < GRID_SIZE; k++) {
                update_cell(grid, i, j);
            }
        }

        print_grid(grid);
        printf("Generation %d\n", i + 1);
    }

    free(grid);

    return 0;
}