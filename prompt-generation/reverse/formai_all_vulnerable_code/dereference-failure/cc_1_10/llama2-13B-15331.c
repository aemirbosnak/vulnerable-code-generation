//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the grid
typedef struct {
    int alive;   // Whether the cell is alive or not
    int born;   // Whether the cell was born this generation
} cell_t;

// Function to initialize the grid with random data
void init_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j].alive = rand() % 2;
            grid[i][j].born = 0;
        }
    }
}

// Function to apply the Game of Life rules
void apply_rules(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // If the cell is alive and has two or three alive neighbors, keep it alive
            if (grid[i][j].alive && (grid[i][j].born || grid[i][j].alive == 2) && grid[i][j].alive == 1) {
                grid[i][j].alive = 1;
            }
            // If the cell is alive and has less than two alive neighbors, die
            else if (grid[i][j].alive && grid[i][j].born == 0) {
                grid[i][j].alive = 0;
            }
            // If the cell is dead and has exactly three alive neighbors, come to life
            else if (!grid[i][j].alive && grid[i][j].born == 0 && grid[i][j].alive == 0) {
                grid[i][j].alive = 1;
            }
        }
    }
}

// Function to display the grid
void display_grid(cell_t** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].alive) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Set the random seed

    // Create a 10x10 grid
    cell_t** grid = calloc(10, sizeof(cell_t*));
    for (int i = 0; i < 10; i++) {
        grid[i] = calloc(10, sizeof(cell_t));
    }

    // Initialize the grid with random data
    init_grid(grid, 10);

    // Set the timer
    clock_t start = clock();

    // Apply the Game of Life rules for 100 generations
    for (int i = 0; i < 100; i++) {
        apply_rules(grid, 10);
    }

    // Calculate the score
    int score = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j].alive) {
                score++;
            }
        }
    }

    // Display the final grid and the score
    display_grid(grid, 10);
    printf("Score: %d\n", score);

    // Get the elapsed time
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    // Free the memory
    for (int i = 0; i < 10; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}