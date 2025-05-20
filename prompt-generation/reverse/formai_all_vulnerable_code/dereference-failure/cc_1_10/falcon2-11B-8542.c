//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **grid;
} Grid;

void generate_grid(Grid *grid, int size) {
    grid->rows = size;
    grid->cols = size;
    grid->grid = (int **)malloc(sizeof(int *) * grid->rows);
    for (int i = 0; i < grid->rows; i++) {
        grid->grid[i] = (int *)malloc(sizeof(int) * grid->cols);
    }

    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            grid->grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(Grid grid) {
    for (int i = 0; i < grid.rows; i++) {
        for (int j = 0; j < grid.cols; j++) {
            printf("%d ", grid.grid[i][j]);
        }
        printf("\n");
    }
}

int is_connected(Grid grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.rows || j >= grid.cols) {
        return 0;
    }

    if (grid.grid[i][j] == 1) {
        return 1;
    }

    return is_connected(grid, i - 1, j) || is_connected(grid, i + 1, j) ||
            is_connected(grid, i, j - 1) || is_connected(grid, i, j + 1);
}

int main() {
    srand(time(0));

    int size = 100;
    Grid grid;
    generate_grid(&grid, size);

    printf("Initial grid:\n");
    print_grid(grid);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (is_connected(grid, i, j)) {
                grid.grid[i][j] = 1;
            }
        }
    }

    printf("Final grid:\n");
    print_grid(grid);

    return 0;
}