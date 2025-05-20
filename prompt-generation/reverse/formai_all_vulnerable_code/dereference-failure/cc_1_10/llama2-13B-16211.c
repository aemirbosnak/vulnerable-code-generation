//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define CELL_SIZE 10
#define GRID_SIZE 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int next_alive; // The next state of the cell (for the next iteration)
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int random = rand() % 2;
            grid[i * GRID_SIZE + j].alive = random;
            grid[i * GRID_SIZE + j].next_alive = random;
        }
    }
}

// Function to iterate through the grid and update the cell states
void update_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i * GRID_SIZE + j].alive &&
                    (grid[i * GRID_SIZE + j - 1].alive && grid[i * GRID_SIZE + j + 1].alive && grid[i * GRID_SIZE + j - CELL_SIZE].alive)) {
                grid[i * GRID_SIZE + j].next_alive = 1;
            } else {
                // If the cell is alive and has less than two alive neighbors, die
                if (grid[i * GRID_SIZE + j].alive && grid[i * GRID_SIZE + j - 1].alive && grid[i * GRID_SIZE + j + 1].alive) {
                    grid[i * GRID_SIZE + j].next_alive = 0;
                } else {
                    // If the cell is dead and has three alive neighbors, come to life
                    if (!grid[i * GRID_SIZE + j].alive && grid[i * GRID_SIZE + j - 1].alive && grid[i * GRID_SIZE + j + 1].alive && grid[i * GRID_SIZE + j - CELL_SIZE].alive) {
                        grid[i * GRID_SIZE + j].next_alive = 1;
                    }
                }
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t* grid) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i * GRID_SIZE + j].alive) {
                printf("O ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t* grid = malloc(GRID_SIZE * GRID_SIZE * sizeof(cell_t));
    init_grid(grid);

    for (int generations = 0; generations < 100; generations++) {
        update_grid(grid);
        draw_grid(grid);
    }

    free(grid);
    return 0;
}