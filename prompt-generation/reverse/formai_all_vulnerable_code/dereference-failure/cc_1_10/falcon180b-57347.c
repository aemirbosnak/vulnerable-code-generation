//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define P 0.5
#define N 1000

int **create_grid(int size);
void percolate(int **grid, int size);
int count_percolations(int **grid, int size);

int main() {
    int **grid = create_grid(SIZE);
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        percolate(grid, SIZE);
        printf("Iteration %d:\n", i + 1);
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (grid[j][k] == 1) {
                    printf("* ");
                } else {
                    printf("- ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Total Percolations: %d\n", count_percolations(grid, SIZE));
    return 0;
}

int **create_grid(int size) {
    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void percolate(int **grid, int size) {
    int x, y;
    for (int i = 0; i < size; i++) {
        x = rand() % size;
        y = rand() % size;
        if (grid[x][y] == 0 && (grid[x - 1][y] == 1 || grid[x + 1][y] == 1 || grid[x][y - 1] == 1 || grid[x][y + 1] == 1)) {
            grid[x][y] = 1;
        }
    }
}

int count_percolations(int **grid, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}