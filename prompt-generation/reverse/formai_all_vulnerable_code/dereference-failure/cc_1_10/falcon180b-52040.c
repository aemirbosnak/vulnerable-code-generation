//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100  // number of sites
#define M 1000 // number of Monte Carlo steps
#define P 0.5  // probability of site being occupied

int **grid;  // the grid of sites
int top, bottom;  // the top and bottom boundaries of the grid
int left, right;  // the left and right boundaries of the grid
int num_sites;  // the number of sites in the grid
int num_open;  // the number of open sites in the grid

void init_grid() {
    srand(time(NULL));  // seed the random number generator with the current time
    grid = (int **) malloc(N * sizeof(int *));  // allocate memory for the grid
    for (int i = 0; i < N; i++) {
        grid[i] = (int *) malloc(N * sizeof(int));  // allocate memory for each row of the grid
    }
    top = 0;
    bottom = N - 1;
    left = 0;
    right = N - 1;
    num_sites = N * N;
    num_open = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                grid[i][j] = 1;  // set the boundary sites to occupied
            } else {
                grid[i][j] = rand() % 2;  // randomly set the interior sites to occupied or open
                if (grid[i][j] == 0) {
                    num_open++;  // count the number of open sites
                }
            }
        }
    }
}

void display_grid() {
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void percolate() {
    int count = 0;
    while (count < M) {
        int i = rand() % N;
        int j = rand() % N;
        if (grid[i][j] == 0) {
            grid[i][j] = 1;
            num_open--;
            count++;
        }
    }
}

int main() {
    init_grid();
    display_grid();
    percolate();
    display_grid();
    printf("Number of open sites: %d\n", num_open);
    return 0;
}