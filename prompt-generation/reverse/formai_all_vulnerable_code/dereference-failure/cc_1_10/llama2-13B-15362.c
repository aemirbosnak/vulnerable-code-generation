//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int born;   // Whether the cell was born in the current generation
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].born = 0;
        }
    }
}

// Function to apply the Game of Life rules to the grid
void apply_rules(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j].born || (grid[i][j-1].alive && grid[i][j+1].alive))) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has less than two alive neighbors, die
            else if (grid[i][j].alive && !(grid[i][j-1].alive && grid[i][j+1].alive)) {
                grid[i][j].alive = 0;
            }
            // If the cell is dead and has exactly three alive neighbors, come to life
            else if (!grid[i][j].alive && grid[i][j-1].alive && grid[i][j+1].alive && !grid[i][j-2].alive && !grid[i][j+2].alive) {
                grid[i][j].alive = 1;
            }
            // Otherwise, do nothing
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid;
    srand(time(NULL));
    init_grid(&grid);
    for (int gen = 0; gen < 10; gen++) {
        apply_rules(grid);
        print_grid(grid);
        printf("Generation %d\n", gen);
    }
    return 0;
}