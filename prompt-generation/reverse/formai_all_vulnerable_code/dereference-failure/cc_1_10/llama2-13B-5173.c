//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive[WIDTH * HEIGHT];  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life grid
void init_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
            grid[i][j].neighbors_alive[0] = (i == 0 || grid[i][j].alive) && (j == 0 || grid[i][j].alive);
            grid[i][j].neighbors_alive[1] = (i == WIDTH - 1 || grid[i][j].alive) && (j == HEIGHT - 1 || grid[i][j].alive);
            grid[i][j].neighbors_alive[2] = (i == 0 || grid[i][j].alive) && (j == 0 || grid[i][j].alive);
            grid[i][j].neighbors_alive[3] = (i == WIDTH - 1 || grid[i][j].alive) && (j == HEIGHT - 1 || grid[i][j].alive);
        }
    }
}

// Function to update the game of life grid
void update_grid(cell_t** grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            int alive_neighbors = 0;

            // Count the number of alive neighbors
            for (int k = 0; k < 4; k++) {
                if (grid[i][j].neighbors_alive[k]) {
                    alive_neighbors++;
                }
            }

            // Update the cell's state based on the number of alive neighbors
            if (alive_neighbors < 2 && grid[i][j].alive) {
                grid[i][j].alive = 0;
            } else if (alive_neighbors > 3 && grid[i][j].alive) {
                grid[i][j].alive = 0;
            } else if (alive_neighbors == 2 && grid[i][j].alive) {
                grid[i][j].alive = 1;
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
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t** grid = (cell_t**) malloc(sizeof(cell_t*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = (cell_t*) malloc(sizeof(cell_t) * HEIGHT);
    }

    init_grid(grid);

    for (int i = 0; i < 100; i++) {
        update_grid(grid);
        draw_grid(grid);
    }

    return 0;
}