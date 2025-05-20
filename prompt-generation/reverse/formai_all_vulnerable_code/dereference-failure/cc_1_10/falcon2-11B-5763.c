//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void print_grid(int **grid, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_alive(int **grid, int rows, int cols, int x, int y) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == x && j == y)
                continue;
            if (grid[i][j] == 1)
                count++;
        }
    }
    return count == 3 || count == 2 && grid[x][y] == 1;
}

void next_generation(int **grid, int rows, int cols) {
    int new_grid[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0)
                        continue;
                    int x = i + k;
                    int y = j + l;
                    if (x >= 0 && x < rows && y >= 0 && y < cols)
                        neighbors++;
                }
            }
            if (grid[i][j] == 1)
                new_grid[i][j] = (neighbors == 2 || neighbors == 3);
            else
                new_grid[i][j] = (neighbors == 3);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int rows = 10;
    int cols = 10;
    int **grid = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(int));
    }
    int max_rows = 100;
    int max_cols = 100;
    int max_iters = 100;
    int max_gen = 1;
    int *c = malloc(sizeof(int));
    c[0] = rows;
    c[1] = cols;
    c[2] = max_rows;
    c[3] = max_cols;
    c[4] = max_iters;
    c[5] = max_gen;
    for (int i = 0; i < max_iters; i++) {
        print_grid(grid, rows, cols);
        next_generation(grid, rows, cols);
        if (i == 0) {
            printf("\nGeneration %d:\n", i);
        }
        else {
            printf("\nGeneration %d:\n", i);
        }
        if (i == max_iters - 1) {
            printf("\n\nFinal Generation:\n");
        }
    }
    return 0;
}