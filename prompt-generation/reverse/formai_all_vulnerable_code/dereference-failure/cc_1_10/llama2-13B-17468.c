//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 2)
#define WINDOW_HEIGHT (CELL_SIZE * 2)

// Structure to represent a cell in the game of life
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to draw the game of life grid
void draw_grid(cell_t **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].alive) {
                printf("O"); // Draw alive cell as 'O'
            } else {
                printf("."); // Draw dead cell as '.'
            }
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t **grid, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculate the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue; // Skip diagonals
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }
            // Apply the rules
            if (grid[i][j].alive && neighbors_alive < 2) {
                grid[i][j].alive = 0; // Underpopulation
            } else if (!grid[i][j].alive && neighbors_alive >= 2) {
                grid[i][j].alive = 1; // Overpopulation
            }
        }
    }
}

int main() {
    // Create the grid
    cell_t **grid = (cell_t **)malloc(WINDOW_HEIGHT * sizeof(cell_t *));
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        grid[i] = (cell_t *)malloc(WINDOW_WIDTH * sizeof(cell_t));
    }
    // Initialize the grid with random values
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        for (int j = 0; j < WINDOW_WIDTH; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
    // Draw the grid
    draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    // Apply the rules
    apply_rules(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    // Draw the updated grid
    draw_grid(grid, WINDOW_WIDTH, WINDOW_HEIGHT);
    // Free memory
    for (int i = 0; i < WINDOW_HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}