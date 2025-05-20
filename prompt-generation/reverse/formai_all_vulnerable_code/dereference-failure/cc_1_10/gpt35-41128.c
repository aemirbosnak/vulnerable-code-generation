//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to create a percolation simulation grid
int **createGrid(int size) {
    int i, j;
    int **grid = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

// function to print the percolation simulation grid
void printGrid(int **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the percolation simulation percolates
bool doesPercolate(int **grid, int size) {
    int i, j;
    bool flag = false;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j] == 2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    if (flag) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (grid[i][j] == 2) {
                    if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                        return true;
                    } else if (i > 0 && grid[i - 1][j] == 1) {
                        return true;
                    } else if (j > 0 && grid[i][j - 1] == 1) {
                        return true;
                    } else if (i < size - 1 && grid[i + 1][j] == 1) {
                        return true;
                    } else if (j < size - 1 && grid[i][j + 1] == 1) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// function to create a random percolation simulation
void createRandom(int **grid, int size) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((rand() % 100 + 1) <= 60) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
}

// function to simulate percolation
void percolate(int **grid, int size) {
    int i, j, k, l;
    bool flag = true;
    while (flag) {
        flag = false;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (grid[i][j] == 1) {
                    if (i == 0 || j == 0 || i == size - 1 || j == size - 1) {
                        grid[i][j] = 2;
                        flag = true;
                    } else if (i > 0 && grid[i - 1][j] == 2) {
                        grid[i][j] = 2;
                        flag = true;
                    } else if (j > 0 && grid[i][j - 1] == 2) {
                        grid[i][j] = 2;
                        flag = true;
                    } else if (i < size - 1 && grid[i + 1][j] == 2) {
                        grid[i][j] = 2;
                        flag = true;
                    } else if (j < size - 1 && grid[i][j + 1] == 2) {
                        grid[i][j] = 2;
                        flag = true;
                    }
                }
            }
        }
    }
}

// main function
int main() {
    int size = 10;
    int **grid = createGrid(size);
    createRandom(grid, size);
    printf("Before percolating:\n");
    printGrid(grid, size);
    percolate(grid, size);
    printf("\nAfter percolating:\n");
    printGrid(grid, size);
    printf("\nPercolation simulation %spercolates.", doesPercolate(grid, size) ? "" : "does not ");
    return 0;
}