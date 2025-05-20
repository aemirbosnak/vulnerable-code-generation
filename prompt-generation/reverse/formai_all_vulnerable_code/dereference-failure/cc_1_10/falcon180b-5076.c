//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the constants
#define N 100
#define D 0.5
#define L 1.0
#define U 1.5

// Define the global variables
int **grid;
int num_filled;

// Function prototypes
void initialize_grid();
int is_valid(int x, int y);
void add_drop(int x, int y);
void percolate();
void print_grid();

int main() {
    srand(time(NULL));
    initialize_grid();
    percolate();
    print_grid();
    return 0;
}

void initialize_grid() {
    grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    num_filled = 0;
}

int is_valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void add_drop(int x, int y) {
    if (is_valid(x, y)) {
        grid[x][y] = 1;
        num_filled++;
    }
}

void percolate() {
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_valid(i, j) && grid[i][j] == 1) {
                add_drop(i + 1, j);
                add_drop(i - 1, j);
                add_drop(i, j + 1);
                add_drop(i, j - 1);
            }
        }
    }
}

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}