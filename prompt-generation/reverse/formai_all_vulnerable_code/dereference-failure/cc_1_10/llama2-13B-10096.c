//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a cell in the game of life
typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

// Function to generate the game of life grid
void generate_grid(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Initialize cell as alive with a 50% chance
            grid[i][j].alive = rand() % 2;
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
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
void update_grid(cell_t **grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Check if cell is alive and has two or three alive neighbors
            if (grid[i][j].alive && (grid[i][j-1].alive || grid[i][j+1].alive || grid[i-1][j].alive || grid[i+1][j].alive)) {
                // If so, keep the cell alive
                grid[i][j].alive = 1;
            } else {
                // If not, set the cell to dead
                grid[i][j].alive = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Create the game of life grid
    cell_t **grid = (cell_t **) malloc(sizeof(cell_t *) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t *) malloc(sizeof(cell_t) * HEIGHT);
    }

    // Generate the grid
    generate_grid(grid, WIDTH, HEIGHT);

    // Draw the grid
    draw_grid(grid, WIDTH, HEIGHT);

    // Update the grid
    update_grid(grid, WIDTH, HEIGHT);

    // Free the grid memory
    for (int i = 0; i < WIDTH; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}