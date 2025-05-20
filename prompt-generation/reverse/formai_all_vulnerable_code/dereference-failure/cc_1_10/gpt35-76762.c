//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define THRESHOLD 0.6 // probability threshold for percolation

// grid object
typedef struct Grid {
    int size;
    int **contents;
} Grid;

// function to initialize grid with all cells set to zero
void initialize_grid(Grid *grid) {
    int i, j;
    for (i = 0; i < grid->size; i++) {
        for (j = 0; j < grid->size; j++) {
            grid->contents[i][j] = 0;
        }
    }
}

// function to print out contents of grid
void print_grid(Grid *grid) {
    int i, j;
    for (i = 0; i < grid->size; i++) {
        for (j = 0; j < grid->size; j++) {
            printf("%d ", grid->contents[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to generate random float between 0.0 and 1.0
float generate_random_float() {
    return (float) rand() / (float) RAND_MAX;
}

// function to check if a grid site can be connected to the top row
int is_connected_to_top(Grid *grid, int row, int col) {
    if (row == 0) {
        return 1;
    }
    if ((row - 1) >= 0 && grid->contents[row - 1][col] == 1) {
        return 1;
    }
    if ((col - 1) >= 0 && grid->contents[row][col - 1] == 1) {
        return 1;
    }
    if ((col + 1) < grid->size && grid->contents[row][col + 1] == 1) {
        return 1;
    }
    return 0;
}

// function to check if the grid percolates
int does_percolate(Grid *grid) {
    int i, j;
    for (j = 0; j < grid->size; j++) {
        if (grid->contents[grid->size - 1][j] == 1 && is_connected_to_top(grid, grid->size - 1, j)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Grid grid;
    grid.size = SIZE;
    grid.contents = malloc(sizeof(int*) * grid.size);
    int i, j;
    for (i = 0; i < grid.size; i++) {
        grid.contents[i] = malloc(sizeof(int) * grid.size);
    }
    srand(time(NULL));
    initialize_grid(&grid);
    // loop through each cell and determine if it should be open (populated with 1)
    for (i = 0; i < grid.size; i++) {
        for (j = 0; j < grid.size; j++) {
            float random_number = generate_random_float();
            if (random_number < THRESHOLD) {
                grid.contents[i][j] = 1;
            }
        }
    }
    printf("Initial Grid:\n");
    print_grid(&grid);
    printf("Does the grid percolate? %s\n", does_percolate(&grid) ? "Yes" : "No");
    return 0;
}