//GPT-4o-mini DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ALIVE 'O'
#define DEAD '.'

// Function declarations
char **create_grid(int rows, int cols);
void destroy_grid(char **grid, int rows);
void initialize_grid(char **grid, int rows, int cols);
void display_grid(char **grid, int rows, int cols);
void update_grid(char **current, char **next, int rows, int cols);
int count_neighbors(char **grid, int row, int col, int rows, int cols);
void copy_grid(char **source, char **destination, int rows, int cols);

int main() {
    int rows = 20, cols = 40;
    
    // Create grids for current and next generation
    char **current = create_grid(rows, cols);
    char **next = create_grid(rows, cols);
    
    // Initialize the grid
    initialize_grid(current, rows, cols);
    
    // Game loop
    while (1) {
        // Display current grid
        display_grid(current, rows, cols);
        
        // Update to the next generation
        update_grid(current, next, rows, cols);
        
        // Copy next generation to current
        copy_grid(next, current, rows, cols);
        
        usleep(200000); // Sleep for 200 milliseconds
    }
    
    // Free allocated memory
    destroy_grid(current, rows);
    destroy_grid(next, rows);
    
    return 0;
}

char **create_grid(int rows, int cols) {
    char **grid = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(char));
    }
    return grid;
}

void destroy_grid(char **grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

void initialize_grid(char **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2) ? ALIVE : DEAD; // Randomly populate
        }
    }
}

void display_grid(char **grid, int rows, int cols) {
    // ANSI escape code to clear the console
    printf("\033[H\033[J");
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            putchar(grid[i][j]);
        }
        putchar('\n');
    }
}

void update_grid(char **current, char **next, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int alive_neighbors = count_neighbors(current, i, j, rows, cols);
            if (current[i][j] == ALIVE) {
                // Rule 1 and 3
                next[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
            } else {
                // Rule 4
                next[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
            }
        }
    }
}

int count_neighbors(char **grid, int row, int col, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int new_row = row + i;
            int new_col = col + j;
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols) {
                if (grid[new_row][new_col] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void copy_grid(char **source, char **destination, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            destination[i][j] = source[i][j];
        }
    }
}