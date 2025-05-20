//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a cluster of random bits
void create_cluster(int **grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to grow the largest cluster
void grow_cluster(int **grid, int width, int height) {
    int max_size = 0;
    int *row_sizes = (int *)malloc(width * sizeof(int));
    for (int i = 0; i < width; i++) {
        row_sizes[i] = 0;
        for (int j = 0; j < height; j++) {
            if (grid[i][j] == 1) {
                row_sizes[i]++;
            }
        }
    }
    for (int i = 0; i < width; i++) {
        for (int j = i + 1; j < width; j++) {
            if (row_sizes[i] > row_sizes[j]) {
                int temp = grid[i][j];
                grid[i][j] = grid[j][i];
                grid[j][i] = temp;
                row_sizes[i] += row_sizes[j];
                row_sizes[j] = 0;
            }
        }
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = max_size;
            }
        }
    }
}

// Function to print the current cluster
void print_cluster(int **grid, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to percolate the grid
void percolate(int **grid, int width, int height) {
    srand(time(NULL));
    create_cluster(grid, width, height);
    int max_size = 0;
    while (max_size!= width * height) {
        grow_cluster(grid, width, height);
        max_size = 0;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (grid[i][j] == width * height) {
                    max_size++;
                }
            }
        }
    }
    print_cluster(grid, width, height);
}

int main() {
    int width = 20;
    int height = 20;
    int **grid = (int **)malloc(width * sizeof(int *));
    for (int i = 0; i < width; i++) {
        grid[i] = (int *)malloc(height * sizeof(int));
    }
    percolate(grid, width, height);
    for (int i = 0; i < width; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}