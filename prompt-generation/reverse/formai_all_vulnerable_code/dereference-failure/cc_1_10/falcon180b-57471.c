//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define P 0.5
#define T 100

int **create_grid();
void percolate(int **grid);
void print_grid(int **grid);

int main() {
    srand(time(NULL));
    int **grid = create_grid();
    percolate(grid);
    print_grid(grid);
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    return grid;
}

void percolate(int **grid) {
    int x, y, count = 0;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    while (count < T) {
        x = rand() % N;
        y = rand() % N;
        if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
            continue;
        }
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            count++;
        }
    }
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}