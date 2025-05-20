//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height;
    printf("Enter the width and height of the grid: ");
    scanf("%d %d", &width, &height);

    int** grid = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        grid[i] = (int*)malloc(width * sizeof(int));
    }

    int numOpen = 0;
    srand(time(NULL));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = rand() % 100;
            if (r < 50) {
                grid[i][j] = 1;
                numOpen++;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    printf("Initial Grid:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("After 1 Iteration:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 1) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    int numOpen2 = numOpen;

    for (int i = 0; i < 1000; i++) {
        printf("After %d Iterations:\n", i + 1);
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (grid[j][k] == 1) {
                    int numAdjacent = 0;
                    if (j > 0 && grid[j - 1][k] == 1) {
                        numAdjacent++;
                    }
                    if (j < height - 1 && grid[j + 1][k] == 1) {
                        numAdjacent++;
                    }
                    if (k > 0 && grid[j][k - 1] == 1) {
                        numAdjacent++;
                    }
                    if (k < width - 1 && grid[j][k + 1] == 1) {
                        numAdjacent++;
                    }
                    if (numAdjacent == 2 || numAdjacent == 3) {
                        grid[j][k] = 1;
                        numOpen2++;
                    }
                }
            }
        }

        if (numOpen == numOpen2) {
            break;
        }
        numOpen = numOpen2;
    }

    printf("Final Grid:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}