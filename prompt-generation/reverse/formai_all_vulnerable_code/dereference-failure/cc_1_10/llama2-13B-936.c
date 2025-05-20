//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024

// Structure to represent a cell in the game of life
typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

// Function to create a 2D array of cells
cell_t** create_grid(int width, int height) {
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
    return grid;
}

// Function to update the state of the cells
void update_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].alive && (grid[i][j].alive == grid[i][j-1].alive) && (grid[i][j].alive == grid[i][j+1].alive) && (grid[i][j].alive == grid[i-1][j].alive) && (grid[i][j].alive == grid[i+1][j].alive)) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                grid[i][j].alive = 1;
            } else {
                // If the cell is alive and has fewer than two alive neighbors, die
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    cell_t** grid = create_grid(WIDTH, HEIGHT);
    update_grid(grid);
    draw_grid(grid);
    return 0;
}