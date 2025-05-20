//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 100
#define P 0.5

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

void print_grid(int **grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void percolate(int **grid, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = 2;
                count++;
            }
        }
    }
    printf("Number of sites percolated: %d\n", count);
}

int main() {
    srand(time(NULL));
    int **grid = create_grid(N);
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rand() % 100 < P) {
                grid[i][j] = 1;
                count++;
            }
        }
    }
    printf("Initial grid:\n");
    print_grid(grid, N);
    percolate(grid, N);
    return 0;
}