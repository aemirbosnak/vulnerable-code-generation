//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void createGrid(int grid[SIZE][SIZE], int top, int bottom, int left, int right) {
    int i, j;
    for (i = top; i <= bottom; i++) {
        for (j = left; j <= right; j++) {
            grid[i][j] = 0;
        }
    }
}

void printGrid(int grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValid(int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        return 1;
    }
    return 0;
}

int countNeighbors(int grid[SIZE][SIZE], int x, int y) {
    int count = 0;
    if (grid[x - 1][y] == 1) {
        count++;
    }
    if (grid[x + 1][y] == 1) {
        count++;
    }
    if (grid[x][y - 1] == 1) {
        count++;
    }
    if (grid[x][y + 1] == 1) {
        count++;
    }
    if (count == 3) {
        return 1;
    }
    return 0;
}

void percolate(int grid[SIZE][SIZE], int top, int bottom, int left, int right) {
    int i, j;
    for (i = top; i <= bottom; i++) {
        for (j = left; j <= right; j++) {
            if (grid[i][j] == 1) {
                if (countNeighbors(grid, i, j) == 0) {
                    grid[i][j] = 0;
                }
            } else if (grid[i][j] == 0 && countNeighbors(grid, i, j) == 3) {
                grid[i][j] = 1;
            }
        }
    }
}

int main() {
    int top, bottom, left, right, i, j;
    printf("Enter the top boundary: ");
    scanf("%d", &top);
    printf("Enter the bottom boundary: ");
    scanf("%d", &bottom);
    printf("Enter the left boundary: ");
    scanf("%d", &left);
    printf("Enter the right boundary: ");
    scanf("%d", &right);
    int grid[SIZE][SIZE];
    createGrid(grid, top, bottom, left, right);
    int numPercolations = 0;
    while (numPercolations < 100) {
        percolate(grid, top, bottom, left, right);
        numPercolations++;
        printf("Percolation %d:\n", numPercolations);
        printGrid(grid);
        printf("\n");
    }
    return 0;
}