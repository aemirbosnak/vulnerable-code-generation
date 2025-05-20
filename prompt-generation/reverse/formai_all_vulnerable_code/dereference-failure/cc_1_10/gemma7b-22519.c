//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define GRID_SIZE 20
#define FILL_PERCENTAGE 50

// Define the grid structure
typedef struct Grid {
    int **data;
    int rows;
    int cols;
} Grid;

// Function to create a new grid
Grid* create_grid(int rows, int cols) {
    Grid* grid = malloc(sizeof(Grid));
    grid->rows = rows;
    grid->cols = cols;
    grid->data = malloc(rows * cols * sizeof(int));
    return grid;
}

// Function to percolate the grid
void percolate(Grid* grid) {
    int i, j, x, y;
    srand(time(NULL));
    for (i = 0; i < grid->rows; i++) {
        for (j = 0; j < grid->cols; j++) {
            // Randomly fill the cell
            if (rand() % 100 < FILL_PERCENTAGE) {
                grid->data[i][j] = 1;
            } else {
                grid->data[i][j] = 0;
            }
        }
    }
}

// Function to display the grid
void display_grid(Grid* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%d ", grid->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Grid* grid = create_grid(GRID_SIZE, GRID_SIZE);
    percolate(grid);
    display_grid(grid);
    free(grid);
    return 0;
}