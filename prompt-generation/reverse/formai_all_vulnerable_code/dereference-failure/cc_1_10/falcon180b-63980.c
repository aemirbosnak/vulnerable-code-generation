//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of nodes
#define P 0.5 // probability of connection
#define D 0.1 // density of nodes
#define T 100 // number of simulations
#define S 0 // starting node

int **create_grid();
void print_grid(int **grid);
int count_neighbors(int **grid, int x, int y);
void percolate(int **grid);

int main() {
    srand(time(NULL));
    int **grid = create_grid();
    for (int i = 0; i < T; i++) {
        percolate(grid);
        printf("Simulation %d:\n", i+1);
        print_grid(grid);
        printf("\n");
    }
    return 0;
}

int **create_grid() {
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            grid[i][j] = (rand() % 2);
        }
    }
    grid[S][S] = 1;
    return grid;
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int **grid, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && grid[x+i][y+j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void percolate(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1 && count_neighbors(grid, i, j) < 2) {
                grid[i][j] = 0;
            } else if (grid[i][j] == 0 && count_neighbors(grid, i, j) >= 2) {
                grid[i][j] = 1;
            }
        }
    }
}