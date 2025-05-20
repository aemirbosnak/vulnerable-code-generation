//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int state; // 0 for dead, 1 for alive
    int next_state; // The next state of the cell (used for simulation)
} Cell;

// Function to initialize the grid with random values
void init_grid(Cell** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].state = (rand() % 2) ? 1 : 0; // 50% chance of starting alive
            grid[i][j].next_state = grid[i][j].state; // Initialize next state as current state
        }
    }
}

// Function to update the grid based on the current state of the cells
void update_grid(Cell** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Check if the cell is alive and has two or three alive neighbors
            if (grid[i][j].state == 1 &&
                    (grid[i][j].next_state == 1 && // Alive and has two alive neighbors
                     (grid[i][j-1].state == 1 && grid[i][j+1].state == 1) || // Top and bottom neighbors are alive
                     (grid[i][j-1].state == 1 && grid[i][j+1].state == 0) || // Top neighbor is alive, bottom neighbor is dead
                     (grid[i][j-1].state == 0 && grid[i][j+1].state == 1) || // Bottom neighbor is alive, top neighbor is dead
                     (grid[i][j-1].state == 1 && grid[i][j+1].state == 1 && grid[i-1][j].state == 1) || // Left and right neighbors are alive
                     (grid[i][j-1].state == 1 && grid[i][j+1].state == 1 && grid[i+1][j].state == 1))) { // Left and right neighbors are alive
                grid[i][j].next_state = 1; // Cell will be alive in the next generation
            } else {
                grid[i][j].next_state = 0; // Cell will be dead in the next generation
            }
        }
    }
}

// Function to draw the grid
void draw_grid(Cell** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid[i][j].state == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    Cell** grid = (Cell**) malloc(sizeof(Cell*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (Cell*) malloc(sizeof(Cell) * HEIGHT);
    }
    init_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        sleep(1); // Simulate time passing
    }
    free(grid);
    return 0;
}