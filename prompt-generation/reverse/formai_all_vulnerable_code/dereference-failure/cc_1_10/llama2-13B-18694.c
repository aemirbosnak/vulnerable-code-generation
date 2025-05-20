//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the grid
typedef struct {
    int state; // 0 for dead, 1 for alive
    int neighbors; // Number of alive neighbors
} cell_t;

// Function to initialize the grid with random values
void init_grid(cell_t **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int random_state = rand() % 2;
            grid[i][j].state = random_state;
            grid[i][j].neighbors = 0;
        }
    }
}

// Function to apply the Game of Life rules
void apply_rules(cell_t **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Count the number of alive neighbors
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (grid[i + k][j + l].state == 1) {
                        neighbors++;
                    }
                }
            }
            
            // Apply the rules based on the number of alive neighbors
            if (grid[i][j].state == 0 && neighbors > 1) {
                grid[i][j].state = 1; // If one alive neighbor, cell becomes alive
            } else if (grid[i][j].state == 1 && neighbors < 2) {
                grid[i][j].state = 0; // If no alive neighbors, cell dies
            } else if (grid[i][j].state == 1 && neighbors == 2) {
                grid[i][j].state = 1; // If two alive neighbors, cell stays alive
            }
            grid[i][j].neighbors = neighbors;
        }
    }
}

// Main function
int main() {
    // Initialize the grid with random values
    cell_t **grid = (cell_t **) malloc(sizeof(cell_t *) * 10);
    for (int i = 0; i < 10; i++) {
        grid[i] = (cell_t *) malloc(sizeof(cell_t) * 10);
    }
    init_grid(grid, 10);

    // Apply the Game of Life rules for 100 generations
    for (int i = 0; i < 100; i++) {
        apply_rules(grid, 10);
    }

    // Print the final state of the grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j].state);
        }
        printf("\n");
    }

    return 0;
}