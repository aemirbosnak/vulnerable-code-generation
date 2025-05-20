//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int **create_grid(int n);
void percolate(int **grid, int n);
int count_neighbors(int **grid, int i, int j);
int main() {
    int **grid = create_grid(N);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    percolate(grid, N);
    return 0;
}

int **create_grid(int n) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }
    return grid;
}

void percolate(int **grid, int n) {
    int top = 0, bottom = n - 1;
    while (top < bottom) {
        for (int i = 0; i < n; i++) {
            if (grid[top][i] == 1) {
                grid[top][i] = 0;
                grid[bottom][i] = 1;
                bottom--;
            }
        }
        top++;
    }
}

int count_neighbors(int **grid, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if ((i + k >= 0 && i + k < N) && (j + l >= 0 && j + l < N)) {
                count += grid[i + k][j + l];
            }
        }
    }
    return count;
}