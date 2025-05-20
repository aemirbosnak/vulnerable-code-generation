//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Number of sites
#define L 10 // Number of layers

int **grid; // The grid of sites
int top; // The topmost layer with water
int num_filled; // The number of filled sites

void init() {
    srand(time(NULL));
    grid = (int **) malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *) malloc(L * sizeof(int));
        for (int j = 0; j < L; j++) {
            grid[i][j] = rand() % 2; // Initialize with random water
        }
    }
    top = 0;
    num_filled = 0;
}

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= top; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < L;
}

int count_neighbors(int i, int j) {
    int count = 0;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0)
                continue;
            int ni = i + di, nj = j + dj;
            if (is_valid(ni, nj) && grid[ni][nj] == 1)
                count++;
        }
    }
    return count;
}

void percolate() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = top - 1; j >= 0; j--) {
            if (grid[i][j] == 1) {
                int neighbors = count_neighbors(i, j);
                if (neighbors < 2) {
                    grid[i][j] = 0;
                    num_filled--;
                }
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = top - 1; j >= 0; j--) {
            if (grid[i][j] == 0 && count_neighbors(i, j) == 3) {
                grid[i][j] = 1;
                num_filled++;
            }
        }
    }
    top++;
}

int main() {
    init();
    while (num_filled < N * L) {
        percolate();
        print_grid();
    }
    return 0;
}