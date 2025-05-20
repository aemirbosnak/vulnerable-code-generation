//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a grid cell
typedef struct {
    int alive;   // Whether the cell is alive or not
    int born;   // Whether the cell was born in the current generation
} cell_t;

// Function to initialize the grid with random data
void init_grid(cell_t* grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i * HEIGHT + j].alive = rand() % 2;
            grid[i * HEIGHT + j].born = 0;
        }
    }
}

// Function to apply the Game of Life rules
void apply_rules(cell_t* grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i * HEIGHT + j].alive && (grid[i * HEIGHT + j - 1].alive || grid[i * HEIGHT + j + 1].alive || grid[i * HEIGHT + j - HEIGHT].alive)) {
                grid[i * HEIGHT + j].alive = 1;
            }
            // If the cell is alive and has less than two alive neighbors, die (underpopulation)
            else if (grid[i * HEIGHT + j].alive && !(grid[i * HEIGHT + j - 1].alive || grid[i * HEIGHT + j + 1].alive)) {
                grid[i * HEIGHT + j].alive = 0;
            }
            // If the cell is dead and has exactly three alive neighbors, come to life (reproduction)
            else if (!grid[i * HEIGHT + j].alive && (grid[i * HEIGHT + j - 1].alive && grid[i * HEIGHT + j + 1].alive && grid[i * HEIGHT + j - HEIGHT].alive)) {
                grid[i * HEIGHT + j].alive = 1;
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t* grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i * HEIGHT + j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t* grid;
    srand(time(NULL));

    // Initialize the grid with random data
    init_grid(grid);

    // Apply the Game of Life rules for a few generations
    for (int i = 0; i < 10; i++) {
        apply_rules(grid);
    }

    // Print the final grid
    print_grid(grid);

    return 0;
}