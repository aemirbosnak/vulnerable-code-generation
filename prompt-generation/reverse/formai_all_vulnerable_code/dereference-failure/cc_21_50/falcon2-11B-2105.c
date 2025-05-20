//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int width = 50;
    int height = 50;
    int** grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        grid[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    int** visited = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        visited[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            visited[i][j] = 0;
        }
    }

    int** adjacent = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        adjacent[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            adjacent[i][j] = 0;
        }
    }

    int** percolation = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        percolation[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            percolation[i][j] = 0;
        }
    }

    int count = 0;
    int i = 0;
    int j = 0;

    while (i < height && j < width) {
        if (grid[i][j] == 1) {
            visited[i][j] = 1;
            adjacent[i][j] = 1;
            percolation[i][j] = 1;
            count++;
            j++;
        } else {
            if (j > 0 && visited[i][j - 1] == 1 && adjacent[i][j - 1] == 1) {
                j--;
            } else if (j < width - 1 && visited[i][j + 1] == 1 && adjacent[i][j + 1] == 1) {
                j++;
            } else if (i > 0 && visited[i - 1][j] == 1 && adjacent[i - 1][j] == 1) {
                i--;
            } else if (i < height - 1 && visited[i + 1][j] == 1 && adjacent[i + 1][j] == 1) {
                i++;
            } else {
                j = 0;
                i = 0;
            }
        }
    }

    printf("Percolation count: %d\n", count);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", percolation[i][j]);
        }
        printf("\n");
    }

    free(grid);
    free(visited);
    free(adjacent);
    free(percolation);

    return 0;
}