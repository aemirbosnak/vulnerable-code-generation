//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_grid(int n) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void initialize_grid(int **grid, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 2 == 1) {
                grid[i][j] = 1;
            }
        }
    }
}

void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int check_neighbors(int **grid, int i, int j, int n) {
    int count = 0;
    if (i > 0 && grid[i - 1][j] == 1) {
        count++;
    }
    if (i < n - 1 && grid[i + 1][j] == 1) {
        count++;
    }
    if (j > 0 && grid[i][j - 1] == 1) {
        count++;
    }
    if (j < n - 1 && grid[i][j + 1] == 1) {
        count++;
    }
    return count;
}

void percolate_grid(int **grid, int n) {
    int **new_grid = create_grid(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int neighbors = check_neighbors(grid, i, j, n);
                if (neighbors == 1) {
                    new_grid[i][j] = 1;
                } else if (neighbors > 1) {
                    new_grid[i][j] = 0;
                }
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter grid size: ");
    scanf("%d", &n);
    int **grid = create_grid(n);
    initialize_grid(grid, n);
    int iterations = 0;
    while (iterations < 100) {
        print_grid(grid, n);
        percolate_grid(grid, n);
        iterations++;
    }
    return 0;
}