//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int next;   // The next state of the cell (dead or alive)
} cell_t;

// Function to generate the game of life grid
void generate_grid(cell_t** grid) {
    int i, j;

    // Initialize the grid with random values
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].next = grid[i][j].alive;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid) {
    int i, j;

    // Update the state of each cell based on its neighbors
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].next == 1) { // If the cell is alive and has two or three alive neighbors
                grid[i][j].next = 1; // Keep the cell alive
            } else if (grid[i][j].next == 0 && grid[i][j].alive == 1 && // If the cell is alive and has fewer than two alive neighbors
                    (grid[i][j-1].alive == 1 || grid[i][j+1].alive == 1 || grid[i-1][j].alive == 1 || grid[i+1][j].alive == 1) && // Check the four neighbors
                    (grid[i][j-1].alive + grid[i][j+1].alive + grid[i-1][j].alive + grid[i+1][j].alive) >= 2) { // Check the total number of alive neighbors
                grid[i][j].next = 1; // Keep the cell alive
            } else {
                grid[i][j].next = 0; // Make the cell dead
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid) {
    int i, j;

    // Draw the grid with characters
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = (cell_t**) malloc(WIDTH * HEIGHT * sizeof(cell_t*));

    // Generate the initial grid
    generate_grid(grid);

    // Update the grid for a few generations
    for (int i = 0; i < 10; i++) {
        update_grid(grid);
    }

    // Draw the final grid
    draw_grid(grid);

    // Free the memory
    free(grid);

    return 0;
}