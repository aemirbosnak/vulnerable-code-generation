//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a game of life grid
typedef struct {
    int rows;
    int cols;
    int **grid;
} game_of_life_t;

// Function to create a new game of life grid
game_of_life_t *new_game_of_life(int rows, int cols) {
    game_of_life_t *grid = malloc(sizeof(game_of_life_t));
    grid->rows = rows;
    grid->cols = cols;
    grid->grid = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid->grid[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid->grid[i][j] = 0; // Initialize all cells to 0
        }
    }
    return grid;
}

// Function to update the game of life grid
void update_game_of_life(game_of_life_t *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            // Check if the cell is alive
            if (grid->grid[i][j] == 1) {
                // If alive, apply the rules
                if (i < grid->rows - 1 && grid->grid[i + 1][j] == 1) { // North
                    grid->grid[i][j] = 1; // Alive
                } else if (i > 0 && grid->grid[i - 1][j] == 1) { // South
                    grid->grid[i][j] = 1; // Alive
                } else if (j < grid->cols - 1 && grid->grid[i][j + 1] == 1) { // East
                    grid->grid[i][j] = 1; // Alive
                } else if (j > 0 && grid->grid[i][j - 1] == 1) { // West
                    grid->grid[i][j] = 1; // Alive
                } else {
                    grid->grid[i][j] = 0; // Die
                }
            }
        }
    }
}

// Function to print the game of life grid
void print_game_of_life(game_of_life_t *grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new game of life grid with 20 rows and 20 cols
    game_of_life_t *grid = new_game_of_life(20, 20);

    // Initialize the grid with random values
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            grid->grid[i][j] = rand() % 2;
        }
    }

    // Update the grid for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        update_game_of_life(grid);
    }

    // Print the final grid
    print_game_of_life(grid);

    // Free the memory
    free(grid->grid);
    free(grid);

    return 0;
}