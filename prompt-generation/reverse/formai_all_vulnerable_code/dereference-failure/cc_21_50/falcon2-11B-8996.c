//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int width = 100;
    int height = 100;
    Point** grid = malloc(height * sizeof(Point*));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(Point));
    }

    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j].x = rand() % width;
            grid[i][j].y = rand() % height;
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].x >= width / 2 && grid[i][j].y >= height / 2) {
                int neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (grid[i + k][j + l].x >= 0 && grid[i + k][j + l].x < width && grid[i + k][j + l].y >= 0 && grid[i + k][j + l].y < height && grid[i + k][j + l].x == grid[i][j].x && grid[i + k][j + l].y == grid[i][j].y) {
                            neighbors++;
                        }
                    }
                }
                if (neighbors == 2 || neighbors == 3) {
                    grid[i][j].x = -1;
                    grid[i][j].y = -1;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].x == -1 && grid[i][j].y == -1) {
                count++;
            }
        }
    }

    printf("Number of percolated clusters: %d\n", count);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].x == -1 && grid[i][j].y == -1) {
                printf(".");
            } else {
                printf("%d %d\n", grid[i][j].x, grid[i][j].y);
            }
        }
        printf("\n");
    }

    free(grid);

    return 0;
}