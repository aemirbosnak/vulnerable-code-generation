//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10
#define GRID_SIZE (CELL_WIDTH * CELL_HEIGHT)
#define SPACESHIP_SPEED 3
#define ALIEN_SPEED 2

// Structure to represent a cell in the grid
typedef struct {
    int alive;
} cell_t;

// Function to draw the grid
void draw_grid(cell_t** grid) {
    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            if (grid[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to update the grid based on the game rules
void update_grid(cell_t** grid) {
    for (int i = 0; i < CELL_HEIGHT; i++) {
        for (int j = 0; j < CELL_WIDTH; j++) {
            // Check if the cell is alive and has neighbors that are alive
            if (grid[i][j].alive && (i > 0 && grid[i - 1][j].alive) && (i < CELL_HEIGHT - 1 && grid[i + 1][j].alive) && (j > 0 && grid[i][j - 1].alive) && (j < CELL_WIDTH - 1 && grid[i][j + 1].alive)) {
                // If the cell is alive and has enough alive neighbors, leave it alive
                grid[i][j].alive = 1;
            } else {
                // If the cell is alive but has no alive neighbors, die
                grid[i][j].alive = 0;
            }
        }
    }
}

// Function to handle user input and move the spaceship
void handle_input(cell_t** grid) {
    char key;
    printf("Press a key to move the spaceship (up, down, left, or right): ");
    scanf("%c", &key);

    // Move the spaceship based on the user input
    if (key == 'U') {
        for (int i = 0; i < CELL_HEIGHT; i++) {
            if (grid[i][0].alive) {
                grid[i][0].alive = 0;
                grid[i][1].alive = 1;
            }
        }
    } else if (key == 'D') {
        for (int i = 0; i < CELL_HEIGHT; i++) {
            if (grid[i][CELL_WIDTH - 1].alive) {
                grid[i][CELL_WIDTH - 1].alive = 0;
                grid[i][CELL_WIDTH - 2].alive = 1;
            }
        }
    } else if (key == 'L') {
        for (int i = 0; i < CELL_HEIGHT; i++) {
            if (grid[i][0].alive) {
                grid[i][0].alive = 0;
                grid[i][1].alive = 1;
            }
        }
    } else if (key == 'R') {
        for (int i = 0; i < CELL_HEIGHT; i++) {
            if (grid[i][CELL_WIDTH - 1].alive) {
                grid[i][CELL_WIDTH - 1].alive = 0;
                grid[i][CELL_WIDTH - 2].alive = 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the grid with random values
    cell_t** grid = (cell_t**) calloc(CELL_HEIGHT, sizeof(cell_t*));
    for (int i = 0; i < CELL_HEIGHT; i++) {
        grid[i] = (cell_t*) calloc(CELL_WIDTH, sizeof(cell_t));
        for (int j = 0; j < CELL_WIDTH; j++) {
            grid[i][j].alive = (rand() % 2) == 0;
        }
    }

    // Game loop
    while (1) {
        // Update the grid based on the game rules
        update_grid(grid);

        // Draw the grid
        draw_grid(grid);

        // Handle user input and move the spaceship
        handle_input(grid);

        // Sleep for a bit before updating the grid again
        sleep(1);
    }

    return 0;
}