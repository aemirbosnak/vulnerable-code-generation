//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 //size of the grid
#define D 0.5 //probability of a site being open
#define T 1000 //number of time steps

int **create_grid(int n);
void percolate(int **grid, int n);
int check_neighbors(int **grid, int i, int j);
int main() {
    int **grid = create_grid(N);
    srand(time(NULL));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(rand() % 100 < D) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    percolate(grid, N);
    return 0;
}

int **create_grid(int n) {
    int **grid = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }
    return grid;
}

void percolate(int **grid, int n) {
    int top = 0, bottom = n-1, left = 0, right = n-1;
    while(top < bottom || left < right) {
        if(check_neighbors(grid, top, left)) {
            grid[top][left] = 1;
            top++;
        } else if(check_neighbors(grid, bottom, right)) {
            grid[bottom][right] = 1;
            bottom--;
        } else if(check_neighbors(grid, top, right)) {
            grid[top][right] = 1;
            top++;
        } else if(check_neighbors(grid, bottom, left)) {
            grid[bottom][left] = 1;
            bottom--;
        }
    }
}

int check_neighbors(int **grid, int i, int j) {
    if(i > 0 && grid[i-1][j] == 1) return 1;
    if(i < N-1 && grid[i+1][j] == 1) return 1;
    if(j > 0 && grid[i][j-1] == 1) return 1;
    if(j < N-1 && grid[i][j+1] == 1) return 1;
    return 0;
}