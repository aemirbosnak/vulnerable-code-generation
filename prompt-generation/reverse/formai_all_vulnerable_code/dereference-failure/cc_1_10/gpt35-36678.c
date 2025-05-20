//FormAI DATASET v1.0 Category: Fractal Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void randomize_grid(int**, int);
void print_grid(int**, int);
void generate_fractal(int**, int, int, int);

int main() {

    srand(time(NULL)); // initialize random seed

    int size = 33; // size of grid (must be 2^n + 1)
    int* temp = calloc(size * size, sizeof(int)); // allocate memory for 2D array
    int** grid = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        grid[i] = &temp[i * size];
    }

    randomize_grid(grid, size);
    generate_fractal(grid, size, 0, 0);
    print_grid(grid, size);

    free(grid[0]);
    free(grid);

    return 0;
}

/**
 * Randomly assigns initial values for the corners of the grid
 **/
void randomize_grid(int** grid, int size) {
    grid[0][0] = rand() % 100;
    grid[0][size - 1] = rand() % 100;
    grid[size - 1][0] = rand() % 100;
    grid[size - 1][size - 1] = rand() % 100;
}

/**
 * Recursively generates a fractal by averaging corner values
 **/
void generate_fractal(int** grid, int size, int x, int y) {

    int half = (size - 1) / 2;
    int avg = (grid[x][y] + grid[x + size - 1][y] + grid[x][y + size - 1] + grid[x + size - 1][y + size - 1]) / 4;
    grid[x + half][y + half] = avg + (rand() % 20 - 10);

    if (half > 1) {
        generate_fractal(grid, half + 1, x, y);
        generate_fractal(grid, half + 1, x + half, y);
        generate_fractal(grid, half + 1, x, y + half);
        generate_fractal(grid, half + 1, x + half, y + half);
    }
}

/**
 * Prints the grid with ASCII art
 **/
void print_grid(int** grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] > 80) {
                printf("**");
            } else if (grid[i][j] > 60) {
                printf("++");
            } else if (grid[i][j] > 40) {
                printf("--");
            } else if (grid[i][j] > 20) {
                printf("~~");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}