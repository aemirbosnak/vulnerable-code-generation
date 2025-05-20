//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules to the grid
void apply_rules(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbors_alive++;
            }

            // Apply the rules
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1;  // Stay alive if there are 2 or 3 alive neighbors
            } else if (grid[i][j].alive && neighbors_alive == 0) {
                grid[i][j].alive = 0;  // Die if there are no alive neighbors
            } else {
                grid[i][j].alive = 1 - grid[i][j].alive;  // Flip the cell if there are 4 alive neighbors
            }
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
    cell_t** grid = calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }

    // Initialize the grid with random values
    init_grid(grid);

    // Apply the game of life rules for 10 generations
    for (int generation = 0; generation < 10; generation++) {
        apply_rules(grid);
    }

    // Print the final grid
    print_grid(grid);

    // Free the memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}