//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 100 //number of nodes

int **create_grid();
void init_grid(int **grid);
void print_grid(int **grid);
int count_neighbors(int **grid, int i, int j);
int check_percolation(int **grid);

int main() {
    int **grid = create_grid();
    init_grid(grid);
    printf("Initial grid:\n");
    print_grid(grid);

    int percolated = 0;
    while (!percolated) {
        percolated = check_percolation(grid);
    }

    printf("Percolation occurred!\n");
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void init_grid(int **grid) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            }
        }
    }
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(int **grid, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if ((k!= 0 || l!= 0) && (i + k >= 0 && i + k < N && j + l >= 0 && j + l < N)) {
                count += grid[i + k][j + l];
            }
        }
    }
    return count;
}

int check_percolation(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0 && count_neighbors(grid, i, j) == 3) {
                grid[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (grid[i][0] == 0) {
            return 0;
        }
    }

    return 1;
}