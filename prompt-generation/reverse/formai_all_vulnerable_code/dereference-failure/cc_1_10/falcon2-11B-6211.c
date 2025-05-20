//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define R 0.5

// Function to check if a cell is occupied
int occupied(int x, int y) {
    return rand() % 100 < R;
}

// Function to check if a cell is adjacent to an occupied cell
int adjacent(int x, int y, int n) {
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i!= 0 || j!= 0) {
                int xx = x + i;
                int yy = y + j;
                if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                if (occupied(xx, yy)) return 1;
            }
        }
    }
    return 0;
}

// Function to simulate percolation
void percolation(int n) {
    int i, j, k, l;
    int **grid = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        grid[i] = malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            grid[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (rand() % 100 < R) {
                grid[i][j] = 1;
            }
        }
    }
    for (k = 0; k < n; k++) {
        for (l = 0; l < n; l++) {
            if (grid[k][l] == 1 && adjacent(k, l, n)) {
                grid[k][l] = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    percolation(N);
    return 0;
}