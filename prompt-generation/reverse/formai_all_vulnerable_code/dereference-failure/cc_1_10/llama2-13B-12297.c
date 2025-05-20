//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a cell in the grid
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t** grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the rules of the Game of Life
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
            
            // Apply the rules of the Game of Life
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1; // Stay alive if there are 2 or 3 alive neighbors
            } else if (grid[i][j].alive && neighbors_alive < 2) {
                grid[i][j].alive = 0; // Die if there is only one alive neighbor
            } else if (!grid[i][j].alive && neighbors_alive >= 3) {
                grid[i][j].alive = 1; // Come to life if there are 3 or more dead neighbors
            }
        }
    }
}

// Function to draw the grid
void draw_grid(cell_t** grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (grid[i][j].alive) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    cell_t** grid = malloc(width * sizeof(cell_t*));
    for (int i = 0; i < width; i++) {
        grid[i] = malloc(height * sizeof(cell_t));
    }
    
    init_grid(grid, width, height);
    
    // Main game loop
    while (1) {
        update_grid(grid, width, height);
        draw_grid(grid, width, height);
        printf("Press enter to continue...");
        getchar();
    }
    
    return 0;
}