//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

// Structure to represent a cell in the game of life
typedef struct {
    int alive;
} cell_t;

// Function to generate the game of life grid
void generate_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid, int width, int height) {
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
void update_grid(cell_t** grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].alive && (grid[i][j - 1].alive || grid[i][j + 1].alive || grid[i - 1][j].alive || grid[i + 1][j].alive)) {
                grid[i][j].alive = 1; // Cell is alive and has two or three alive neighbors, so it stays alive
            } else {
                grid[i][j].alive = 0; // Cell is not alive or has less than two alive neighbors, so it dies
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Generate the game of life grid
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WINDOW_WIDTH);
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * WINDOW_HEIGHT);
    }
    generate_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Draw the game of life grid
    draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Update the game of life grid
    update_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Free memory
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}