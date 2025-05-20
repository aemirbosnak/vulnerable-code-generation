//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of sites
#define M 100 // number of attempts
#define P 0.5 // probability of success

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

void destroy_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
}

void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int **grid, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if ((k == 0 && l == 0) || (k == 0 && l == 1) || (k == 1 && l == 0) || (k == 1 && l == -1)) {
                continue;
            }
            int x = i + k;
            int y = j + l;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                if (grid[x][y] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

void percolate(int **grid, int n) {
    srand(time(NULL));
    for (int i = 0; i < M; i++) {
        int x = rand() % N;
        int y = rand() % N;
        if (grid[x][y] == 0 && rand() % 100 < P) {
            grid[x][y] = 1;
        }
    }
}

int main() {
    int **grid = create_grid(N);
    percolate(grid, N);
    print_grid(grid, N);
    destroy_grid(grid, N);
    return 0;
}