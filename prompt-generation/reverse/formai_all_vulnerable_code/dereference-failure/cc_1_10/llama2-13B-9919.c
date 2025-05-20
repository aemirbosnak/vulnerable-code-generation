//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the grid and update the values of the cells
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Update the value of the current cell based on its neighbors
            grid[i][j].alive = (grid[i][j].alive && (grid[i][j - 1].alive || grid[i][j + 1].alive || grid[i - 1][j].alive || grid[i + 1][j].alive)) ? 1 : 0;
            // Increment the number of alive neighbors
            grid[i][j].neighbors_alive += (grid[i][j].alive && grid[i][j].neighbors_alive > 0) ? 1 : 0;
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
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
    cell_t** grid = calloc(WIDTH, sizeof(cell_t *));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }
    init_grid(grid);

    // Update and draw the grid in a loop
    while (1) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", (int)clock());
        sleep(1);
    }

    return 0;
}