//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;    // Whether the cell is alive or not
    int births;   // Number of times the cell has born
    int deaths;  // Number of times the cell has died
} cell_t;

// Function to initialize the grid with random data
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].births = 0;
            grid[i][j].deaths = 0;
        }
    }
}

// Function to apply the Game of Life rules to the grid
void update_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two or three alive neighbors, keep it alive
            if (grid[i][j].alive && (grid[i][j].births + grid[i][j].deaths) % 2 == 0) {
                grid[i][j].alive = 1;
            } else {
                // If the cell is alive and has less than two alive neighbors, die
                if (grid[i][j].alive && grid[i][j].births + grid[i][j].deaths == 1) {
                    grid[i][j].alive = 0;
                }
                // If the cell is alive and has more than three alive neighbors, die
                else if (grid[i][j].alive && grid[i][j].births + grid[i][j].deaths > 3) {
                    grid[i][j].alive = 0;
                }
                // If the cell is dead and has three alive neighbors, come to life
                else if (!grid[i][j].alive && grid[i][j].births + grid[i][j].deaths == 3) {
                    grid[i][j].alive = 1;
                }
            }
            grid[i][j].births += grid[i][j].alive;
            grid[i][j].deaths += grid[i][j].alive;
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid;
    srand(time(NULL));
    init_grid(&grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        print_grid(grid);
    }
    return 0;
}