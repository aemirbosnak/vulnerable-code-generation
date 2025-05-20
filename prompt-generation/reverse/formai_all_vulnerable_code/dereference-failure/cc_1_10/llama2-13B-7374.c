//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid) {
    int i, j, neighbor_count;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            neighbor_count = 0;
            if (i - 1 >= 0 && grid[i - 1][j].alive) {
                neighbor_count++;
            }
            if (i + 1 < WIDTH && grid[i + 1][j].alive) {
                neighbor_count++;
            }
            if (j - 1 >= 0 && grid[i][j - 1].alive) {
                neighbor_count++;
            }
            if (j + 1 < HEIGHT && grid[i][j + 1].alive) {
                neighbor_count++;
            }
            grid[i][j].neighbors_alive = neighbor_count;
            if (grid[i][j].alive && neighbor_count < 2 ||
                    !grid[i][j].alive && neighbor_count >= 2) {
                grid[i][j].alive = !grid[i][j].alive;
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
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize the random number generator
    cell_t** grid = calloc(WIDTH, sizeof(cell_t*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(cell_t));
    }
    init_grid(grid);
    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
        printf("Generation %d\n", i);
        sleep(1); // Pause for 1 second
    }
    return 0;
}