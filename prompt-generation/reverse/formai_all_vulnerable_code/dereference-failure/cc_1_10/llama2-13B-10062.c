//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the grid
typedef struct cell {
    int x;
    int y;
    int alive;
} cell_t;

// Function to generate the grid
void generate_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }
}

// Function to apply the game of life rules
void apply_rules(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].alive && (grid[i][j].alive == grid[i][j + 1].alive) && (grid[i][j].alive == grid[i][j - 1].alive) && (grid[i][j].alive == grid[i + 1][j].alive) && (grid[i][j].alive == grid[i - 1][j].alive)) {
                // If the cell is alive and has two or three alive neighbors, it stays alive
                grid[i][j].alive = 1;
            } else {
                // If the cell is alive and has fewer than two alive neighbors, it dies
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to display the grid
void display_grid(cell_t **grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].alive) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t **grid;
    srand(time(NULL));

    // Generate the grid
    generate_grid(&grid);

    // Apply the game of life rules
    apply_rules(grid);

    // Display the grid
    display_grid(grid);

    return 0;
}