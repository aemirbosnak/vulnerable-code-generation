//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // Number of sites
#define T 100 // Number of time steps
#define P 0.5 // Probability of a site being open

int **grid; // The grid of sites
int top; // The topmost open site
int num_open; // The number of open sites
int num_closed; // The number of closed sites
int *status; // The status of each site (open or closed)

void init() {
    grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = -1;
        }
    }
    top = -1;
    num_open = 0;
    num_closed = N * N;
    status = (int *)malloc(N * N * sizeof(int));
    for (int i = 0; i < N * N; i++) {
        status[i] = -1;
    }
}

void percolate() {
    int k, count;
    for (k = 0; k < N * N; k++) {
        if (status[k] == -1 && rand() % 100 < P) {
            status[k] = 1;
            num_open++;
        }
    }
    if (num_open == 0) {
        return;
    }
    for (k = 0; k < N * N; k++) {
        if (status[k] == -1) {
            count = 0;
            if (k / N > 0 && grid[k / N - 1][k % N] == 1) {
                count++;
            }
            if (k / N < N - 1 && grid[k / N + 1][k % N] == 1) {
                count++;
            }
            if (k % N > 0 && grid[k / N][k % N - 1] == 1) {
                count++;
            }
            if (k % N < N - 1 && grid[k / N][k % N + 1] == 1) {
                count++;
            }
            if (count == 1) {
                grid[k / N][k % N] = 1;
                status[k] = 1;
                num_open++;
            }
        }
    }
}

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init();
    for (int t = 0; t < T; t++) {
        percolate();
        print_grid();
    }
    return 0;
}