//FormAI DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLUMNS 80

// function to generate a random grid of cells
void generate_grid(int **grid) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// function to print the grid
void print_grid(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors around a cell
int count_neighbors(int **grid, int row, int column) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_column = column + j;
            if (neighbor_row >= 0 && neighbor_row < ROWS && neighbor_column >= 0 && neighbor_column < COLUMNS && !(i == 0 && j == 0)) {
                count += grid[neighbor_row][neighbor_column];
            }
        }
    }
    return count;
}

// function to update the grid for the next generation
void update_grid(int **grid) {
    int **new_grid = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        new_grid[i] = malloc(COLUMNS * sizeof(int));
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
    for (int i = 0; i < ROWS; i++) {
        free(new_grid[i]);
    }
    free(new_grid);
}

// main function
int main() {
    int **grid = malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = malloc(COLUMNS * sizeof(int));
    }
    generate_grid(grid);
    while (1) {
        system("cls||clear");
        print_grid(grid);
        update_grid(grid);
        printf("Press any key to continue... (or press Ctrl + C to quit)\n");
        getchar();
    }
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}