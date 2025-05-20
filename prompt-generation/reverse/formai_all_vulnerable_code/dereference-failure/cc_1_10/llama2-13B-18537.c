//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int next;   // The next state of the cell (for the next iteration)
} cell_t;

// Function to create the game of life grid
void create_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) ? 1 : 0;
            grid[i][j].next = grid[i][j].alive;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (grid[i][j].alive && (grid[i][j].next == 1 || grid[i][j].next == 2)) {
                grid[i][j].next = 1;
            } else {
                // If the cell is alive and has less than two alive neighbors, die
                if (grid[i][j].alive && grid[i][j].next == 0) {
                    grid[i][j].next = 0;
                } else {
                    // If the cell is dead and has exactly three alive neighbors, come to life
                    if (!grid[i][j].alive && (grid[i][j].next == 2 || grid[i][j].next == 3)) {
                        grid[i][j].next = 1;
                    } else {
                        // Otherwise, keep the cell dead
                        grid[i][j].next = 0;
                    }
                }
            }
        }
    }
}

// Function to draw the game of life grid
void draw_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
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
    cell_t** grid;
    create_grid(&grid);
    update_grid(grid);
    draw_grid(grid);

    return 0;
}