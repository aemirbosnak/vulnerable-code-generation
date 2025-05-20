//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 100
#define P 0.5
#define T 1.0

int n, m, p;
int **grid;
int top, bottom;
int count;

void init() {
    srand(time(NULL));
    count = 0;
    n = N;
    m = M;
    p = P;
    grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }
    top = 0;
    bottom = n - 1;
}

void percolate() {
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                x = rand() % 3 - 1 + i;
                y = rand() % 3 - 1 + j;
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0) {
                    grid[x][y] = 1;
                }
            }
        }
    }
}

void display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    init();
    int i;
    for (i = 0; i < M; i++) {
        percolate();
        display();
    }
    return 0;
}