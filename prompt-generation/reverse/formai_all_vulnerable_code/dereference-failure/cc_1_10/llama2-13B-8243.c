//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000

// Structure to represent a cell in the game of life
typedef struct {
    int alive;   // Whether the cell is alive or not
    int birth;  // When the cell was born (used for simulating the game)
} Cell;

// Function to generate a random initial state for the game
void init_state(Cell *grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i * height + j].alive = (rand() % 2) ? 1 : 0;
            grid[i * height + j].birth = (rand() % 1000) + 1; // random birth time
        }
    }
}

// Function to update the state of the game
void update_state(Cell *grid, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            // Check for alive neighbors
            int alive_neighbors = 0;
            if (i - 1 >= 0 && grid[i - 1 * height + j].alive) alive_neighbors++;
            if (i + 1 < width && grid[i + 1 * height + j].alive) alive_neighbors++;
            if (j - 1 >= 0 && grid[i * height + j - 1].alive) alive_neighbors++;
            if (j + 1 < height && grid[i * height + j + 1].alive) alive_neighbors++;

            // Update the cell's state based on the number of alive neighbors
            if (alive_neighbors == 2 || alive_neighbors == 3) {
                grid[i * height + j].alive = 1;
            } else if (alive_neighbors == 0 || alive_neighbors == 4) {
                grid[i * height + j].alive = 0;
            } else {
                grid[i * height + j].alive = grid[i * height + j].alive; // no change
            }
            grid[i * height + j].birth = 0; // reset birth time
        }
    }
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;
    Cell *grid = malloc(width * height * sizeof(Cell));
    init_state(grid, width, height);

    for (int i = 0; i < 100; i++) {
        update_state(grid, width, height);
        printf("Generation %d\n", i + 1);
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                if (grid[i * height + j].alive) {
                    printf("*");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }

    free(grid);
    return 0;
}