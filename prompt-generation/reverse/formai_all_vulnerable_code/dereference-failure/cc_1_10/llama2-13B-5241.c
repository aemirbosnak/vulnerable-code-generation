//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct cell {
    int alive;
} cell;

// Function to draw the game of life grid
void draw_grid(cell **grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to update the game of life grid
void update_grid(cell **grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                // If the cell is alive and has two or three alive neighbors, keep it alive
                if (grid[i][j - 1].alive && grid[i][j + 1].alive && grid[i][j - 2].alive) {
                    grid[i][j].alive = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (grid[i][j - 1].alive && grid[i][j + 1].alive) {
                        grid[i][j].alive = 0;
                    }
                }
            } else {
                // If the cell is dead and has three alive neighbors, come to life
                if (grid[i][j - 1].alive && grid[i][j + 1].alive && grid[i][j - 2].alive) {
                    grid[i][j].alive = 1;
                }
            }
        }
    }
}

int main() {
    cell **grid = malloc(WIDTH * sizeof(cell *));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = malloc(HEIGHT * sizeof(cell));
    }

    // Initialize the grid with random values
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
        }
    }

    // Draw the initial grid
    draw_grid(grid, WIDTH, HEIGHT);

    // Update the grid for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        update_grid(grid, WIDTH, HEIGHT);
    }

    // Draw the final grid
    draw_grid(grid, WIDTH, HEIGHT);

    // Free memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}