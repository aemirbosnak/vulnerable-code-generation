//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // number of sites
#define T 10 // number of iterations

int **create_grid(int n) {
    int **grid = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void free_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

int count_neighbors(int **grid, int i, int j) {
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if ((x == 0 && y == 0) || (x == -1 && y == -1) || (x == 1 && y == 1)) {
                continue;
            }
            int nx = i + x;
            int ny = j + y;
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}

void percolate(int **grid, int n) {
    srand(time(NULL));
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int neighbors = count_neighbors(grid, i, j);
                if (neighbors == 3 && grid[i][j] == 0) {
                    grid[i][j] = 1;
                } else if (neighbors < 2 && grid[i][j] == 1) {
                    grid[i][j] = 0;
                }
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

int main() {
    int **grid = create_grid(N);
    percolate(grid, N);
    print_grid(grid, N);
    free_grid(grid, N);
    return 0;
}