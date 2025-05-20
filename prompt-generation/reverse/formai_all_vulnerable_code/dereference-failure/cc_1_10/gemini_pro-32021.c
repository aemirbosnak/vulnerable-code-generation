//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defines the size of the grid
#define GRID_SIZE 20

// Defines the number of generations to simulate
#define NUM_GENERATIONS 100

// Creates a new grid with the given size
bool** create_grid(int size) {
    bool** grid = malloc(sizeof(bool*) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(bool) * size);
    }
    return grid;
}

// Frees the memory allocated for the grid
void free_grid(bool** grid, int size) {
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);
}

// Initializes the grid with a random pattern
void initialize_grid(bool** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Counts the number of alive neighbors of a given cell
int count_neighbors(bool** grid, int size, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = x + i;
            int ny = y + j;
            if (nx < 0 || nx >= size || ny < 0 || ny >= size) {
                continue;
            }
            count += grid[nx][ny];
        }
    }
    return count;
}

// Updates the grid according to the rules of the Game of Life
void update_grid(bool** grid, int size) {
    bool** new_grid = create_grid(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = count_neighbors(grid, size, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = false;
                } else {
                    new_grid[i][j] = true;
                }
            } else {
                if (neighbors == 3) {
                    new_grid[i][j] = true;
                } else {
                    new_grid[i][j] = false;
                }
            }
        }
    }

    free_grid(grid, size);
    grid = new_grid;
}

// Prints the grid to the console
void print_grid(bool** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%s ", grid[i][j] ? "O" : " ");
        }
        printf("\n");
    }
}

int main() {
    bool** grid = create_grid(GRID_SIZE);
    initialize_grid(grid, GRID_SIZE);

    for (int i = 0; i < NUM_GENERATIONS; i++) {
        printf("\nGeneration %d\n", i + 1);
        print_grid(grid, GRID_SIZE);
        update_grid(grid, GRID_SIZE);
    }

    free_grid(grid, GRID_SIZE);

    return 0;
}