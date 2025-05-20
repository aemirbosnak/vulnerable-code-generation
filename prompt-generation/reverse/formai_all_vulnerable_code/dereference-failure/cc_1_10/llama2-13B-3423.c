//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the grid
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void initialize_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the grid based on the rules of the Game of Life
void update_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Count the number of alive neighbors
            int neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0 || i + k < 0 || i + k >= WIDTH || j + l < 0 || j + l >= HEIGHT) {
                        continue;
                    }
                    if (grid[i + k][j + l].alive) {
                        neighbors_alive++;
                    }
                }
            }

            // Apply the rules of the Game of Life
            if (grid[i][j].alive && neighbors_alive >= 2 && neighbors_alive <= 3) {
                grid[i][j].alive = 1; // Stay alive if there are 2-3 alive neighbors
            } else if (!grid[i][j].alive && neighbors_alive == 3) {
                grid[i][j].alive = 1; // Be born if there are 3 alive neighbors
            } else {
                grid[i][j].alive = 0; // Die if there are less than 2 or more than 3 alive neighbors
            }
        }
    }
}

// Function to print the grid
void print_grid(cell_t** grid) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", grid[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    initialize_grid(grid);

    for (int generation = 0; generation < 10; generation++) {
        update_grid(grid);
        print_grid(grid);
        printf("Generation %d\n", generation);
        sleep(1); // Pause for 1 second before updating the grid again
    }

    free(grid);
    return 0;
}