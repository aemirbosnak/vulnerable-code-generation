//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define M 1000
#define P 0.5

int **create_grid(int n, int m) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void percolation(int **grid, int n, int m, double p) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                int k = rand() % 3 + 1;
                int x = i + k - 1;
                int y = j + k - 1;
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                    grid[i][j] = 1;
                    count++;
                }
            }
        }
    }
    printf("The number of clusters is %d\n", count);
}

int main() {
    srand(time(NULL));
    int **grid = create_grid(N, M);
    percolation(grid, N, M, P);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}