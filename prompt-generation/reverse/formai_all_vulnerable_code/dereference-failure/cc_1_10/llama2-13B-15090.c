//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct cell {
    int alive;
} cell;

// Function to generate the grid
void generate_grid(cell **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Initialize cell as alive with 50% chance
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if cell is alive and has 2 or 3 alive neighbors
            if (grid[i][j].alive && (grid[i][j - 1].alive || grid[i][j + 1].alive || grid[i - 1][j].alive || grid[i + 1][j].alive)) {
                // If so, keep the cell alive
                grid[i][j].alive = 1;
            } else {
                // If not, die of loneliness
                grid[i][j].alive = 0;
            }
        }
    }
}

// Main function
int main() {
    cell **grid = (cell **)malloc(WIDTH * HEIGHT * sizeof(cell));
    generate_grid(grid);
    for (int i = 0; i < 10; i++) {
        apply_rules(grid);
        // Print the current state of the grid
        for (int j = 0; j < WIDTH; j++) {
            for (int k = 0; k < HEIGHT; k++) {
                printf("%d ", grid[j][k].alive);
            }
            printf("\n");
        }
        // Sleep for 1 second to let the game evolve
        sleep(1);
    }
    free(grid);
    return 0;
}