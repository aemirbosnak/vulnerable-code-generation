//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the game of life
typedef struct {
    int alive;    // Whether the cell is alive or not
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (i % 2 == 0) && (j % 2 == 0); // Initialize cells with a 50% chance of being alive
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors++;
            }
            // Update the cell's state based on the number of alive neighbors
            grid[i][j].alive = (neighbors >= 2) || (neighbors <= 0);
            grid[i][j].neighbors = neighbors;
        }
    }
}

// Function to print the game of life grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf(" alive");
            } else {
                printf(" dead");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * HEIGHT);
    }
    init_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    return 0;
}