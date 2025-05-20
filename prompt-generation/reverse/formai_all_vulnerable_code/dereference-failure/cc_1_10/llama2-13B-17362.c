//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate through the grid and apply the game of life rules
void update_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbors_alive++;
            }
            if (i + 1 < width && grid[i + 1][j].alive) {
                neighbors_alive++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbors_alive++;
            }
            if (j + 1 < height && grid[i][j + 1].alive) {
                neighbors_alive++;
            }

            // Apply the game of life rules
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1;  // Stay alive if there are 2-3 alive neighbors
            } else if (grid[i][j].alive && neighbors_alive < 2) {
                grid[i][j].alive = 0;  // Die if there is only 1 alive neighbor
            } else if (!grid[i][j].alive && neighbors_alive >= 3) {
                grid[i][j].alive = 1;  // Come to life if there are 3 alive neighbors
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid, int width, int height) {
    int i, j;

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O ");  // Draw a circle if the cell is alive
            } else {
                printf("_ ");  // Draw a blank space if the cell is dead
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the game of life grid
    cell_t** grid = malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(sizeof(cell_t) * HEIGHT);
    }
    init_grid(grid, WIDTH, HEIGHT);

    // Update the grid for a few generations
    for (int i = 0; i < 10; i++) {
        update_grid(grid, WIDTH, HEIGHT);
    }

    // Draw the final state of the grid
    draw_grid(grid, WIDTH, HEIGHT);

    // Free the memory used by the grid
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}