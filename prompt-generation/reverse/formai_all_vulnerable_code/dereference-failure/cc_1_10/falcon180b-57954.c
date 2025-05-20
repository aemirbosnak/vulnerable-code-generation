//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define P 0.5
#define T 200

int **create_grid();
void percolate(int **grid);
void print_grid(int **grid);
int count_neighbors(int **grid, int i, int j);

int main() {
    int **grid;
    int i, j, k;
    srand(time(NULL));

    grid = create_grid();

    for (k = 0; k < T; k++) {
        percolate(grid);
        print_grid(grid);
    }

    return 0;
}

int **create_grid() {
    int **grid;
    int i, j;

    grid = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    return grid;
}

void percolate(int **grid) {
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                for (k = 0; k < 4; k++) {
                    if (i + 1 < N && grid[i + 1][j] == 0) {
                        grid[i + 1][j] = 1;
                    } else if (i - 1 >= 0 && grid[i - 1][j] == 0) {
                        grid[i - 1][j] = 1;
                    } else if (j + 1 < N && grid[i][j + 1] == 0) {
                        grid[i][j + 1] = 1;
                    } else if (j - 1 >= 0 && grid[i][j - 1] == 0) {
                        grid[i][j - 1] = 1;
                    }
                }
            }
        }
    }
}

void print_grid(int **grid) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int **grid, int i, int j) {
    int count = 0;

    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
        count++;
    }
    if (i + 1 < N && grid[i + 1][j] == 1) {
        count++;
    }
    if (j - 1 >= 0 && grid[i][j - 1] == 1) {
        count++;
    }
    if (j + 1 < N && grid[i][j + 1] == 1) {
        count++;
    }

    return count;
}