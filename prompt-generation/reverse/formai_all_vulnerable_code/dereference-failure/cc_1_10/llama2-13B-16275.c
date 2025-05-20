//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the game of life
typedef struct cell {
    int state; // 0 for dead, 1 for alive
    int next_state; // The next state of the cell, based on the current state and the neighborhood
} cell_t;

// Function to initialize the grid with random cells
void init_grid(cell_t** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j].state = rand() % 2;
            grid[i][j].next_state = grid[i][j].state;
        }
    }
}

// Function to apply the game of life rules to the grid
void update_grid(cell_t** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Calculate the neighborhood of the current cell
            int neighbors = 0;
            if (i - 1 >= 0) {
                neighbors += grid[i - 1][j].state;
            }
            if (i + 1 < size) {
                neighbors += grid[i + 1][j].state;
            }
            if (j - 1 >= 0) {
                neighbors += grid[i][j - 1].state;
            }
            if (j + 1 < size) {
                neighbors += grid[i][j + 1].state;
            }
            
            // Apply the game of life rules
            if (neighbors < 2) {
                grid[i][j].next_state = grid[i][j].state;
            } else if (neighbors > 3) {
                grid[i][j].next_state = 0;
            } else {
                grid[i][j].next_state = grid[i][j].state;
            }
        }
    }
}

// Function to print the final state of the grid
void print_grid(cell_t** grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }
}

int main() {
    int size = 10; // Size of the grid
    cell_t** grid = malloc(size * sizeof(cell_t*));
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(size * sizeof(cell_t));
    }
    
    init_grid(grid, size);
    
    for (int i = 0; i < 100; i++) {
        update_grid(grid, size);
    }
    
    print_grid(grid, size);
    
    return 0;
}