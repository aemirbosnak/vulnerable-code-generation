//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int born;   // Whether the cell was born in the current generation
} cell_t;

// Function to generate the game of life grid
void generate_grid(cell_t **grid) {
    int i, j;

    // Generate a random grid of cells
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].born = 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t **grid) {
    int i, j;

    // Loop through each cell in the grid
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two alive neighbors, leave it alive
            if (grid[i][j].alive && grid[i][j-1].alive && grid[i][j+1].alive) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has three alive neighbors, born a new cell
            else if (grid[i][j].alive && grid[i][j-1].alive && grid[i][j+1].alive && grid[i-1][j].alive) {
                grid[i][j].born = 1;
            }
            // If the cell is dead and has three dead neighbors, die
            else if (!grid[i][j].alive && !grid[i-1][j].alive && !grid[i+1][j].alive) {
                grid[i][j].alive = 0;
            }
            // Otherwise, do nothing
        }
    }
}

// Function to print the game of life grid
void print_grid(cell_t **grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t **grid;
    generate_grid(&grid);
    apply_rules(grid);
    print_grid(grid);
    return 0;
}