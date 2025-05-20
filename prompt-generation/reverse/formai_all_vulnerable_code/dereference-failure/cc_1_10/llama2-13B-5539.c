//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct cell {
    int state; // 0 for dead, 1 for alive
    int next_state; // Next state of the cell
} cell_t;

// Function to generate the game of life grid
void generate_grid(cell_t** grid) {
    int i, j;

    // Initialize the grid with random states
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].state = rand() % 2;
            grid[i][j].next_state = grid[i][j].state;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid) {
    int i, j;

    // Loop through each cell in the grid
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].state == 1 &&
                    (grid[i][j].next_state == 1 && // Alive and has two alive neighbors
                     (grid[i][j].next_state == 1 && // Alive and has three alive neighbors
                      grid[i][j].next_state == 1)) || // Dead and has three alive neighbors
                    (grid[i][j].next_state == 1 && // Alive and has two dead neighbors
                     (grid[i][j].next_state == 0 && // Dead and has three dead neighbors
                      grid[i][j].next_state == 0))) {
                grid[i][j].next_state = 1 - grid[i][j].state;
            } else {
                grid[i][j].next_state = grid[i][j].state;
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid) {
    int i, j;

    // Loop through each cell in the grid
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].state == 1) {
                printf("O ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    generate_grid(grid);
    update_grid(grid);
    draw_grid(grid);
    free(grid);
    return 0;
}