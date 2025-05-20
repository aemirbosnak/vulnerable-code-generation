//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int next;   // The next state of the cell (used for simulating)
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].next = grid[i][j].alive;
        }
    }
}

// Function to simulate one generation of the game of life
void simulate(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].next == 1) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                if (grid[i][j].alive && (grid[i][j].alive == grid[i][j - 1].alive) && (grid[i][j].alive == grid[i][j + 1].alive)) {
                    grid[i][j].next = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (grid[i][j].alive && (grid[i][j].alive != grid[i][j - 1].alive) && (grid[i][j].alive != grid[i][j + 1].alive)) {
                        grid[i][j].next = 0;
                    }
                }
            } else {
                // If the cell is dead and has three alive neighbors, come to life
                if (!grid[i][j].alive && (grid[i][j].alive == grid[i][j - 1].alive) && (grid[i][j].alive == grid[i][j + 1].alive)) {
                    grid[i][j].next = 1;
                }
            }
            grid[i][j].alive = grid[i][j].next;
        }
    }
}

int main() {
    cell_t** grid = (cell_t**) malloc(WIDTH * HEIGHT * sizeof(cell_t*));
    init_grid(grid);

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < 100; i++) {
        simulate(grid);
        // Print the current state of the grid
        for (int j = 0; j < HEIGHT; j++) {
            for (int i = 0; i < WIDTH; i++) {
                printf("%d ", grid[i][j].alive);
            }
            printf("\n");
        }
    }

    free(grid);
    return 0;
}