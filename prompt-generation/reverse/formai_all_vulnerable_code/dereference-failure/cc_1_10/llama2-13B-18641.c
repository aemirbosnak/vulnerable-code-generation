//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Global variables
const int WIDTH = 800;
const int HEIGHT = 600;
const int CELL_SIZE = 20;
const int MAX_GENERATIONS = 100;
const int STARTING_CELLS = 200;

// Structure to represent a cell
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors;  // Number of alive neighbors
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
        for (int j = 0; j < height; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors = 0;
        }
    }
    return grid;
}

// Function to update the cells
void update_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= WIDTH || j + l < 0 || j + l >= HEIGHT) {
                        continue;
                    }
                    alive_neighbors += grid[i + k][j + l].alive;
                }
            }
            grid[i][j].neighbors = alive_neighbors;
            if (grid[i][j].alive && grid[i][j].neighbors < 2) {
                grid[i][j].alive = 0;  // If a cell is alive and has less than 2 alive neighbors, it dies
            } else if (!grid[i][j].alive && grid[i][j].neighbors >= 3) {
                grid[i][j].alive = 1;  // If a cell is dead and has exactly 3 alive neighbors, it becomes alive
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("X");  // Draw a 'X' if the cell is alive
            } else {
                printf(" ");  // Draw a space if the cell is dead
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = create_grid(WIDTH, HEIGHT);
    for (int i = 0; i < MAX_GENERATIONS; i++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", i + 1);
        sleep(1);  // Wait for 1 second before updating and drawing again
    }
    return 0;
}