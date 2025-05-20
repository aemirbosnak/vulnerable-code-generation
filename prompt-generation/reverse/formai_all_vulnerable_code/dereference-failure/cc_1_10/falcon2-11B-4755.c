//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CELLS 100
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// The states of a cell in the game of life
typedef enum {
    ALIVE = 1,
    DEAD = 0
} State;

int width = MAX_WIDTH;
int height = MAX_HEIGHT;

State** grid = NULL;

// Initialize the grid with random states
void init_grid() {
    grid = (State**)malloc(height * sizeof(State*));
    for (int i = 0; i < height; i++) {
        grid[i] = (State*)malloc(width * sizeof(State));
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2 == 0? ALIVE : DEAD;
        }
    }
}

// Update the grid based on the rules of the game of life
void update_grid() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int live_neighbors = 0;

            // Count the number of live neighbors
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; // Skip the cell itself
                    int neighbor_i = i + x;
                    int neighbor_j = j + y;
                    if (neighbor_i < 0 || neighbor_i >= height || neighbor_j < 0 || neighbor_j >= width) continue;
                    if (grid[neighbor_i][neighbor_j] == ALIVE) live_neighbors++;
                }
            }

            // Apply the rules of the game of life
            if (grid[i][j] == ALIVE) {
                if (live_neighbors < 2 || live_neighbors > 3) grid[i][j] = DEAD;
            } else {
                if (live_neighbors == 3) grid[i][j] = ALIVE;
            }
        }
    }
}

// Print the current state of the grid
void print_grid() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init_grid();

    while (1) {
        update_grid();
        print_grid();
    }

    return 0;
}